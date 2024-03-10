rd /s /q c:\stuff\gerefi.svn2git 

mkdir -p c:\stuff\gerefi.svn2git\gerefi.svn
cd       c:\stuff\gerefi.svn2git\gerefi.svn
svn co https://svn.code.sf.net/p/gerefi/code/trunk/ .

mkdir -p c:\stuff\gerefi.svn2git\gerefi.github
cd       c:\stuff\gerefi.svn2git\gerefi.github
git clone https://github.com/gerefi/gerefi.git
