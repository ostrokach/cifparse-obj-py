#include "boost/python.hpp"

#include <string>
#include <vector>

#include "DataInfo.h"
#include "PdbMlFileUtil.h"


namespace bp = boost::python;


void InitPdbMlFilePyWrapper()
{
    { //::ParsePdbMl
    
        typedef ::CifFile * ( *ParsePdbMl_function_type )( ::std::string const &,::DataInfo &,bool const );
        
        bp::def( 
            "ParsePdbMl"
            , ParsePdbMl_function_type( &::ParsePdbMl )
            , ( bp::arg("fileName"), bp::arg("dataInfo"), bp::arg("verbose")=(bool const)(false) )
                , bp::return_value_policy<bp::manage_new_object>() );
    
    }

}

