#!/bin/sh
cd ..
foldName==${PWD##*/}
buildFoldName==${PWD##*/}_build
cd ..
rm -rf $buildFoldName
mkdir $buildFoldName
cd $buildFoldName
cmake ../$foldName -G"Eclipse CDT4 - Unix Makefiles"
