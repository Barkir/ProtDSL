#!/usr/bin/env python3
import subprocess
import re
import sys
import argparse
import tempfile
import os
from collections import defaultdict
from typing import Dict, List, Tuple, Optional

class RISCVDecoderTester:
    def __init__(self, gcc_path: str, objdump_path: str, decoder_cmd: str):
        self.gcc_path = gcc_path
        self.objdump_path = objdump_path
        self.decoder_cmd = decoder_cmd
        self.temp_dir = tempfile.mkdtemp()

    def cleanup(self):
        """Очистка временных файлов"""
        import shutil
        shutil.rmtree(self.temp_dir, ignore_errors=True)

    def compile_test(self, c_code: str) -> str:
        """Компиляция C-кода в ELF"""
        c_file = os.path.join(self.temp_dir, "test.c")
        elf_file = os.path.join(self.temp_dir, "test.elf")

        with open(c_file, 'w') as f:
            f.write(c_code)

        cmd = [
            self.gcc_path,
            "-march=rv32im",
            "-mabi=ilp32",
            "-O0",
            "-nostdlib",
            "-nostartfiles",
            c_file,
            "-o", elf_file
        ]

        try:
            subprocess.run(cmd, check=True, capture_output=True, text=True)
        except subprocess.CalledProcessError as e:
            print(f"Ошибка компиляции:\n{e.stderr}")
            sys.exit(1)

        return elf_file

    def get_objdump_instructions(self, elf_file: str) -> List[Tuple[int, str, str]]:
        """
        Получение инструкций из objdump
        Возвращает: [(address, opcode_hex, mnemonic), ...]
        """
        cmd = [self.objdump_path, "-d", "-M", "no-aliases", elf_file]
        result = subprocess.run(cmd, capture_output=True, text=True, check=True)

        instructions = []
        in_main = False
        main_pattern = re.compile(r'^[0-9a-f]+\s+<main>:')
        instr_pattern = re.compile(r'^\s*([0-9a-f]+):\s+([0-9a-f]{8})\s+(\S+)')

        for line in result.stdout.split('\n'):
            if main_pattern.match(line):
                in_main = True
                continue

            if in_main and re.match(r'^[0-9a-f]+\s+<', line) and not re.match(r'^\s*([0-9a-f]+):', line):
                break

            if in_main:
                match = instr_pattern.match(line)
                if match:
                    addr = len(instructions) * 4
                    opcode_hex = match.group(2)
                    mnemonic = match.group(3).split()[0]  # Берем только имя инструкции
                    instructions.append((addr, opcode_hex, mnemonic))

        return instructions

    def run_decoder(self, elf_file: str) -> Dict[int, str]:
        """
        Запуск пользовательского декодера
        Возвращает: {address: mnemonic, ...}
        """
        cmd = self.decoder_cmd.format(elf=elf_file)
        cmd_parts = cmd.split()
        cmd_parts.append(elf_file)


        try:
            result = subprocess.run(cmd_parts, capture_output=True, text=True, check=True)
        except subprocess.CalledProcessError as e:
            sys.exit(1)

        decoder_output = {}
        pattern = re.compile(r'(?:0x)?([0-9a-f]+)[:|\s]+(\S+)')

        for line in result.stdout.split('\n'):
            match = pattern.match(line.strip())
            if match:
                addr = int(match.group(1), 16)
                mnemonic = match.group(2).strip()
                has_number = bool(re.search(r'\d', mnemonic))
                if not has_number:
                    decoder_output[addr] = mnemonic
        return decoder_output

    def compare_instructions(self, objdump_instrs: List[Tuple[int, str, str]],
                           decoder_results: Dict[int, str]) -> Dict:
        """Сравнение инструкций и формирование статистики"""

        stats = {
            'total': 0,
            'matched': 0,
            'mismatched': 0,
            'by_instruction': defaultdict(lambda: {'total': 0, 'matched': 0, 'mismatched': 0}),
            'errors': []
        }

        for addr, opcode_hex, objdump_mnem in objdump_instrs:
            stats['total'] += 1
            decoder_mnem = decoder_results.get(addr, "MISSING")

            objdump_norm = objdump_mnem.lower()
            decoder_norm = decoder_mnem.lower()

            instr_stat = stats['by_instruction'][objdump_norm]
            instr_stat['total'] += 1

            if objdump_norm == decoder_norm:
                stats['matched'] += 1
                instr_stat['matched'] += 1
            else:
                stats['mismatched'] += 1
                instr_stat['mismatched'] += 1
                stats['errors'].append({
                    'addr': addr,
                    'opcode': opcode_hex,
                    'expected': objdump_mnem,
                    'got': decoder_mnem
                })

        return stats

    def print_report(self, stats: Dict):
        """Вывод отчета"""
        print("\n" + "="*60)
        print("ОТЧЕТ О ТЕСТИРОВАНИИ ДЕКОДЕРА RISC-V")
        print("="*60)

        print(f"\nОбщая статистика:")
        print(f"  Всего инструкций проверено: {stats['total']}")
        print(f"  Совпало: {stats['matched']} ({stats['matched']/stats['total']*100:.1f}%)")
        print(f"  Несовпадений: {stats['mismatched']} ({stats['mismatched']/stats['total']*100:.1f}%)")

        print(f"\nСтатистика по типам инструкций:")
        print(f"{'Инструкция':<15} {'Всего':<8} {'OK':<8} {'FAIL':<8} {'Статус'}")
        print("-" * 55)

        # Сортируем по количеству инструкций
        sorted_instrs = sorted(stats['by_instruction'].items(),
                              key=lambda x: x[1]['total'], reverse=True)

        for instr_name, instr_stats in sorted_instrs:
            total = instr_stats['total']
            matched = instr_stats['matched']
            mismatched = instr_stats['mismatched']
            status = "✓ OK" if mismatched == 0 else "✗ FAIL"

            print(f"{instr_name:<15} {total:<8} {matched:<8} {mismatched:<8} {status}")

        if stats['errors']:
            print(f"\nДетали несовпадений (первые 10):")
            print(f"{'Адрес':<10} {'Opcode':<10} {'Ожидалось':<15} {'Получено':<15}")
            print("-" * 55)
            for err in stats['errors'][:10]:
                print(f"0x{err['addr']:08x} {err['opcode']:<10} {err['expected']:<15} {err['got']:<15}")

            if len(stats['errors']) > 10:
                print(f"... и еще {len(stats['errors']) - 10} ошибок")

        print("\n" + "="*60)

        # Итоговый вердикт
        failed_instrs = [name for name, s in stats['by_instruction'].items() if s['mismatched'] > 0]
        if not failed_instrs:
            print("✓ ВСЕ ИНСТРУКЦИИ ДЕКОДИРУЮТСЯ КОРРЕКТНО!")
        else:
            print(f"✗ ЕСТЬ ОШИБКИ в инструкциях: {', '.join(failed_instrs)}")
        print("="*60)

def main():
    parser = argparse.ArgumentParser(description='Тестирование RISC-V декодера')
    parser.add_argument('--gcc', default='riscv32-unknown-elf-gcc',
                       help='Путь к RISC-V gcc (default: riscv32-unknown-elf-gcc)')
    parser.add_argument('--objdump', default='riscv32-unknown-elf-objdump',
                       help='Путь к objdump (default: riscv32-unknown-elf-objdump)')
    parser.add_argument('--decoder', default="../Simulator/build/ricsv_decode",
                       help='Команда для запуска вашего декодера. Используйте {elf} как placeholder для пути к ELF файлу')
    parser.add_argument('--test-file',
                       help='Путь к собственному C-файлу для тестирования (иначе используется встроенный тест)')
    parser.add_argument('--keep-elf', action='store_true',
                       help='Не удалять временный ELF файл после тестирования')

    args = parser.parse_args()

    tester = RISCVDecoderTester(args.gcc, args.objdump, args.decoder)

    try:
        if args.test_file:
            with open(args.test_file, 'r') as f:
                test_code = f.read()

        print("Компиляция тестового кода...")
        elf_file = tester.compile_test(test_code)
        print(f"ELF файл создан: {elf_file}")

        print("Получение инструкций из objdump...")
        objdump_instrs = tester.get_objdump_instructions(elf_file)
        print(f"Найдено {len(objdump_instrs)} инструкций в секции main")

        print("Запуск пользовательского декодера...")
        decoder_results = tester.run_decoder(elf_file)
        print(f"Декодер вернул {len(decoder_results)} инструкций")

        print("Сравнение результатов...")
        stats = tester.compare_instructions(objdump_instrs, decoder_results)
        tester.print_report(stats)

        if args.keep_elf:
            print(f"\nELF файл сохранен: {elf_file}")
            print(f"Для ручной проверки: {args.objdump} -d {elf_file}")
        else:
            tester.cleanup()

        sys.exit(0 if stats['mismatched'] == 0 else 1)

    except Exception as e:
        print(f"Ошибка: {e}")
        tester.cleanup()
        sys.exit(1)

if __name__ == "__main__":
    main()
