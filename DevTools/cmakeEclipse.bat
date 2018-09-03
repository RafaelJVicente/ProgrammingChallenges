cd ..
FOR %%I IN (.) DO SET foldName=%%~nI%%~xI
cd ..
SET buildFoldName=%foldName%_build
rmdir %buildFoldName% /s /q
mkdir %buildFoldName%
cd %buildFoldName%
cmake ../%foldName% -G"Eclipse CDT4 - MinGW Makefiles"
PAUSE