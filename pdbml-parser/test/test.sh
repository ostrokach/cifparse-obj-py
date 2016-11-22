#!/bin/bash

# Save test start time
START_TIME=$(date +%s)

# Execute all tests

#
# This scripts assumes that the Xerces libary path is known to the
# executing environment.

../bin/xml2mmcif -xml `pwd`/1ysh.xml -df mmcif_pdbx.odb -dict mmcif_pdbx.dic

# Save test end time
END_TIME=$(date +%s)

DIFF_TIME=$(( $END_TIME - $START_TIME ))

echo "Tests execution time is $DIFF_TIME seconds." > exectime.txt

echo
echo
cat exectime.txt
echo
echo
