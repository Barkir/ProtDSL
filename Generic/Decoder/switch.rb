require_relative "helper.rb"
require_relative "../base.rb"

module SimInfra
    def self.generate_switch(executer, subtree, level, mode)
            key = subtree.keys[0]
            name = generate_get_bits_function(executer, key[1], key[2] + 1)

            executer.write("\t" * level + "switch(#{name}) {\n")
            for key in subtree.keys
                executer.write("\t" * level + "case #{key[0]}:\n", "\t" * level, "{\n")
                if subtree[key].is_a?(Hash)
                    generate_switch(executer, subtree[key], level + 1, mode)
                else
                    if mode == :decode
                        executer.write("\t" * (level + 1) + "decode#{subtree[key].to_s.tr('[', '').tr(']', '').tr(':', '')}(spu, command);\n")
                    elsif mode == :encode
                        executer.write("\t" * (level + 1) + "execute#{subtree[key].to_s.tr('[', '').tr(']', '').tr(':', '')}(spu, command);\n")
                    end
                end
                    executer.write("\t" * (level + 1) + "break;\n" + "\t" * level + "}\n")
            end
            executer.write("\t" * level + "default: break;\n")
            executer.write("\t" * level + "}\n")
    end

    def self.create_big_switch(decoders, executers)
        decoders.write("void inline bigSwitchDecode(SPU& spu, uint32_t command){\n")
        generate_switch(decoders, @tree, 2, :decode)
        decoders.write("}\n")

        executers.write("void inline bigSwitchEncode(SPU& spu, uint32_t command){\n")
        generate_switch(executers, @tree, 2, :encode)
        executers.write("}\n")
    end
end
