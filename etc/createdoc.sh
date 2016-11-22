#!/bin/sh
#
#  File:  createdoc.sh
#
#  Purpose: For all source modules in the production, creates documentation
#    from the source files.
#
#  Assumptions: Script is started from within the etc directory.

# See if doxygen is installed and report error if it is not

Doxygen=$(which doxygen)

if [ x"$Doxygen" = x ]
then
    echo doxygen not found. Please make doxygen tool available to this script!
    exit 1;
fi

# Go to the base production directory
cd ..

# If it does not exist, create root documentation directory
if [[ ! -e docs ]];
then
    mkdir docs;
fi

# If it does not exist, create doxygen configuration files directory
if [[ ! -e docs/doxyfiles ]];
then
    mkdir docs/doxyfiles;
fi

# If it does not exist, create root modules documentation directory
if [[ ! -e docs/modules ]];
then
    mkdir docs/modules;
fi


# Read all the modules from local/modules.txt

ModFile=./local/modules.txt

while read One Two ModName ModTag; do

# For each module, create module doxygen configuration file
    echo PROJECT_NAME     = $ModName-$ModTag   >> docs/doxyfiles/Doxyfile-$ModName-$ModTag
    echo PROJECT_NUMBER   = $ModTag   >> docs/doxyfiles/Doxyfile-$ModName-$ModTag
    echo OUTPUT_DIRECTORY = docs/modules/$ModName-$ModTag >> docs/doxyfiles/Doxyfile-$ModName-$ModTag
    echo INPUT = ./$ModName-$ModTag >> docs/doxyfiles/Doxyfile-$ModName-$ModTag
    cat etc/Doxyfile-template >> docs/doxyfiles/Doxyfile-$ModName-$ModTag

# For each module run doxygen to generate documentation
    doxygen docs/doxyfiles/Doxyfile-$ModName-$ModTag

done < $ModFile

echo Done.
