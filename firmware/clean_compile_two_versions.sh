#!/usr/bin/env bash

set -e

echo "Compiler gcc version"
arm-none-eabi-gcc -v

rm -rf deliver
mkdir deliver

#bash clean.sh
#echo "TIMESTAMP $(date "+%D %T.%2N")"

#EXTRA_PARAMS="-DDUMMY -DFIRMWARE_ID=\\\"default_no_assert\\\" -DEFI_ENABLE_ASSERTS=FALSE -DCH_DBG_ENABLE_ASSERTS=FALSE -DCH_DBG_ENABLE_STACK_CHECK=FALSE -DCH_DBG_FILL_THREADS=FALSE -DCH_DBG_THREADS_PROFILING=FALSE"
#make -j$(nproc) DEBUG_LEVEL_OPT='-O2' $@
#EXTRA_PARAMS=""

# mv build/gerefi.elf deliver/gerefi_no_asserts.elf
#mv build/gerefi.bin deliver/gerefi_no_asserts.bin
# this file is needed for DFU generation
#mv build/gerefi.hex deliver/gerefi_no_asserts.hex
#echo "Release compilation results 1/2"
#echo "TIMESTAMP $(date "+%D %T.%2N")"
#ls -l build
#[ -e deliver/gerefi_no_asserts.hex ] || { echo "FAILED to compile NO ASSERTS version"; exit 1; }

bash clean.sh
echo "TIMESTAMP $(date "+%D %T.%2N")"
EXTRA_PARAMS="-DDUMMY -DFIRMWARE_ID=\\\"default\\\""
make -j$(nproc) $@
EXTRA_PARAMS=""

mv build/gerefi.elf deliver/gerefi.elf
# this file is needed for DFU generation
mv build/gerefi.hex deliver/gerefi.hex
# Keeping file in place since hw_test.bat would take it from current location
cp build/gerefi.bin deliver/gerefi.bin
echo Debug compilation results 2/2
echo "TIMESTAMP $(date "+%D %T.%2N")"
ls -l build
[ -e deliver/gerefi.hex ] || { echo "FAILED to compile DEFAULT with DEBUG"; exit 1; }

echo "clean_compile_two_versions: Looks good!"
