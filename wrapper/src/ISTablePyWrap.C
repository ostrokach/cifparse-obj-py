#include "boost/python.hpp"

#include <string>
#include <vector>

#include "ISTable.h"


namespace bp = boost::python;


#ifndef VLAD_PYTHON_GLUE
vector<unsigned int> Py_ISTable__Search(ISTable& isTable,
  const std::vector<std::string>& targets,
  const std::vector<std::string>& colNames,
  const unsigned int fromRowIndex,
  const ITTable::eSearchDir searchDir,
  const ITTable::eSearchType searchType,
  const std::string& indexName)
{
    vector<unsigned int> rowsIndices;

    isTable.Search(rowsIndices, targets, colNames, fromRowIndex, searchDir,
      searchType, indexName);

    return(rowsIndices);
}


vector<std::string> Py_ISTable__GetColumn(ISTable& isTable,
  const std::string& colName)
{
    vector<std::string> col;

    isTable.GetColumn(col, colName);

    return (col);
}
#endif // VLAD_PYTHON_GLUE


void InitISTablePyWrapper()
{
    { //::ITTable
        typedef bp::class_< ITTable > ITTable_exposer_t;
        ITTable_exposer_t ITTable_exposer = ITTable_exposer_t( "ITTable", bp::init< >() );
        bp::scope ITTable_scope( ITTable_exposer );
        bp::enum_< ITTable::eOrientation>("eOrientation")
            .value("eCOLUMN_WISE", ITTable::eCOLUMN_WISE)
            .value("eROW_WISE", ITTable::eROW_WISE)
            .export_values()
            ;
        bp::enum_< ITTable::eSearchDir>("eSearchDir")
            .value("eFORWARD", ITTable::eFORWARD)
            .value("eBACKWARD", ITTable::eBACKWARD)
            .export_values()
            ;
        bp::enum_< ITTable::eSearchType>("eSearchType")
            .value("eEQUAL", ITTable::eEQUAL)
            .value("eLESS_THAN", ITTable::eLESS_THAN)
            .value("eLESS_THAN_OR_EQUAL", ITTable::eLESS_THAN_OR_EQUAL)
            .value("eGREATER_THAN", ITTable::eGREATER_THAN)
            .value("eGREATER_THAN_OR_EQUAL", ITTable::eGREATER_THAN_OR_EQUAL)
            .export_values()
            ;
        ITTable_exposer.def( bp::init< ITTable::eOrientation >(( bp::arg("orient") )) );
        bp::implicitly_convertible< ITTable::eOrientation, ITTable >();
        ITTable_exposer.def( bp::init< ITTable const & >(( bp::arg("inTable") )) );
    }

    { //::ISTable
        typedef bp::class_< ISTable > ISTable_exposer_t;
        ISTable_exposer_t ISTable_exposer = ISTable_exposer_t( "ISTable", bp::init< bp::optional< Char::eCompareType > >(( bp::arg("colCaseSense")=::Char::eCASE_SENSITIVE )) );
        bp::scope ISTable_scope( ISTable_exposer );
        bp::enum_< ISTable::eTableDiff>("eTableDiff")
            .value("eNONE", ISTable::eNONE)
            .value("eCASE_SENSE", ISTable::eCASE_SENSE)
            .value("eMORE_COLS", ISTable::eMORE_COLS)
            .value("eLESS_COLS", ISTable::eLESS_COLS)
            .value("eCOL_NAMES", ISTable::eCOL_NAMES)
            .value("eMORE_ROWS", ISTable::eMORE_ROWS)
            .value("eLESS_ROWS", ISTable::eLESS_ROWS)
            .value("eCELLS", ISTable::eCELLS)
            .value("eMISSING", ISTable::eMISSING)
            .value("eEXTRA", ISTable::eEXTRA)
            .export_values()
            ;
        bp::implicitly_convertible< Char::eCompareType const, ISTable >();
        ISTable_exposer.def( bp::init< ITTable::eOrientation, bp::optional< Char::eCompareType > >(( bp::arg("orient"), bp::arg("colCaseSense")=::Char::eCASE_SENSITIVE )) );
        ISTable_exposer.def( bp::init< std::string const &, bp::optional< Char::eCompareType > >(( bp::arg("name"), bp::arg("colCaseSense")=::Char::eCASE_SENSITIVE )) );
        ISTable_exposer.def( bp::init< std::string const &, ITTable::eOrientation, bp::optional< Char::eCompareType > >(( bp::arg("name"), bp::arg("orient"), bp::arg("colCaseSense")=::Char::eCASE_SENSITIVE )) );
        ISTable_exposer.def( bp::init< ISTable const & >(( bp::arg("inTable") )) );
        { //::ISTable::GetName
        
            typedef ::std::string const & ( ::ISTable::*GetName_function_type )(  ) const;
            
            ISTable_exposer.def( 
                "GetName"
                , GetName_function_type( &::ISTable::GetName )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ISTable::SetName

            typedef void ( ::ISTable::*SetName_function_type )( ::std::string const & ) ;

            ISTable_exposer.def(
                "SetName"
                , SetName_function_type( &::ISTable::SetName )
                , ( bp::arg("name") ) );

        }
        { //::ISTable::GetColCaseSense
        
            typedef ::Char::eCompareType ( ::ISTable::*GetColCaseSense_function_type )(  ) const;
            
            ISTable_exposer.def( 
                "GetColCaseSense"
                , GetColCaseSense_function_type( &::ISTable::GetColCaseSense ) );
        
        }
        { //::ISTable::GetColumnNames
        
            typedef ::std::vector< std::string > const & ( ::ISTable::*GetColumnNames_function_type )(  ) const;
            
            ISTable_exposer.def( 
                "GetColumnNames"
                , GetColumnNames_function_type( &::ISTable::GetColumnNames )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ISTable::IsColumnPresent

            typedef bool ( ::ISTable::*IsColumnPresent_function_type )( ::std:: string const & ) ;

            ISTable_exposer.def(
                "IsColumnPresent"
                , IsColumnPresent_function_type( &::ISTable::IsColumnPresent )
                , ( bp::arg("colName") ) );

        }
        { //::ISTable::AddColumn
        
            typedef void ( ::ISTable::*AddColumn_function_type )( ::std::string const &,::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "AddColumn"
                , AddColumn_function_type( &::ISTable::AddColumn )
                , ( bp::arg("colName"), bp::arg("col")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >)( std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ISTable::AddRow
        
            typedef unsigned int ( ::ISTable::*AddRow_function_type )( ::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "AddRow"
                , AddRow_function_type( &::ISTable::AddRow )
                , ( bp::arg("row")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >)( std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ISTable::FillRow
        
            typedef void ( ::ISTable::*FillRow_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "FillRow"
                , FillRow_function_type( &::ISTable::FillRow )
                , ( bp::arg("rowIndex"), bp::arg("row") ) );
        
        }
        { //::ISTable::UpdateCell

            typedef void ( ::ISTable::*UpdateCell_function_type )( unsigned int const,::std::string const &,::std::string const & ) ;

            ISTable_exposer.def(
                "UpdateCell"
                , UpdateCell_function_type( &::ISTable::UpdateCell )
                , ( bp::arg("rowIndex"), bp::arg("colName"), bp::arg("value") ) );

        }
        { //::ISTable::operator()

            typedef ::std::string const & ( ::ISTable::*__call___function_type )( unsigned int const,::std::string const & ) const;

            ISTable_exposer.def(
                "__call__"
                , __call___function_type( &::ISTable::operator() )
                , ( bp::arg("rowIndex"), bp::arg("colName") )
                , bp::return_value_policy< bp::copy_const_reference >() );

        }
        { //::ISTable::FindFirst

            typedef unsigned int ( ::ISTable::*FindFirst_function_type )( ::std::vector< std::string > const &,::std::vector< std::string > const &,::std::string const & ) ;

            ISTable_exposer.def(
                "FindFirst"
                , FindFirst_function_type( &::ISTable::FindFirst )
                , ( bp::arg("targets"), bp::arg("colNames"), bp::arg("indexName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() ) );

        }
        { //::ISTable::Search
        
            typedef void ( ::ISTable::*Search_function_type )( ::std::vector< unsigned int > &,::std::vector< std::string > const &,::std::vector< std::string > const &,unsigned int const,::ITTable::eSearchDir const,::ITTable::eSearchType const,::std::string const & ) ;
            
            ISTable_exposer.def( 
                "Search"
                , &::Py_ISTable__Search
                , ( bp::arg("targets"), bp::arg("colNames"), bp::arg("fromRowIndex")=(unsigned int const)(0), bp::arg("searchDir")=ITTable::eFORWARD, bp::arg("searchType")=ITTable::eEQUAL, bp::arg("indexName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >()) );
        
        }
        { //::ISTable::GetNumRows
        
            typedef unsigned int ( ::ISTable::*GetNumRows_function_type )(  ) const;
            
            ISTable_exposer.def( 
                "GetNumRows"
                , GetNumRows_function_type( &::ISTable::GetNumRows ) );
        
        }
        { //::ISTable::GetRow
        
            typedef void ( ::ISTable::*GetRow_function_type )( ::std::vector< std::string > &,unsigned int const,::std::string const &,::std::string const & ) ;
            
            ISTable_exposer.def( 
                "GetRow"
                , GetRow_function_type( &::ISTable::GetRow )
                , ( bp::arg("row"), bp::arg("rowIndex"), bp::arg("fromColName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >(), bp::arg("toColName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() ) );
        
        }
        { //::ISTable::GetRow

            typedef ::std::vector< std::string > const & ( ::ISTable::*GetRow_function_type )( unsigned int const ) ;

            ISTable_exposer.def(
                "GetRow"
                , GetRow_function_type( &::ISTable::GetRow )
                , ( bp::arg("rowIndex") )
                , bp::return_value_policy< bp::copy_const_reference >() );

        }
        { //::ISTable::GetColumn

            typedef void ( ::ISTable::*GetColumn_function_type )( ::std::vector< std::string > &,::std::string const & ) ;

            ISTable_exposer.def(
                "GetColumn"
                , &::Py_ISTable__GetColumn
                , ( bp::arg("colName") ) );

        }
        { //::ISTable::DeleteColumn

            typedef void ( ::ISTable::*DeleteColumn_function_type )( ::std::    string const & ) ;

            ISTable_exposer.def(
                "DeleteColumn"
                , DeleteColumn_function_type( &::ISTable::DeleteColumn )
                , ( bp::arg("colName") ) );

        }
        { //::ISTable::DeleteRows

            typedef void ( ::ISTable::*DeleteRows_function_type )( ::std::      vector< unsigned int > const & ) ;

            ISTable_exposer.def(
                "DeleteRows"
                , DeleteRows_function_type( &::ISTable::DeleteRows )
                , ( bp::arg("rows") ) );

        }
#ifdef VLAD_LATER
        { //::ISTable::AddRow
        
            typedef unsigned int ( ::ISTable::*AddRow_function_type )( ::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "AddRow"
                , AddRow_function_type( &::ISTable::AddRow )
                , ( bp::arg("row")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ISTable::ClearColumn
        
            typedef void ( ::ISTable::*ClearColumn_function_type )( ::std::string const & ) ;
            
            ISTable_exposer.def( 
                "ClearColumn"
                , ClearColumn_function_type( &::ISTable::ClearColumn )
                , ( bp::arg("colName") ) );
        
        }
#endif // VLAD_LATER
    }

}

