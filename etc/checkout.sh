#!/bin/sh

# This script checks out from repository the modules needed to build the
# production.

# To run the script do the following:
#    checkout.sh
#
# Arguments:
#    None.

cd ..

echo

echo -------- Removing temporary etc directory --------
echo
rm -rf etc

ModFile=./local/modules.txt

echo -------- Getting the modules --------
echo

while read ModName ModTag; do
    echo ---------- Getting version $ModTag of module $ModName ----------
    if [ "$ModTag" = "Latest" ];
    then
        cvs co $ModName
    else
        cvs co -r $ModTag $ModName
    fi
done < $ModFile

cd etc

exit 0

