#!/bin/bash
# This script files reads gerefi_config.txt and produces firmware persistent configuration headers
# the storage section of gerefi.ini is updated as well

BOARDNAME=kinetis
SHORT_BOARDNAME=kin
BOARD_DIR=config/boards/${BOARDNAME}















  INI="gerefi_${SHORT_BOARDNAME}.ini"




bash gen_signature.sh ${SHORT_BOARDNAME}

source gen_config_common.sh
echo "Using COMMON_GEN_CONFIG [$COMMON_GEN_CONFIG]"

java \
 $COMMON_GEN_CONFIG_PREFIX \
 -tool kinetis_gen_config.bat \
 $COMMON_GEN_CONFIG \
 -c_defines ${BOARD_DIR}/config/controllers/algo/gerefi_generated.h \
 -c_destination ${BOARD_DIR}/config/controllers/algo/engine_configuration_generated_structures.h \
 -enumInputFile controllers/algo/gerefi_hw_enums.h

[ $? -eq 0 ] || { echo "ERROR generating TunerStudio config for ${BOARDNAME}"; exit 1; }
