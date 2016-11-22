#ifndef PDBML_FILE_UTIL_H
#define PDBML_FILE_UTIL_H


#include <string>

#include "DataInfo.h"
#include "CifFile.h"


CifFile* ParsePdbMl(const std::string& fileName, DataInfo& dataInfo,
  const bool verbose = false);


#endif // PDBML_FILE_UTIL_H
