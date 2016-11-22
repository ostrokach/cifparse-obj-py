#include "boost/python.hpp"

#include "rcsb_types.h"

namespace bp = boost::python;


void InitTypeCodeWrapper()
{
    bp::enum_< eTypeCode>("eTypeCode")
        .value("eTYPE_CODE_NONE", eTYPE_CODE_NONE)
        .value("eTYPE_CODE_INT", eTYPE_CODE_INT)
        .value("eTYPE_CODE_FLOAT", eTYPE_CODE_FLOAT)
        .value("eTYPE_CODE_STRING", eTYPE_CODE_STRING)
        .value("eTYPE_CODE_TEXT", eTYPE_CODE_TEXT)
        .value("eTYPE_CODE_DATETIME", eTYPE_CODE_DATETIME)
        .value("eTYPE_CODE_BIGINT", eTYPE_CODE_BIGINT)
        .export_values()
        ;

}

