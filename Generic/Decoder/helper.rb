require_relative "../base.rb"
require 'ostruct'

module SimInfra

    def self.create_mask(from, to) # from < to
        "0b" + "0" * (32 - (to - from + 1)) + "1" * (to - from + 1)
    end

    def self.getOperandsAsHashTable(instr)
        puts "-------------------"
        puts instr
        operands = instr.fields.select{|f| f[:value] == :reg}
        .each_with_object({}){|f, h| h[f[:name].to_s] = OpenStruct.new(f.to_h)}
        puts "################"
        puts operands
        puts "################"
        return operands
    end

#!SECTION##################################################################

    def self.get_instruction_string(map, bitBasis)
      instructionString = []
      index = 0
      bitBasis.each do |value|
          instructionString[index] = map[value[:nbit]]
          instructionString[index][:nbit] = value[:nbit]
          index += 1
      end
      # puts instructionString
      # puts "\n"
      # turn it into string

      return instructionString.map{|item| item[:value].to_s}.join.rjust(bitBasis.length, '0')
  end

#!SECTION##################################################################

    # score is evaluated using this formula: score = N_total - N_x - |N_0 - N_1|
    # N_total - number of instructions where we choose this bit (instruction_map.length)

    # N_x - number of instructions where this bit is marked as     'don't care'
    # N_0 - number of instructions where this bit is equal to       0
    # N_1 - number of instructions where this bit is equal to       1

    def self.getBitScore(instruction_map, nbit)
      n_total = instruction_map.length
      if n_total == 2
          return instruction_map.values[0][nbit][:value] ^ instruction_map.values[1][nbit][:value]
      end
      n_0 = 0
      n_1 = 0
      n_x = 0
      instruction_map.each do |name, value|
          if value[nbit][:type] == 0
              n_x += 1
          elsif value[nbit][:value] == 1
              n_1 += 1
          elsif value[nbit][:value] == 0
              n_0 += 1
          end
      end
      printf("total: %d, don't care: %d, 1: %d, 0: %d\n", n_total, n_x, n_1, n_0)
      return n_total - n_x - (n_0 - n_1).abs
  end

    ## some shitty offset formula i need to explain
    ## so, we found out a bit at 12th position on the 1st iteration of our cycle
    ## if we have, let's say a basis length of 4 bits, then we have 4 iterations (n goes from 0 to 3)
    ## so, we need to place this bit at the 3rd position, then the next bit in basis at the 2nd, at the 1st at the 0th...
    ## to do that we count offset
    ## it is equal to value[:nbit] - (STANDARD_BIT_BASIS_SIZE - 1 - n) + 1
    ## STANDARD_BIT_BASIS_SIZE - 1 - n is actually the bit we want to place. e.g we want to place it to the 2nd bit, it is the 2nd iteration
    ## this will eqaul 4 - 1 - 1 = 2.


  def self.generate_get_bits_function(executers, bitBasis, depth)
        # executers.write("int getBitsAtLevel#{depth}(uint32_t command) {\n")
        var_name = "bits_#{depth}_#{bitBasis.map{|n| n[:nbit]}.join()}"
        executers.write("\t" * depth + "\tuint32_t #{var_name} = 0;\n")
        executers.write("\t" * depth + "\tuint32_t bitMask = 0;\n")
        # i need to get the bits and collect them into single number
        # 1. get the value of n'th bit. this can be done by masking it
        # 2. set this bit as the 0, 1, 2 bit in the 'bits' value

        bitBasis.each_with_index do |value, n|
            printf("basis: %d <<< index: %d\n", value[:nbit], n)
            mask = ("1" + "0" * (value[:nbit])).rjust(32, '0')
            print("mask = " + mask + "\n")

            # offset = value[:nbit] - n >= 0 ? (value[:nbit] - n) : (n - value[:nbit])
            offset = value[:nbit] - (bitBasis.length - 1 - n)
            if offset >= 0
                executers.write("\t" * (depth + 1) + "bitMask = (command & 0b#{mask}) >> #{offset};\n")
            else
                executers.write("\t" * (depth + 1) + "bitMask = (command & 0b#{mask}) << #{offset.abs};\n")
            end

            #LOGS######
            # executers.write("\t" * depth + "std::cout << std::bitset<32>(command) << \"\t&\"<< std::endl;\n")
            # executers.write("\t" * depth + "std::cout << std::bitset<32>(0b#{mask}) << std::endl;\n")
            # executers.write("\t" * depth + "std::cout << \"\t\t=\" << std::endl;\n")
            # executers.write("\t" * depth + "std::cout << std::bitset<32>(bitMask) << std::endl;\n")

            # executers.write("\t" * depth + "std::cout << std::bitset<32>(#{var_name}) << std::endl;\n")
            # executers.write("\t" * depth + "std::cout << \"\t\t+\" << std::endl;\n")
            # executers.write("\t" * depth + "std::cout << std::bitset<32>(bitMask) << std::endl;\n")
            # executers.write("\t" * depth + "std::cout << \"\t\t=\" << std::endl;\n")
            #LOGS######

            executers.write("\t" * depth + "\t#{var_name} += bitMask;\n")

            #LOGS######
            # executers.write("\t" * depth + "std::cout << #{var_name} << std::endl;")
            # executers.write("\t" * depth + "std::cout << \"bit#{value[:nbit]}, offset#{offset} : \" << \tstd::bitset<32>(#{var_name})" + " << std::endl;\n")
            #LOGS######

        end

        # executers.write("\t" * depth + "\t#{var_name} = flipMask(#{var_name}, #{STANDARD_BIT_BASIS_SIZE});\n")

        #LOGS######
        # executers.write("\t" * depth + "std::cout << \"flipped: \" << std::bitset<32>(#{var_name}) << std::endl;\n")
        #LOGS######

        # executers.write("\treturn bits;\n")
        # executers.write("}\n")
    return var_name
    end

    def self.set_bits(number, value, to, from)
        width = to - from + 1
        mask = ((1 << width) - 1) << from
        (number & ~mask) | ((value & ((1 << width) - 1)) << from)
    end

def self.buildValue(fields)
  bitValue = Array.new(INSTRUCTION_SIZE_IN_BITS) { { type: 0, value: 0 } }

  fields.each do |field|
    from  = field[:from]
    to    = field[:to]
    value = field[:value]

    width = to - from + 1

    (0...width).each do |bit|
      i = from + bit
      bitValue[i][:value] = (value >> bit) & 1
      bitValue[i][:type]  = 1
    end
  end

  printf("RETVAL = %s\n", bitValue.map { |n| n[:value] }.join(""))
  bitValue
end



#!SECTION##################################################################

end
