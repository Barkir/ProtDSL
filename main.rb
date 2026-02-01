#!/usr/bin/ruby
require_relative "Generic/base"
require_relative "Generic/builder"
require_relative "Target/RISC-V/32I.rb"

require_relative "Generic/Encoder/encoder_generator.rb"
require_relative "Generic/Decoder/decoder_generator.rb"

SimInfra.serialize

### AT THIS POINT IR.YAML is created

# SimInfra.create_encoder

# WE CAN USE OUR OWN ENCODER BUT THERE IS NO NEED
# SINCE WE GOT RISC-V TOOLCHAIN...

SimInfra.create_decoder
