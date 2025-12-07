#!/bin/sh

ruby main.rb
g++ decoder.cpp -O2 -o riscv_decode
