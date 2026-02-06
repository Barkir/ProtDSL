# dump_tree.rb
require_relative "helper.rb"
require "fileutils"
require_relative "../base.rb"

module SimInfra
  DEFAULT_DOT_FILENAME = "dot/tree.dot"
  MAX_LABEL_LEN = 60
  MAX_KEYS_IN_NODE = 6

  def self.sanitize_id(s)
    id_str = s.to_s.gsub(/[^0-9A-Za-z_]/, "_")
    id_str.match?(/^\d/) ? "n_#{id_str}" : id_str
  end

  def self.truncate(str, max = MAX_LABEL_LEN)
    s = str.to_s
    return s if s.length <= max
    s[0, max - 3] + "..."
  end

  def self.escape_label(s)
    s.to_s.gsub("\\", "\\\\").gsub("\"", "\\\"").gsub("\n", "\\n")
  end

  def self.extract_nbits(obj, acc = [])
    case obj
    when Hash
      acc << obj[:nbit] if obj.key?(:nbit)
      obj.each do |k, v|
        extract_nbits(k, acc)
        extract_nbits(v, acc)
      end
    when Array
      obj.each { |e| extract_nbits(e, acc) }
    end
    acc
  end

  def self.parse_key_for_edge(key)
    if key.is_a?(Array) && key.size == 3 && key[0].is_a?(Integer) && key[1].is_a?(Array)
      value = key[0]
      edge_str = value.to_s(2)
      bits = extract_nbits(key).compact.uniq.sort
      return { edge: edge_str, bits: bits }
    end

    if key.is_a?(Array) || key.is_a?(Hash)
        values = []
        extract_values = lambda do |o|
          case o
          when Hash
            values << o[:value] if o.key?(:value)
            o.each { |k, v| extract_values.call(k); extract_values.call(v) }
          when Array
            o.each { |e| extract_values.call(e) }
          end
        end
        extract_values.call(key)

        unless values.empty?
            edge_str = values.map { |v| v.is_a?(Integer) ? v.to_s(2) : v.to_s }.join(",")
            bits = extract_nbits(key).compact.uniq.sort
            return { edge: edge_str, bits: bits }
        end
    end

    edge_str = truncate(key.inspect, 40)
    bits = extract_nbits(key).compact.uniq.sort
    { edge: edge_str, bits: bits }
  end

  def self.format_edge_label(edge_str)
    s = edge_str.to_s
    s = s.gsub(/^0b/, "")
    s = s.gsub(/\s+/, "")
    truncate(s, 24)
  end

  def self.dump_tree(tree, filename = DEFAULT_DOT_FILENAME)
    dir = File.dirname(filename)
    FileUtils.mkdir_p(dir) unless Dir.exist?(dir)

    File.open(filename, "w") do |f|
      f.write <<~DOT
        digraph Decoder {
          rankdir=LR;
          graph [fontname="Helvetica"];
          node [shape=box, style="rounded,filled", fillcolor="#f8fbff", fontname="monospace", fontsize=10];
          edge [fontname="monospace", fontsize=9];
      DOT

      dump_node_bits_only(f, tree, "root")

      f.write "}\n"
    end

    puts "Generating graph visualization..."
    png = filename.sub(/\.dot\z/, ".png")
    system("dot -Tpng #{filename} -o #{png}")
    puts "Graph saved to #{png}"
    png
  end

  def self.dump_node_bits_only(file, value, node_id)
    node_id = sanitize_id(node_id)
    if value.is_a?(Hash)
      child_count = value.size

      all_bits = value.keys.flat_map { |k| extract_nbits(k) }.compact.uniq.sort
      bits_label = all_bits.empty? ? "" : "\\nbits: #{all_bits.join(', ')}"

      keys_preview = value.keys.first(MAX_KEYS_IN_NODE).map do |k|
        info = parse_key_for_edge(k)
        format_edge_label(info[:edge])
      end
      keys_more = value.keys.size > MAX_KEYS_IN_NODE ? " (+#{value.keys.size - MAX_KEYS_IN_NODE} more)" : ""
      label = "#{node_id}\\nchildren=#{child_count}#{bits_label}\\n(keys: #{keys_preview.join(", ")})#{keys_more}"

      file.write "  \"#{node_id}\" [label=\"#{escape_label(label)}\", fillcolor=\"#eef6ff\"];\n"

      sorted_keys = value.keys.sort_by { |k| k.inspect }
      sorted_keys.each do |key|
        sub = value[key]

        info = parse_key_for_edge(key)
        edge_label_for_id = info[:edge]

        child_id = "#{node_id}_#{edge_label_for_id}"

        edge_label_display = format_edge_label(info[:edge])

        file.write "  \"#{node_id}\" -> \"#{sanitize_id(child_id)}\" [label=\"#{escape_label(edge_label_display)}\"];\n"
        dump_node_bits_only(file, sub, child_id)
      end
    else
      leaf_text = case value
                  when Symbol then value.to_s
                  when String then value
                  when Array then value.map(&:to_s).join(", ")
                  else truncate(value.inspect, 40)
                  end
      label = "#{truncate(leaf_text, 40)}"
      file.write "  \"#{node_id}\" [label=\"#{escape_label(label)}\", shape=ellipse, fillcolor=\"#eaffea\"];\n"
    end
  end
end


