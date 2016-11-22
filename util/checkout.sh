#!/bin/sh

# This script checks out from repository the modules needed to build the
# production.

# To run the script do the following:
#    checkout.sh
#
# Arguments:
#    None.

cd ..

ModFile=./local/modules.txt

echo
echo -------- Getting the modules --------
echo


while read One Two Three Four; do
    if [ "$One" = "cvs" ];
    then
        Rep=$One
        RepName=
        ModName=$Three
        ModTag=$Four
    else
        if [ "$One" = "svn" ];
        then
            Rep=$One
            RepName=$Two
            ModName=$Three
            ModTag=$Four
        else
            Rep=cvs 
            RepName=
            ModName=$One
            ModTag=$Two
        fi
    fi

    echo -------- Getting version $ModTag of module $ModName --------

    if [ "$Rep" = "cvs" ];
    then
        TagOpt="-r $ModTag"
        LatOpt=
        DirModName=$ModName
    else
        TagOpt=$RepName/tags/$ModTag
        LatOpt=$RepName/trunk
        if [ "$ModTag" = "Latest" ];
        then
            DirModName=$ModName
        else
            case $ModName in 
                etc)
                    DirModName=$ModName
                    ;;
                dicts)
                    DirModName=$ModName
                    ;;
                *)
                    DirModName=$ModName-$ModTag
                    ;;
            esac
        fi 
    fi

    if [ "$ModTag" = "Latest" ];
    then
        $Rep co $LatOpt $DirModName
    else
        $Rep co $TagOpt $DirModName
    fi
done < $ModFile

exit 0

