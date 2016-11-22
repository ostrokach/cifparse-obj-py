# Top level Makefile

UTIL_LOC = https://svn-dev.wwpdb.org/svn-rcsb/build/util
UTIL_MODULE = util
CHECKOUT_SCRIPT = checkout.sh
DIFF_SCRIPT = diff.sh
COMPILE_SCRIPT = compile.sh
CLEAN_SCRIPT = clean.sh
TEST_SCRIPT = test.sh
CLEAN_TEST_SCRIPT = clean_test.sh
DOC_SCRIPT = doc.sh
CLEAN_DOC_SCRIPT = clean_doc.sh
EXPORT_SCRIPT = export.sh

all: 
	@echo
	@echo ------- compile targets are compile_lnx_38, compile_lnx_41, compile_wwpdb_py27 and compile_osx -------

compile:  
	@echo
	@echo ------- compile targets are compile_lnx_38, compile_lnx_41, compile_wwpdb_py27 and compile_osx -------

install: 
	@echo 
	@echo -------- Updating shared wrapper library --------
	@rm -f ./test/CorePyWrap.so
	@cp ./wrapper/lib/CorePyWrap.so ./test


build: checkout

clean: clean_build clean_test clean_doc

checkout:
	@echo 
	@echo -------- Getting version Latest of module util --------
	@svn co $(UTIL_LOC)/trunk $(UTIL_MODULE) 
	@sh -c 'cd ./$(UTIL_MODULE); ./$(CHECKOUT_SCRIPT)'

diff:
	@sh -c 'cd ./$(UTIL_MODULE); ./$(DIFF_SCRIPT)'

compile_osx:
	@sh -c 'cd ./$(UTIL_MODULE); \
         export PIC=-fPIC;  \
         export WWPDB_XERCESC_INC=/opt/local/include; \
         export WWPDB_XERCESC_LIB_DIR=/opt/local/lib; \
         export WWPDB_XERCESC_LIB=xerces-c-3.1; \
         export WWPDB_PYTHON_INC=/opt/local/Library/Frameworks/Python.framework/Versions/2.7/include/python2.7; \
         export WWPDB_BOOST_INC=/opt/local/include; \
         export WWPDB_BOOST_PYTHON_LIB_DIR=/opt/local/lib; \
         export WWPDB_BOOST_PYTHON_LIB=boost_python-mt; \
         export WWPDB_PYTHON_LIB_DIR=/opt/local/lib; \
         export WWPDB_PYTHON_LIB=python2.7; \
        ./$(COMPILE_SCRIPT)'

compile_lnx_38:
	@sh -c 'cd ./$(UTIL_MODULE); \
         export PIC=-fPIC;  \
         export WWPDB_PYTHON_INC=/apps/python/include/python2.5; \
         export WWPDB_PYTHON_LIB_DIR=/apps/python/lib; \
         export WWPDB_PYTHON_LIB=python2.5; \
         export WWPDB_BOOST_INC=/apps/boost_1_38_0/include/boost-1_38; \
         export WWPDB_BOOST_PYTHON_LIB_DIR=/apps/boost_1_38_0/lib; \
         export WWPDB_BOOST_PYTHON_LIB=boost_python-gcc41-mt-1_38; \
         export WWPDB_XERCESC_INC=/apps/xerces-3.0.1/include; \
         export WWPDB_XERCESC_LIB_DIR=/apps/xerces-3.0.1/lib; \
         export WWPDB_XERCESC_LIB=xerces-c; \
         ./$(COMPILE_SCRIPT)'

compile_lnx_41:
	@sh -c 'cd ./$(UTIL_MODULE); \
        export PIC=-fPIC; \
        export WWPDB_PYTHON_INC=/apps/python/include/python2.5; \
	export WWPDB_PYTHON_LIB_DIR=/apps/python/lib; \
        export WWPDB_PYTHON_LIB=python2.5; \
        export WWPDB_BOOST_INC=/apps/boost/include/boost-1_41; \
        export WWPDB_BOOST_PYTHON_LIB_DIR=/apps/boost/lib; \
        export WWPDB_BOOST_PYTHON_LIB=boost_python-gcc41-mt-1_41; \
        export WWPDB_XERCESC_INC=/apps/xerces-3.0.1/include; \
        export WWPDB_XERCESC_LIB_DIR=/apps/xerces-3.0.1/lib; \
        export WWPDB_XERCESC_LIB=xerces-c; \
        ./$(COMPILE_SCRIPT)'


compile_wwpdb_py27:
	@sh -c 'cd ./$(UTIL_MODULE); \
        export PIC=-fPIC; \
        export WWPDB_PYTHON_INC=$(TOP_INSTALL_DIR)/include/python2.7; \
	export WWPDB_PYTHON_LIB_DIR=$(TOP_INSTALL_DIR)/lib; \
        export WWPDB_PYTHON_LIB=python2.7; \
        export WWPDB_BOOST_INC=$(TOP_INSTALL_DIR)/include; \
        export WWPDB_BOOST_PYTHON_LIB_DIR=$(TOP_INSTALL_DIR)/lib; \
        export WWPDB_BOOST_PYTHON_LIB=boost_python-mt; \
        export WWPDB_XERCESC_INC=$(TOP_INSTALL_DIR)/include; \
        export WWPDB_XERCESC_LIB_DIR=$(TOP_INSTALL_DIR)/lib; \
        export WWPDB_XERCESC_LIB=xerces-c; \
        ./$(COMPILE_SCRIPT)'



debug:
	@sh -c 'cd ./$(UTIL_MODULE); ./$(COMPILE_SCRIPT) debug'

clean_build: 
	@sh -c 'cd ./$(UTIL_MODULE); ./$(CLEAN_SCRIPT)'

test: test-all

testall: compile 
	@sh -c 'cd ./$(UTIL_MODULE); ./$(TEST_SCRIPT)'

clean_test: 
	@sh -c 'cd ./$(UTIL_MODULE); ./$(CLEAN_TEST_SCRIPT)'

###
doc:
	@sh -c 'cd ./$(UTIL_MODULE); ./$(DOC_SCRIPT)'

clean_doc:
	@sh -c 'cd ./$(UTIL_MODULE); ./$(CLEAN_DOC_SCRIPT)'

export: clean
	@sh -c 'cd ./$(UTIL_MODULE); ./$(EXPORT_SCRIPT)'

###

everything:  compile 



