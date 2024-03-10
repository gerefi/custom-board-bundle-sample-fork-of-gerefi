rem #
rem # see also ../../misc/git_cheat_sheet.txt
rem # both 'gerefi/ChibiOS/original' and 'gerefi/ChibiOS/gerefi' should have upstream branch changes merged at the same time
rem #
rem # comparing against gerefi version of the unmodified in order to compare remote branches on the same timestamp
rem #

rem git clone -b stable_16.1.x https://github.com/gerefi/ChibiOS Chibios.16_original
rem git -C Chibios.16_original pull
rem git clone -b stable_gerefi https://github.com/gerefi/ChibiOS Chibios.16_gerefi
rem git -C Chibios.16_gerefi pull
rem diff -uwr Chibios.16_gerefi Chibios.16_original > gerefi_chibios_16.patch
rem diff -uwr Chibios.16_original Chibios.16_gerefi > chibios_gerefi_16.patch

 
git clone -b stable_17.6.x        https://github.com/gerefi/ChibiOS Chibios.17_original
git -C Chibios.17_original pull
git clone -b stable_17.6.gerefi   https://github.com/gerefi/ChibiOS Chibios.17_gerefi
git -C Chibios.17_gerefi pull

git clone -b stable_18.2.x        https://github.com/gerefi/ChibiOS Chibios.18_original
git -C Chibios.18_original pull
git clone -b stable_18.2.gerefi   https://github.com/gerefi/ChibiOS Chibios.18_gerefi
git -C Chibios.18_gerefi pull

git clone -b stable_20.3.x        https://github.com/gerefi/ChibiOS Chibios.20_original
git -C Chibios.20_original pull
git clone -b stable_20.3.x.gerefi https://github.com/gerefi/ChibiOS Chibios.20_gerefi
git -C Chibios.20_gerefi pull

diff -uwr Chibios.17_original Chibios.17_gerefi > chibios_gerefi_17.patch
diff -uwr Chibios.18_original Chibios.18_gerefi > chibios_gerefi_18.patch
diff -uwr Chibios.20_original Chibios.20_gerefi > chibios_gerefi_20.patch

