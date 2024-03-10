#!/bin/bash

PROJECT_BOARD=$1
PROJECT_CPU=$2

# fail on error
set -e

SCRIPT_NAME="common_make.sh"
echo "Entering $SCRIPT_NAME with board $1 and CPU $2"

cd ../../..

mkdir -p .dep
# todo: start using env variable for number of threads or for '-r'
make -j$(nproc) -r PROJECT_BOARD=$PROJECT_BOARD PROJECT_CPU=$PROJECT_CPU
[ -e build/gerefi.hex ] || { echo "FAILED to compile by $SCRIPT_NAME with $PROJECT_BOARD $DEBUG_LEVEL_OPT and $EXTRA_PARAMS"; exit 1; }
if [ "$USE_OPENBLT" = "yes" ]; then
  make openblt PROJECT_BOARD=$PROJECT_BOARD PROJECT_CPU=$PROJECT_CPU
  [ -e build-openblt/openblt_$PROJECT_BOARD.hex ] || { echo "FAILED to compile OpenBLT by $SCRIPT_NAME with $PROJECT_BOARD"; exit 1; }
fi

if uname | grep "NT"; then
  HEX2DFU=../misc/encedo_hex2dfu/hex2dfu.exe
else
  HEX2DFU=../misc/encedo_hex2dfu/hex2dfu.bin
fi
chmod u+x $HEX2DFU

mkdir -p deliver
rm -f deliver/*

echo "$SCRIPT_NAME: invoking hex2dfu for incremental gerefi image"
$HEX2DFU -i build/gerefi.hex -C 0x1C -o build/gerefi.dfu

if [ "$USE_OPENBLT" = "yes" ]; then
  # this image is suitable for update through bootloader only
  # do not deliver update images in any format that can confuse users
  #cp build/gerefi.bin  deliver/gerefi_update.bin
  #cp build/gerefi.dfu  deliver/gerefi_update.dfu
  #cp build/gerefi.hex  deliver/gerefi_update.hex
  # srec is the only format used by OpenBLT host tools
  cp build/gerefi.srec deliver/gerefi_update.srec
else
  # standalone images (for use with no bootloader)
  cp build/gerefi.bin  deliver/
  cp build/gerefi.dfu  deliver/
fi

# bootloader and composite image
if [ "$USE_OPENBLT" = "yes" ]; then
  rm -f deliver/openblt.dfu
  echo "$SCRIPT_NAME: invoking hex2dfu for OpenBLT"
  $HEX2DFU -i build-openblt/openblt_$PROJECT_BOARD.hex -o build-openblt/openblt_$PROJECT_BOARD.dfu

  # do we need all these formats?
  cp build-openblt/openblt_$PROJECT_BOARD.bin  deliver/openblt.bin
  cp build-openblt/openblt_$PROJECT_BOARD.dfu  deliver/openblt.dfu
  #cp build-openblt/openblt_$PROJECT_BOARD.hex  deliver/openblt.hex

  rm -f deliver/gerefi_openblt.dfu
  echo "$SCRIPT_NAME: invoking hex2dfu for composite gerefi+OpenBLT image"
  $HEX2DFU -i build-openblt/openblt_$PROJECT_BOARD.hex -i build/gerefi.hex -C 0x1C -o deliver/gerefi.dfu -b deliver/gerefi.bin
  #todo: how to create 'signed' hex and srec? Do we need?
fi

echo "$SCRIPT_NAME: build folder content:"
ls -l build

echo "$SCRIPT_NAME: deliver folder content:"
ls -l deliver
