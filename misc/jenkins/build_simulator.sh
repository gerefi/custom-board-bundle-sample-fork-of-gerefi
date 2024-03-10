#!/bin/bash

echo "TIMESTAMP $(date "+%D %T.%2N") Building gerefi simulator"
pwd
cd simulator
gcc -v
make -v
mkdir -p out
rm -rf build
rm -rf .dep
bash compile.sh
ls build
cd ..
[ -e simulator/build/gerefi_simulator.exe ] || [ -e simulator/build/gerefi_simulator ] || { echo "SIMULATOR COMPILATION FAILED"; exit 1; }
