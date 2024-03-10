#!/usr/bin/env bash

set -e

rm -f build/gerefi_simulator.exe
make -j$(nproc) -r $@
[ $? -eq 0 ] || { echo "Simulator compilation failed"; exit 1; }
file build/gerefi_simulator
echo "TIMESTAMP $(date "+%D %T.%2N") just compiled gerefi simulator"
