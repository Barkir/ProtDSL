require_relative "helper.rb"

module SimInfra
    def self.dump_tree(tree, filename = "dot/tree.dot")
        File.open(filename, "w") do |f|
            f.write "digraph {\n"
            f.write "  node [shape=box];\n"
            dump_hash_node(f, tree, "root")
            f.write "}\n"
        end

        system("dot -Tpng #{filename} -o #{filename.sub('.dot', '.png')}")
    end

    def self.dump_hash_node(file, value, node_id)
        if value.is_a?(Hash)
          keys_label = value.keys.map do |k|
            if k.is_a?(Array) && k.first.is_a?(Hash) && k.first.key?(:value)
              "⟨#{k.first[:value]}⟩"
            else
              k.inspect
            end
          end.join("\\n")

        file.write "  #{node_id} [label=\"#{node_id}\\nKeys:\\n#{keys_label}\"];\n"

        value.each_with_index do |(key, subvalue), idx|
            child_id = "#{node_id}_key#{idx}"

            if key.is_a?(Array) && key.first.is_a?(Hash) && key.first.key?(:value)
              edge_label = "⟨#{key.first[:value]}⟩"
            else
              edge_label = key.inspect.gsub(/"/, '\\"')
            end

            file.write "  #{node_id} -> #{child_id} [label=\"#{edge_label}\"];\n"
            dump_hash_preorder(file, subvalue, child_id)
        end
        else
        escaped_value = value.inspect.gsub(/"/, '\\"').gsub(/\n/, '\\n')
        file.write "  #{node_id} [label=\"#{node_id}\\n#{escaped_value}\", shape=ellipse];\n"
        end
    end

    def self.dump_hash_preorder(file, value, node_id)
    if value.is_a?(Hash)
        value.each_with_index do |(k, v), idx|
            child_id = "#{node_id}_#{idx}"
            if v.is_a?(Hash)
                key_label = if k.is_a?(Array) && k.first.is_a?(Hash) && k.first.key?(:value)
                        "⟨#{k.first[:value]}⟩"
                      else
                        k.inspect
                      end
                file.write "  #{child_id} [label=\"#{key_label}\"];\n"
                file.write "  #{node_id} -> #{child_id};\n"
                dump_hash_preorder(file, v, child_id)
            else
                escaped_k = k.inspect.gsub(/"/, '\\"')
                escaped_v = v.inspect.gsub(/"/, '\\"')
                file.write "  #{child_id} [label=\"#{escaped_k} = #{escaped_v}\", shape=ellipse];\n"
                file.write "  #{node_id} -> #{child_id};\n"
            end
        end
    else
        escaped_value = value.inspect.gsub(/"/, '\\"').gsub(/\n/, '\\n')
        file.write "  #{node_id} [label=\"#{escaped_value}\", shape=ellipse];\n"
    end
    end
end
