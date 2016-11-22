#!/bin/sh

# This script cleans dependent modules

# To run the script do the following:
#    clean.sh
#
# Arguments:
#    None.

#CompType=$1

#if [ "$CompType" = "debug" ];
#then
#    Opt=-g
#    DispInfo="Making ($CompType)"
#else
#    Opt=-O
#    DispInfo="Making"
#fi

cd ..
ModFile=./local/modules.txt

while read One Two Three Four; do
    if [ "$One" = "cvs" ];
    then
        Rep=$One
        ModName=$Three
        ModTag=$Four
    else
        if [ "$One" = "svn" ];
        then
            Rep=$One
            ModName=$Three
            ModTag=$Four
        else
            Rep=cvs 
            ModName=$One
            ModTag=$Two
        fi
    fi

    if [ "$Rep" = "cvs" ];
    then
        DirModName=$ModName
    else
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

    echo
    echo "------------------------------------------------------------"
    echo "**** Cleaning $DirModName ****"
    echo "------------------------------------------------------------"

    cd $DirModName

    case $ModName in 
        etc)
            ;;
        *)
            (make clean_build) || exit 1
            ;;
    esac
    cd .. 
done < $ModFile

exit 0

