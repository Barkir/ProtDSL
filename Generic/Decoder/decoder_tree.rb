require_relative "dump_decoder_tree.rb"
require_relative "helper.rb"
require_relative "../base.rb"

module SimInfra
  def self.build_decoding_tree(executers, tree, instruction_map, depth=0)
    printf(":: building a decoding tree at depth %d | %s \n", depth, instruction_map.keys)
    if instruction_map.size == 1
      return instruction_map.keys
    end

    bitRange = Array.new(32) do
        {score: 0, nbit: 0}
    end

    (0..31).each do |i|
        score = getBitScore(instruction_map, i)
        bitRange[i][:score] = score
        bitRange[i][:nbit] = i
    end
    instruction_map.each do |name, value|
        value_clean = value.map {|n| n[:value].to_s}
        print name, "\t", value_clean.join("").reverse
        print "\n"
    end
    printf(":: got bitRange %s \n", bitRange.to_s)
    bitBasis = bitRange.select{|item| item[:score] != 0}.sort_by{|item| -item[:score]}.first(STANDARD_BIT_BASIS_SIZE)
    printf(":: got bitBasis %s at length %d\n", bitBasis.to_s, depth)
    # generate_get_bits_function(executers, bitBasis, depth)
    # iterating from 0 to 1111 (in case if we choose 4 bits as a basis)
    (0..2**bitBasis.length).each do |i|

      # making a string:  e.g. '0101'
      bitString = i.to_s(2).rjust(bitBasis.length, '0')
      sub_instruction_map = {}

      # iterating over instructions to check if bits are equal
      # to bitString and add them to sub_instruction_map
      # then calling build_decoding_tree recursively
      instruction_map.each do |name, map|
          instructionString = get_instruction_string(map, bitBasis)
          printf("%s <><><> %s, %d\n", instructionString, bitString, instructionString == bitString ? 1 : 0)
          if instructionString == bitString
              sub_instruction_map[name] = map
          end
      end
      print("\n")
      if sub_instruction_map.length > 0
          tree[[bitString.to_i(2), bitBasis, depth]] = Hash.new {|h, k| h[k] = {}}
          tree[[bitString.to_i(2), bitBasis, depth]] = build_decoding_tree(executers, tree[[bitString.to_i(2), bitBasis, depth]], sub_instruction_map, depth+1)
      end
    end
  return tree
  end

  def self.create_decoding_tree(executers)
      @tree = Hash.new {|h, k| h[k] = {}}
      instruction_map = {}
      @@instructions.each do |instr|
          neededFields = instr.fields.select{|f| f.value.is_a?(Numeric)}.map{|f| {:value => f.value, :from => f.to, :to => f.from}}
          fullValues = []
          printf "building value for %s instruction\n", instr.name
          value = buildValue(neededFields)
          instruction_map[instr.name] = value
      end

      # print instruction_map
      # print "\n"
      build_decoding_tree(executers, @tree, instruction_map, 0)
      print @tree.to_s + "\n"
      dump_tree(@tree)
      return @tree
  end

end
