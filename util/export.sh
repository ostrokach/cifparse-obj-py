#!/bin/sh

# This exports production along with dependent modules

# To run the script do the following:
#    export.sh
#
# Arguments:
#    None.


DIRS="bin include lib"
FILES="Makefile README"
ETCFILES="platform.sh initlib.sh cifinstall LICENSE"
VERFILE="./local/VERSION"

cd ..

mkdir -p ../Exported

cd ../Exported
mkdir $DIRS
cd -

cp $FILES ../Exported

cp $VERFILE ../Exported

mkdir ../Exported/util
cp util/*.sh ../Exported/util

mkdir ../Exported/local
cp local/modules.txt ../Exported/local
cp local/platforms.txt ../Exported/local

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
    echo "Exporting $DirModName"

    cd $DirModName

    case $ModName in 
        etc)
            mkdir -p ../../Exported/etc
            cp $ETCFILES ../../Exported/etc
            ;;
        *)
	    (make export) || exit 1;
	    mv export_dir ../../Exported/$DirModName
            ;;
    esac
    cd .. 
done < $ModFile

# Get supported platforms
PlatFile=./local/platforms.txt

while read Plat; do
    cat etc/make.platform.$Plat | grep -v "^WARNINGS_AS_ERRORS" > \
      ../Exported/etc/make.platform.$Plat
done < $PlatFile

# Only for dict-pack
sed "s/DATADIRS = \$(INTERNAL_DATA_DIRS) \$(EXTERNAL_DATA_DIRS)/DATADIRS = \$(EXTERNAL_DATA_DIRS)/g" Makefile > ../Exported/Makefile

perl ./etc/exportPackage.pl $VERFILE ../Exported

exit 0

