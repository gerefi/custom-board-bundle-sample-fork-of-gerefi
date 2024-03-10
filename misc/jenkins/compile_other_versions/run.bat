set script_name=run.bat
echo Entering %script_name%
echo "gerefi_BUILD_FTP_USER=%gerefi_BUILD_FTP_USER%"

pwd

call misc\jenkins\build_java_console.bat
if not exist java_console_binary/gerefi_console.jar exit -1

call misc\jenkins\build_simulator.bat
if not exist simulator/build/gerefi_simulator.exe exit -1

rem #
rem # see gen_config.sh where short<>long name dictionary is hard-coded
rem #

call misc\jenkins\compile_other_versions\compile_and_upload.bat frankenso frankenso_na6
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd

call misc\jenkins\compile_other_versions\compile_and_upload.bat kinetis kinetis
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1

call misc\jenkins\compile_other_versions\compile_and_upload.bat microgerefi mre_f4 gerefi_mre_f4.ini
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd

rem call misc\jenkins\compile_other_versions\compile_and_upload.bat microgerefi mre_f4_slave gerefi_mre_f7.ini
rem IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
rem IF %ERRORLEVEL% NEQ 0 EXIT /B 1
rem pwd

call misc\jenkins\compile_other_versions\compile_and_upload.bat microgerefi mre_f4_hardware_QC_special_build gerefi_microgerefi.ini
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd

set f7_console_setting=firmware\config\boards\nucleo_f767\gerefi_console_properties.xml

rem                     folter_name configuration_name [optional .ini file name]

call misc\jenkins\compile_other_versions\compile_and_upload.bat microgerefi mre_f7 gerefi_microgerefi.ini %f7_console_setting%
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd

rem call misc\jenkins\compile_other_versions\compile_and_upload.bat microgerefi mre_f7_test gerefi_microgerefi.ini %f7_console_setting%
rem IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
rem IF %ERRORLEVEL% NEQ 0 EXIT /B 1
rem pwd

call misc\jenkins\compile_other_versions\compile_and_upload.bat prometheus prometheus_405 prometheus_405.ini
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd


call misc\jenkins\compile_other_versions\compile_and_upload.bat prometheus prometheus_469 prometheus_469.ini
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd

call misc\jenkins\compile_other_versions\compile_and_upload.bat proteus     proteus_f4 gerefi_proteus_f4.ini
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd

call misc\jenkins\compile_other_versions\compile_and_upload.bat proteus     proteus_f7 gerefi_proteus_f7.ini
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd


call misc\jenkins\compile_other_versions\compile_and_upload.bat nucleo_f767 stm32f767_nucleo no %f7_console_setting%
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd


rem call misc\jenkins\compile_other_versions\compile_and_upload.bat nucleo_f767 stm32f767_osc no %f7_console_setting%
rem IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
rem IF %ERRORLEVEL% NEQ 0 EXIT /B 1
rem pwd

call misc\jenkins\compile_other_versions\compile_and_upload.bat prometheus prometheus_405 gerefi_prometheus_405.ini
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd


call misc\jenkins\compile_other_versions\compile_and_upload.bat prometheus prometheus_469 gerefi_prometheus_469.ini
IF %ERRORLEVEL% NEQ 0 echo ERROR invoking compile_and_upload.bat
IF %ERRORLEVEL% NEQ 0 EXIT /B 1
pwd
