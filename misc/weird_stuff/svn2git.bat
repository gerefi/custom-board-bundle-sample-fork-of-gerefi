

echo This script should be executed from the root of gerefi trunk SVN local copy
pwd 

echo Updating from SVN
call svn update

set gerefi_GIT_PATH=../gerefi.github/gerefi



ls -l %gerefi_GIT_PATH%
rd /s /q %gerefi_GIT_PATH%\firmware
rd /s /q %gerefi_GIT_PATH%\hardware
rd /s /q %gerefi_GIT_PATH%\java_console
rd /s /q %gerefi_GIT_PATH%\unit_tests
rd /s /q %gerefi_GIT_PATH%\simulator

cp -r firmware %gerefi_GIT_PATH%
cp -r hardware %gerefi_GIT_PATH%
cp -r java_console %gerefi_GIT_PATH%
cp -r unit_tests %gerefi_GIT_PATH%
cp -r simulator %gerefi_GIT_PATH%
rm -f %gerefi_GIT_PATH%/readme.*
rm -f %gerefi_GIT_PATH%/README.*
cp -r README.* %gerefi_GIT_PATH%
cp -r readme.* %gerefi_GIT_PATH%


echo Going to git copy location


cd %gerefi_GIT_PATH%

git config --global user.email "russianefi@gmail.com"
git config --global user.name "gerefi"

git pull
git add *
git commit -a -m "auto-sync"
git push --repo https://gerefi:PASSWORD@github.com/gerefi/gerefi
