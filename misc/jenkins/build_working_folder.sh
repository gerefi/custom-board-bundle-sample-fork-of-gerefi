#!/bin/bash

#
# file build_working_folder.sh
#

FULL_BUNDLE_FILE="${BUNDLE_FULL_NAME}.zip"
UPDATE_BUNDLE_FILE="${BUNDLE_FULL_NAME}_autoupdate.zip"

echo "${BUNDLE_FULL_NAME}: Packaging temp/$FULL_BUNDLE_FILE file"

rm -rf temp
mkdir temp

SCRIPT_NAME=build_working_folder.sh
echo "Entering $SCRIPT_NAME"

pwd
# This working folder name starts with 'temp/'
echo "$SCRIPT_NAME: Working folder: $FOLDER"
mkdir $FOLDER

CONSOLE_FOLDER="$FOLDER/console"
DRIVERS_FOLDER="$FOLDER/drivers"
OPENBLT_FOLDER="$CONSOLE_FOLDER/openblt"

mkdir $CONSOLE_FOLDER
mkdir $DRIVERS_FOLDER
mkdir $OPENBLT_FOLDER
ls -l $FOLDER

# this magic file is created manually using 'make_package2.bat'
wget https://gerefi.com/build_server/st_files/silent_st_drivers2.exe -P $DRIVERS_FOLDER
[ -e $DRIVERS_FOLDER/silent_st_drivers2.exe ] || { echo "$SCRIPT_NAME: ERROR DOWNLOADING silent_st_drivers2.exe"; exit 1; }

if [ -z $INI_FILE_OVERRIDE ]; then
    INI_FILE_OVERRIDE="gerefi.ini"
    echo "$SCRIPT_NAME: No ini_file_override specified"
fi
echo "$SCRIPT_NAME: Will use $INI_FILE_OVERRIDE"

if [ -z $gerefi_CONSOLE_SETTINGS ]; then
  echo "$SCRIPT_NAME: No gerefi_console_settings"
else
  echo "Using gerefi_console_settings [$gerefi_CONSOLE_SETTINGS]"
  cp $gerefi_CONSOLE_SETTINGS $CONSOLE_FOLDER
fi

cp java_console_binary/gerefi_autoupdate.jar $CONSOLE_FOLDER
cp java_console_binary/gerefi_console.jar $CONSOLE_FOLDER
cp java_tools/ts_plugin_launcher/build/jar/gerefi_ts_plugin_launcher.jar $FOLDER
cp simulator/build/gerefi_simulator.exe   $CONSOLE_FOLDER
cp misc/console_launcher/gerefi_*.exe     $CONSOLE_FOLDER
cp java_console/*.dll                     $CONSOLE_FOLDER
cp java_console/gerefi.xml                $CONSOLE_FOLDER
cp -r java_console/bin                    $FOLDER
cp firmware/ext/openblt/Host/BootCommander.exe $OPENBLT_FOLDER
cp firmware/ext/openblt/Host/libopenblt.dll    $OPENBLT_FOLDER

cp misc/console_launcher/readme.html      $FOLDER

cp firmware/tunerstudio/generated/$INI_FILE_OVERRIDE $FOLDER
# Unsetting since would not be used anywhere else
INI_FILE_OVERRIDE=""
gerefi_CONSOLE_SETTINGS=""

# users probably do not really care for this file
# cp firmware/svnversion.h $FOLDER

cp -r misc/install/openocd $CONSOLE_FOLDER
cp -r misc/install/STM32_Programmer_CLI $CONSOLE_FOLDER
# 407 has additional version of firmware
#cp firmware/deliver/gerefi_no_asserts.bin $FOLDER
#cp firmware/deliver/gerefi_no_asserts.dfu $FOLDER
# just for now - DFU work in progress
#cp firmware/deliver/gerefi_no_asserts.hex $FOLDER

cp firmware/deliver/gerefi.bin $FOLDER
# probably not needed cp firmware/build/gerefi.elf $FOLDER
cp firmware/deliver/gerefi.dfu $FOLDER
# just for now - DFU work in progress
cp firmware/deliver/gerefi.hex $FOLDER

# bootloader
[ -e firmware/deliver/openblt.bin ] && { cp firmware/deliver/openblt.bin $FOLDER ; }
[ -e firmware/deliver/openblt.dfu ] && { cp firmware/deliver/openblt.dfu $FOLDER ; }
# update srec
[ -e firmware/deliver/gerefi_update.srec ] && { cp firmware/deliver/gerefi_update.srec $FOLDER ; }

if [ -n "$BUNDLE_NAME" ]; then
    mv $FOLDER/gerefi.dfu $FOLDER/gerefi_$BUNDLE_NAME.dfu
fi


[ -e firmware/deliver/gerefi.bin ] || { echo "$SCRIPT_NAME: gerefi.bin not found"; exit 1; }

cd temp


echo "Building bundle"
pwd
zip -r $FULL_BUNDLE_FILE *
[ $? -eq 0 ] || (echo "$SCRIPT_NAME: ERROR INVOKING zip"; exit 1)

echo "$SCRIPT_FILE: Bundle $FULL_BUNDLE_FILE ready"
ls -l $FULL_BUNDLE_FILE

[ -e $FULL_BUNDLE_FILE ] || { echo "$SCRIPT_NAME: ERROR not found $FULL_BUNDLE_FILE"; exit 1; }

if [ -n "$gerefi_SSH_USER" ]; then
 echo "$SCRIPT_NAME: Uploading full bundle"
 retVal=0
 if [ "$2" = "true" ]; then
   tar -czf - $FULL_BUNDLE_FILE  | sshpass -p $gerefi_SSH_PASS ssh -o StrictHostKeyChecking=no $gerefi_SSH_USER@$gerefi_SSH_SERVER "mkdir -p build_server/lts/$1; tar -xzf - -C build_server/lts/$1"
   retVal=$?
 else
   tar -czf - $FULL_BUNDLE_FILE  | sshpass -p $gerefi_SSH_PASS ssh -o StrictHostKeyChecking=no $gerefi_SSH_USER@$gerefi_SSH_SERVER "tar -xzf - -C build_server"
   retVal=$?
 fi
 if [ $retVal -ne 0 ]; then
  echo "full bundle upload failed"
  exit 1
 fi
else
  echo "Upload not configured"
fi

cd ..

mkdir -p artifacts
mv temp/$FULL_BUNDLE_FILE artifacts

echo "Removing static content from ${CONSOLE_FOLDER} and $DRIVERS_FOLDER"
rm -rf $CONSOLE_FOLDER/gerefi_autoupdate.exe
rm -rf $CONSOLE_FOLDER/gerefi_console.exe
rm -rf $CONSOLE_FOLDER/DfuSe
rm -rf $CONSOLE_FOLDER/openocd
rm -rf $DRIVERS_FOLDER

# for autoupdate we do not want the unique folder name with timestamp
cd $FOLDER
zip -r ../$UPDATE_BUNDLE_FILE *
cd ..
ls -l $UPDATE_BUNDLE_FILE
if [ -n "$gerefi_SSH_USER" ]; then
 retVal=0
 if [ "$2" = "true" ]; then
   tar -czf - $UPDATE_BUNDLE_FILE  | sshpass -p $gerefi_SSH_PASS ssh -o StrictHostKeyChecking=no $gerefi_SSH_USER@$gerefi_SSH_SERVER "mkdir -p build_server/lts/$1/autoupdate; tar -xzf - -C build_server/lts/$1/autoupdate"
   retVal=$?
 else
   tar -czf - $UPDATE_BUNDLE_FILE  | sshpass -p $gerefi_SSH_PASS ssh -o StrictHostKeyChecking=no $gerefi_SSH_USER@$gerefi_SSH_SERVER "mkdir -p build_server/autoupdate; tar -xzf - -C build_server/autoupdate"
   retVal=$?
 fi
 if [ $retVal -ne 0 ]; then
  echo "autoupdate upload failed"
  exit 1
 fi
else
  echo "Upload not configured"
fi
cd ..
mv temp/$UPDATE_BUNDLE_FILE artifacts

echo "$SCRIPT_NAME: We are back in root directory"

pwd
echo "Exiting $SCRIPT_NAME"
