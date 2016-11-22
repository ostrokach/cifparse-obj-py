#
#        WRAPPER module makefile
#
#----------------------------------------------------------------------------
# Project specific path defintions.
#----------------------------------------------------------------------------
M_INCL_DIR  = ../include
M_LIB_DIR   = ../lib

PROJ_DIR = .

L_INCL_DIR  = $(PROJ_DIR)/include
SRC_DIR     = $(PROJ_DIR)/src
OBJ_DIR     = $(PROJ_DIR)/obj
L_LIB_DIR   = $(PROJ_DIR)/lib

VPATH = $(OBJ_DIR)

EXT_COMP_OPT = -ftemplate-depth-128 -fno-inline -Wall

EXT_INCLS_DIRS = -I$(WWPDB_PYTHON_INC) -I$(WWPDB_BOOST_INC)
EXT_LIBS_DIRS = -L$(WWPDB_PYTHON_LIB_DIR) -L$(WWPDB_BOOST_PYTHON_LIB_DIR) \
  -L$(WWPDB_XERCESC_LIB_DIR)
EXT_LIBS      = -l$(WWPDB_PYTHON_LIB) -l$(WWPDB_BOOST_PYTHON_LIB) \
  -l$(WWPDB_XERCESC_LIB)

SYS_LIBS = -lutil -lpthread -ldl

LINK_METHOD = -shared

#----------------------------------------------------------------------------
# LINCLUDES and LDEFINES are appended to CFLAGS and C++FLAGS
#----------------------------------------------------------------------------
LDEFINES  = -Wno-unused-local-typedefs 
LINCLUDES = -I$(L_INCL_DIR) -I$(M_INCL_DIR) $(EXT_INCLS_DIRS)

#----------------------------------------------------------------------------
# Include the appropriate compiler/platform definitions ...
#----------------------------------------------------------------------------
include ../etc/Makefile.platform

# Dependent libraries
PDBML_PARSER_LIB  = ../$(M_LIB_DIR)/pdbml-parser.a
DICT_OBJ_FILE_LIB = ../$(M_LIB_DIR)/dict-obj-file.a
CIF_FILE_UTIL_LIB = ../$(M_LIB_DIR)/cif-file-util.a
CIF_FILE_LIB      = ../$(M_LIB_DIR)/cif-file.a
CIFPARSE_LIB      = ../$(M_LIB_DIR)/cifparse-obj.a
TABLES_LIB        = ../$(M_LIB_DIR)/tables.a
COMMON_LIB        = ../$(M_LIB_DIR)/common.a
REGEX_LIB         = ../$(M_LIB_DIR)/regex.a

ALL_DEP_LIBS = $(PDBML_PARSER_LIB) $(DICT_OBJ_FILE_LIB) $(CIF_FILE_UTIL_LIB) \
  $(CIF_FILE_LIB) $(CIFPARSE_LIB) $(TABLES_LIB) $(COMMON_LIB) $(REGEX_LIB)

# Module libraries
MOD_LIB = CorePyWrap.so

# Agregate library
AGR_LIB = all.a

# Temporary library. Used to obtain the agregate library.
TMP_LIB = tmp.a

L_MOD_LIB = $(L_LIB_DIR)/$(MOD_LIB)
M_MOD_LIB = $(M_LIB_DIR)/$(MOD_LIB)
L_AGR_LIB = $(L_LIB_DIR)/$(AGR_LIB)
M_AGR_LIB = $(M_LIB_DIR)/$(AGR_LIB)


# Base file names. Must have ".ext" at the end of the file.
BASE_REGULAR_FILES = TypeCodePyWrap.ext \
                     StlPyWrap.ext \
                     CharPyWrap.ext \
                     RcsbFilePyWrap.ext \
                     ISTablePyWrap.ext \
                     TableFilePyWrap.ext \
                     CifFilePyWrap.ext \
                     DicFilePyWrap.ext \
                     DictObjFilePyWrap.ext \
                     DataInfoPyWrap.ext \
                     CifDataInfoPyWrap.ext \
                     DictDataInfoPyWrap.ext \
                     PdbMlFilePyWrap.ext \
                     CorePyWrap.ext

BASE_FILES = $(BASE_REGULAR_FILES)

# Source files. Replace ".ext" with ".C"
SRC_FILES = ${BASE_FILES:.ext=.C}

# Object files. Replace ".ext" with ".o"
OBJ_FILES = ${BASE_FILES:.ext=.o}

# Base header files. Replace ".ext" with ".h"
BASE_HEADER_FILES = ${BASE_FILES:.ext=.h}

EXTRA_HEADER_FILES = 

HEADER_FILES = $(BASE_HEADER_FILES) $(EXTRA_HEADER_FILES)

ALL_OBJ_FILES = *.o

.PHONY: ../etc/Makefile.platform all install export clean clean_build


all: install


install: $(M_MOD_LIB)


export:
	mkdir -p $(EXPORT_DIR)
	@cp Makefile $(EXPORT_DIR)
	@cd $(EXPORT_DIR); mkdir -p $(L_INCL_DIR)
	@cd $(L_INCL_DIR); $(EXPORT) $(EXPORT_LIST) $(HEADER_FILES) ../$(EXPORT_DIR)/$(L_INCL_DIR)
	@cd $(EXPORT_DIR); mkdir -p $(SRC_DIR)
	@cd $(SRC_DIR);	$(EXPORT) $(EXPORT_LIST) $(SRC_FILES) ../$(EXPORT_DIR)/$(SRC_DIR)
	@cd $(EXPORT_DIR); mkdir -p $(OBJ_DIR)
	@cd $(EXPORT_DIR); mkdir -p $(L_LIB_DIR)


clean: clean_build


$(M_MOD_LIB): $(L_MOD_LIB)
#       Install module library
	$(INSTALL) $(INSTALLOPTS) $(L_MOD_LIB) $(PROJ_DIR)
	$(INSTALL) $(INSTALLOPTS) $(L_MOD_LIB) $(M_LIB_DIR)


clean_build:
	@rm -f $(OBJ_DIR)/*.o
	@rm -rf $(OBJ_DIR)/ii_files
	@rm -f $(L_MOD_LIB)
	@rm -f $(PROJ_DIR)/$(MOD_LIB)
	@rm -f $(M_MOD_LIB)
	@rm -f $(M_AGR_LIB)
	@rm -f *.pyc


$(L_MOD_LIB): $(OBJ_FILES) $(ALL_DEP_LIBS)
#       Create module library

	@cd $(OBJ_DIR); $(CCC) $(LINK_METHOD) $(EXT_LIBS_DIRS) $(OBJ_FILES) $(ALL_DEP_LIBS) $(EXT_LIBS) $(SYS_LIBS) -o ../$@


# Rule for making object files
%.o: $(SRC_DIR)/%.C
	$(CCC) $(C++FLAGS) $(EXT_COMP_OPT) -c $< -o $(OBJ_DIR)/$@

