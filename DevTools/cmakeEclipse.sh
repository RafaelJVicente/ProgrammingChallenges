#!/bin/sh
foldName=ProgrammingChallenges_build
cd ../..
rm -rf $foldName
mkdir $foldName
cd $foldName
cmake ../ProgrammingChallenges -G"Eclipse CDT4 - Unix Makefiles"
