#!/usr/bin/ruby
require_relative "Generic/base"
require_relative "Generic/builder"
require_relative "Target/RISC-V/32I.rb"

require_relative "Generic/Encoder/encoder_generator.rb"
require_relative "Generic/Decoder/decoder_generator.rb"

SimInfra.serialize
SimInfra.create_encoder
SimInfra.create_decoder
