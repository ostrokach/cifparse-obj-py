#!/bin/csh -f
#
# Simple example of creating a Boost Python wrapper - JDW May 1, 2009 -
#
# Assign the path to your local Python include directory - 
set MY_PYTHON_INCLUDE   = "/opt/python/include/python2.5"

#
# Assign the paths to the BOOST include files and BOOST Python shared library.
#
set MY_BOOST_INCLUDE    = "/apps/boost/include/boost-1_38"
set MY_BOOST_LIB        = "/apps/boost/lib"
set MY_BOOST_PYTHON_LIB = "libboost_python-gcc41-mt.so"

#  If you have g++ and python in your path then the rest should work 
# 
g++  -ftemplate-depth-128 -O -fno-inline -Wall  -fPIC    -I$MY_PYTHON_INCLUDE  -I$MY_BOOST_INCLUDE \
         -c -o obj/AddNumbers.o AddNumbers.cpp

g++  -ftemplate-depth-128 -O -fno-inline -Wall  -fPIC    -I$MY_PYTHON_INCLUDE  -I$MY_BOOST_INCLUDE \
         -c -o obj/AddNumbers_wrap.o AddNumbers_wrap.cpp

#
g++ -o lib/AddNumbers_wrap.so  -shared  \
       obj/AddNumbers.o \
       obj/AddNumbers_wrap.o \
       ${MY_BOOST_LIB}/${MY_BOOST_PYTHON_LIB} \
      -lutil -lpthread -ldl 
#
#  This path needs to include the Boost Python library and the shared library for the wrapper 
#  created in the previous step ... 
# 
setenv LD_LIBRARY_PATH "./lib:${MY_BOOST_LIB}/${MY_BOOST_PYTHON_LIB}:/usr/bin:/usr/lib:/usr/lib32:/usr/lib64"

# Run the python script to test the wrapper - 
#
/opt/python/bin/python AddNumbersClient.py
#
