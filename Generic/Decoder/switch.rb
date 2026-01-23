require_relative "helper.rb"

module SimInfra
    def self.generate_switch(executer, subtree, level)
            key = subtree.keys[0]
            name = generate_get_bits_function(executer, key[1], key[2] + 1)
            # executer.write("\t" * level + "std::cout << \"#{name} = \" << #{name} << std::endl;" + "\n")
            # executer.write("\t" * level + "std::cout << std::bitset<32>(#{name}) << std::endl;" + "\n")
            executer.write("\t" * level + "switch(#{name}) {\n")
            for key in subtree.keys
                executer.write("\t" * level + "case #{key[0]}:\n", "\t" * level, "{\n")
                if subtree[key].is_a?(Hash)
                    generate_switch(executer, subtree[key], level + 1)
                else
                    executer.write("\t" * (level + 1) + "decode#{subtree[key].to_s.tr('[', '').tr(']', '').tr(':', '')}(spu, command);\n")
                    executer.write("\t" * (level + 1) + "execute#{subtree[key].to_s.tr('[', '').tr(']', '').tr(':', '')}(spu, command);\n")
                end
                    executer.write("\t" * (level + 1) + "break;\n" + "\t" * level + "}\n")
            end
            executer.write("\t" * level + "default: break;\n")
            executer.write("\t" * level + "}\n")
    end

    def self.create_big_switch(file)
        # decoder.write(INIT_HEADER_CODE)
        file.write("void inline bigSwitch(SPU& spu, uint32_t command){\n")
        generate_switch(file, @tree, 2)
        file.write("}\n")
    end
end

