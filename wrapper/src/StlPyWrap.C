#ifdef VLAD_DEEEEEEEEEEEEEEEEEL
#include "boost/python.hpp"

#ifndef VLAD_DEL_PY
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
#include "boost/python/to_python_converter.hpp"
#include "scitbx/boost_python/container_conversions.h"
#include "scitbx/stl/vector_wrapper.h"
#endif

#include "ISTable.h"
#include "CifFile.h"
#include "CifFileUtil.h"

#ifndef VLAD_DEL_PY
namespace bp = boost::python;
#endif

using namespace boost::python;
using namespace scitbx::boost_python;

using std::string;
using std::vector;

#ifdef VLAD_FIGURE_OUT
bp::container_conversions::from_python_sequence<vector<string>,
bp::container_conversions::variable_capacity_policy>();
#endif

#endif // VLAD_DEEEEEEEEEEEEEEEEEEEEL



#include "boost/python.hpp"

#include <string>
#include <vector>

#ifdef VLAD_INDEX_SUITE
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
#endif
#include "container_conversions.h"


using std::string;
using std::vector;

namespace sb = scitbx::boost_python;
namespace bp = boost::python;


void InitStlPyWrapper()
{
    { // ::std::vector<unsigned int>
        // Container conversion approach
        sb::container_conversions::from_python_sequence<vector<unsigned int>,
          sb::container_conversions::variable_capacity_policy>();

        bp::to_python_converter<vector<unsigned int>,
         sb::container_conversions::to_tuple<vector<unsigned int > > > ();
    }

    { // ::std::vector<std::string>
        // Container conversion approach
        sb::container_conversions::from_python_sequence<vector<string>,
          sb::container_conversions::variable_capacity_policy>();

        bp::to_python_converter<vector<string>,
         sb::container_conversions::to_tuple<vector<string > > > ();

#ifdef VLAD_DELETED
        // Vector wrapper approach
        using namespace scitbx::stl::boost_python; 
        vector_wrapper<std::string>::wrap("vec_str");
#endif

#ifdef VLAD_DELETED
        // Container export to Python
        typedef bp::class_< std::vector< std::string > > vector_less__std_scope_string__greater__exposer_t;
        vector_less__std_scope_string__greater__exposer_t vector_less__std_scope_string__greater__exposer = vector_less__std_scope_string__greater__exposer_t( "vector_less__std_scope_string__greater_" );
        bp::scope vector_less__std_scope_string__greater__scope( vector_less__std_scope_string__greater__exposer );
        vector_less__std_scope_string__greater__exposer.def( bp::vector_indexing_suite< ::std::vector< std::string >, true >() );
#endif

    } 


#ifdef VLAD_INDEX_SUITE
    { // ::std::vector<unsigned int>
        // Container export to Python
        typedef bp::class_< std::vector< unsigned int > > vector_less__unsigned_int__greater__exposer_t;
        vector_less__unsigned_int__greater__exposer_t vector_less__unsigned_int__greater__exposer = vector_less__unsigned_int__greater__exposer_t( "vector_less__unsigned_int__greater_" );
        bp::scope vector_less__unsigned_int__greater__scope( vector_less__unsigned_int__greater__exposer );
        vector_less__unsigned_int__greater__exposer.def( bp::vector_indexing_suite< ::std::vector< unsigned int >, true >() );
    }
#endif

#ifdef VLAD_INDEX_SUITE
    { //scope begin
        typedef bp::class_< std::vector< std::pair<unsigned int, unsigned int> > > vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer_t;
        vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer_t vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer = vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer_t("vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater_");
        bp::scope vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__scope( vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer );
        //WARNING: the next line of code will not compile, because "::std::pair<unsigned int, unsigned int>" does not have operator== !
        vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer.def( bp::vector_indexing_suite< ::std::vector< std::pair<unsigned int, unsigned int> > >() );
    } //scope end
#endif
}

