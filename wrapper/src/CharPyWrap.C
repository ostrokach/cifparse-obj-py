#include "boost/python.hpp"

#include "GenString.h"


namespace bp = boost::python;


void InitCharPyWrapper()
{
    { //::Char
        typedef bp::class_< Char > Char_exposer_t;
        Char_exposer_t Char_exposer = Char_exposer_t( "Char" );
        bp::scope Char_scope( Char_exposer );
        bp::enum_< Char::eCompareType>("eCompareType")
            .value("eCASE_SENSITIVE", Char::eCASE_SENSITIVE)
            .value("eCASE_INSENSITIVE", Char::eCASE_INSENSITIVE)
            .value("eWS_INSENSITIVE", Char::eWS_INSENSITIVE)
            .value("eAS_INTEGER", Char::eAS_INTEGER)
            .export_values()
            ;
    }
}

