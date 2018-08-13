SET foldName=ProgrammingChallenges_build
cd ../..
rmdir %foldName% /s /q
mkdir %foldName%
cd %foldName%
cmake ../ProgrammingChallenges -G"Eclipse CDT4 - MinGW Makefiles"
PAUSE