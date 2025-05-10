#!/bin/bash

# Check if a project prefix is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 projectPrefix"
    exit 1
fi

projectPrefix=$1

cd source

# Change all "B0" in CMakeLists.txt to the new project prefix
sed -i "s/B0/$projectPrefix/g" CMakeLists.txt

# Rename B0.cc to the new project prefix file
mv B0.cc ${projectPrefix}.cc

# Change all "B0" in the new .cc file to the new project prefix
sed -i "s/B0/$projectPrefix/g" ${projectPrefix}.cc

# List of source and header files to update
src_files="ActionInitialization.cc DetectorConstruction.cc EventAction.cc PrimaryGeneratorAction.cc RunAction.cc SteppingAction.cc"
hdr_files="ActionInitialization.hh DetectorConstruction.hh EventAction.hh PrimaryGeneratorAction.hh RunAction.hh SteppingAction.hh"

# Change directory to src and update files
cd src
for file in $src_files; do
    sed -i "s/B0/$projectPrefix/g" $file
done

# Change directory to include and update files
cd ../include
for file in $hdr_files; do
    sed -i "s/B0/$projectPrefix/g" $file
done
