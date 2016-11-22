#include "boost/python.hpp"

#include "Serializer.h"


namespace bp = boost::python;


void InitRcsbFilePyWrapper()
{
    // VLAD - This should be moved to RcsbFile class
    bp::enum_< eFileMode>("eFileMode")
        .value("NO_MODE", NO_MODE)
        .value("READ_MODE", READ_MODE)
        .value("CREATE_MODE", CREATE_MODE)
        .value("UPDATE_MODE", UPDATE_MODE)
        .value("VIRTUAL_MODE", VIRTUAL_MODE)
        .export_values()
        ;
}

