#include "boost/python.hpp"


void InitTypeCodeWrapper();
void InitStlPyWrapper();
void InitCharPyWrapper();
void InitRcsbFilePyWrapper();
void InitISTablePyWrapper();
void InitTableFilePyWrapper();
void InitCifFilePyWrapper();
void InitDicFilePyWrapper();
void InitDictObjFilePyWrapper();
void InitDataInfoPyWrapper();
void InitCifDataInfoPyWrapper();
void InitDictDataInfoPyWrapper();
void InitPdbMlFilePyWrapper();


BOOST_PYTHON_MODULE(CorePyWrap)
{
    InitTypeCodeWrapper();

    InitStlPyWrapper();

    InitCharPyWrapper();

    InitRcsbFilePyWrapper();

    InitISTablePyWrapper();

    InitTableFilePyWrapper();

    InitCifFilePyWrapper();

    InitDicFilePyWrapper();

    InitDataInfoPyWrapper();

    InitCifDataInfoPyWrapper();

    InitDictDataInfoPyWrapper();

    InitDictObjFilePyWrapper();

    InitPdbMlFilePyWrapper();
}


#ifdef VLAD_DEL_PY
BOOST_PYTHON_MODULE(pyplusplus){
    { //::std::vector< unsigned int >
        typedef bp::class_< std::vector< unsigned int > > vector_less__unsigned_int__greater__exposer_t;
        vector_less__unsigned_int__greater__exposer_t vector_less__unsigned_int__greater__exposer = vector_less__unsigned_int__greater__exposer_t( "vector_less__unsigned_int__greater_" );
        bp::scope vector_less__unsigned_int__greater__scope( vector_less__unsigned_int__greater__exposer );
        vector_less__unsigned_int__greater__exposer.def( bp::vector_indexing_suite< ::std::vector< unsigned int >, true >() );
    }

    { //::std::vector< std::string >
        typedef bp::class_< std::vector< std::string > > vector_less__std_scope_string__greater__exposer_t;
        vector_less__std_scope_string__greater__exposer_t vector_less__std_scope_string__greater__exposer = vector_less__std_scope_string__greater__exposer_t( "vector_less__std_scope_string__greater_" );
        bp::scope vector_less__std_scope_string__greater__scope( vector_less__std_scope_string__greater__exposer );
        vector_less__std_scope_string__greater__exposer.def( bp::vector_indexing_suite< ::std::vector< std::string >, true >() );
    }

    { //scope begin
        typedef bp::class_< std::vector< std::pair<unsigned int, unsigned int> > > vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer_t;
        vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer_t vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer = vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer_t("vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater_");
        bp::scope vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__scope( vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer );
        //WARNING: the next line of code will not compile, because "::std::pair<unsigned int, unsigned int>" does not have operator== !
        vector_less__std_scope_pair_less_unsigned_int_comma__unsigned_int_greater___greater__exposer.def( bp::vector_indexing_suite< ::std::vector< std::pair<unsigned int, unsigned int> > >() );
    } //scope end

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
        { //::ITTable::AddColumn
        
            typedef void ( ::ITTable::*AddColumn_function_type )( ::std::string const &,::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "AddColumn"
                , AddColumn_function_type( &::ITTable::AddColumn )
                , ( bp::arg("colName"), bp::arg("col")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ITTable::AddRow
        
            typedef unsigned int ( ::ITTable::*AddRow_function_type )( ::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "AddRow"
                , AddRow_function_type( &::ITTable::AddRow )
                , ( bp::arg("row")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ITTable::AppendToColumn
        
            typedef void ( ::ITTable::*AppendToColumn_function_type )( ::std::string const &,::std::string const & ) ;
            
            ITTable_exposer.def( 
                "AppendToColumn"
                , AppendToColumn_function_type( &::ITTable::AppendToColumn )
                , ( bp::arg("colName"), bp::arg("cell") ) );
        
        }
        { //::ITTable::AppendToColumn
        
            typedef void ( ::ITTable::*AppendToColumn_function_type )( ::std::string const &,::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "AppendToColumn"
                , AppendToColumn_function_type( &::ITTable::AppendToColumn )
                , ( bp::arg("colName"), bp::arg("col") ) );
        
        }
        { //::ITTable::AppendToColumn
        
            typedef void ( ::ITTable::*AppendToColumn_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "AppendToColumn"
                , AppendToColumn_function_type( &::ITTable::AppendToColumn )
                , ( bp::arg("colIndex"), bp::arg("col") ) );
        
        }
        { //::ITTable::AppendToColumn
        
            typedef void ( ::ITTable::*AppendToColumn_function_type )( unsigned int const,::std::string const & ) ;
            
            ITTable_exposer.def( 
                "AppendToColumn"
                , AppendToColumn_function_type( &::ITTable::AppendToColumn )
                , ( bp::arg("colIndex"), bp::arg("cell") ) );
        
        }
        { //::ITTable::Clear
        
            typedef void ( ::ITTable::*Clear_function_type )(  ) ;
            
            ITTable_exposer.def( 
                "Clear"
                , Clear_function_type( &::ITTable::Clear ) );
        
        }
        { //::ITTable::ClearColumn
        
            typedef void ( ::ITTable::*ClearColumn_function_type )( ::std::string const & ) ;
            
            ITTable_exposer.def( 
                "ClearColumn"
                , ClearColumn_function_type( &::ITTable::ClearColumn )
                , ( bp::arg("colName") ) );
        
        }
        { //::ITTable::ClearColumn
        
            typedef void ( ::ITTable::*ClearColumn_function_type )( unsigned int const ) ;
            
            ITTable_exposer.def( 
                "ClearColumn"
                , ClearColumn_function_type( &::ITTable::ClearColumn )
                , ( bp::arg("colIndex") ) );
        
        }
        { //::ITTable::ClearRow
        
            typedef void ( ::ITTable::*ClearRow_function_type )( unsigned int const ) ;
            
            ITTable_exposer.def( 
                "ClearRow"
                , ClearRow_function_type( &::ITTable::ClearRow )
                , ( bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::CreateColumn
        
            typedef void ( ::ITTable::*CreateColumn_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "CreateColumn"
                , CreateColumn_function_type( &::ITTable::CreateColumn )
                , ( bp::arg("atColIndex"), bp::arg("col")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ITTable::CreateColumn
        
            typedef void ( ::ITTable::*CreateColumn_function_type )( unsigned int const,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > >,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > > ) ;
            
            ITTable_exposer.def( 
                "CreateColumn"
                , CreateColumn_function_type( &::ITTable::CreateColumn )
                , ( bp::arg("atColIndex"), bp::arg("colBeg"), bp::arg("colEnd") ) );
        
        }
        { //::ITTable::CreateIndex
        
            typedef void ( ::ITTable::*CreateIndex_function_type )( ::std::vector< unsigned int > const &,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "CreateIndex"
                , CreateIndex_function_type( &::ITTable::CreateIndex )
                , ( bp::arg("colIndices"), bp::arg("unique")=(unsigned int const)(0) ) );
        
        }
        { //::ITTable::DeleteColumn
        
            typedef void ( ::ITTable::*DeleteColumn_function_type )( ::std::string const & ) ;
            
            ITTable_exposer.def( 
                "DeleteColumn"
                , DeleteColumn_function_type( &::ITTable::DeleteColumn )
                , ( bp::arg("colName") ) );
        
        }
        { //::ITTable::DeleteColumn
        
            typedef void ( ::ITTable::*DeleteColumn_function_type )( unsigned int const ) ;
            
            ITTable_exposer.def( 
                "DeleteColumn"
                , DeleteColumn_function_type( &::ITTable::DeleteColumn )
                , ( bp::arg("colIndex") ) );
        
        }
        { //::ITTable::DeleteEntry
        
            typedef void ( ::ITTable::*DeleteEntry_function_type )( unsigned int const ) ;
            
            ITTable_exposer.def( 
                "DeleteEntry"
                , DeleteEntry_function_type( &::ITTable::DeleteEntry )
                , ( bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::DeleteIndex
        
            typedef void ( ::ITTable::*DeleteIndex_function_type )( unsigned int const ) ;
            
            ITTable_exposer.def( 
                "DeleteIndex"
                , DeleteIndex_function_type( &::ITTable::DeleteIndex )
                , ( bp::arg("indexIndex") ) );
        
        }
        { //::ITTable::DeleteIndexEntry
        
            typedef void ( ::ITTable::*DeleteIndexEntry_function_type )( unsigned int const,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "DeleteIndexEntry"
                , DeleteIndexEntry_function_type( &::ITTable::DeleteIndexEntry )
                , ( bp::arg("indexIndex"), bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::DeleteRow
        
            typedef void ( ::ITTable::*DeleteRow_function_type )( unsigned int const ) ;
            
            ITTable_exposer.def( 
                "DeleteRow"
                , DeleteRow_function_type( &::ITTable::DeleteRow )
                , ( bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::DeleteRows
        
            typedef void ( ::ITTable::*DeleteRows_function_type )( ::std::vector< unsigned int > const & ) ;
            
            ITTable_exposer.def( 
                "DeleteRows"
                , DeleteRows_function_type( &::ITTable::DeleteRows )
                , ( bp::arg("rows") ) );
        
        }
        { //::ITTable::FillColumn
        
            typedef void ( ::ITTable::*FillColumn_function_type )( ::std::string const &,::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "FillColumn"
                , FillColumn_function_type( &::ITTable::FillColumn )
                , ( bp::arg("colName"), bp::arg("col") ) );
        
        }
        { //::ITTable::FillColumn
        
            typedef void ( ::ITTable::*FillColumn_function_type )( ::std::vector< std::string > const &,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "FillColumn"
                , FillColumn_function_type( &::ITTable::FillColumn )
                , ( bp::arg("col"), bp::arg("colIndex") ) );
        
        }
        { //::ITTable::FillColumn
        
            typedef void ( ::ITTable::*FillColumn_function_type )( unsigned int const,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > >,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > > ) ;
            
            ITTable_exposer.def( 
                "FillColumn"
                , FillColumn_function_type( &::ITTable::FillColumn )
                , ( bp::arg("colIndex"), bp::arg("colBeg"), bp::arg("colEnd") ) );
        
        }
        { //::ITTable::FillRow
        
            typedef void ( ::ITTable::*FillRow_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "FillRow"
                , FillRow_function_type( &::ITTable::FillRow )
                , ( bp::arg("rowIndex"), bp::arg("row") ) );
        
        }
        { //::ITTable::FindDuplicateRows
        
            typedef void ( ::ITTable::*FindDuplicateRows_function_type )( ::std::vector< std::pair<unsigned int, unsigned int> > &,::std::vector< std::string > const &,bool const,::ITTable::eSearchDir const ) ;
            
            ITTable_exposer.def( 
                "FindDuplicateRows"
                , FindDuplicateRows_function_type( &::ITTable::FindDuplicateRows )
                , ( bp::arg("duplRows"), bp::arg("colNames"), bp::arg("keepDuplRows"), bp::arg("searchDir")=::ITTable::eFORWARD ) );
        
        }
        { //::ITTable::FindDuplicateRows
        
            typedef void ( ::ITTable::*FindDuplicateRows_function_type )( ::std::vector< unsigned int > const &,::std::vector< std::pair<unsigned int, unsigned int> > &,bool const,::ITTable::eSearchDir const ) ;
            
            ITTable_exposer.def( 
                "FindDuplicateRows"
                , FindDuplicateRows_function_type( &::ITTable::FindDuplicateRows )
                , ( bp::arg("colIndices"), bp::arg("duplRows"), bp::arg("keep"), bp::arg("searchDir")=::ITTable::eFORWARD ) );
        
        }
        { //::ITTable::FindFirst
        
            typedef unsigned int ( ::ITTable::*FindFirst_function_type )( ::std::vector< std::string > const &,::std::vector< unsigned int > const &,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "FindFirst"
                , FindFirst_function_type( &::ITTable::FindFirst )
                , ( bp::arg("targets"), bp::arg("colIndices"), bp::arg("indexIndex") ) );
        
        }
        { //::ITTable::FindIndex
        
            typedef int ( ::ITTable::*FindIndex_function_type )( ::std::vector< unsigned int > const & ) ;
            
            ITTable_exposer.def( 
                "FindIndex"
                , FindIndex_function_type( &::ITTable::FindIndex )
                , ( bp::arg("colIndices") ) );
        
        }
        { //::ITTable::GetColumn
        
            typedef void ( ::ITTable::*GetColumn_function_type )( ::std::vector< std::string > &,::std::string const & ) ;
            
            ITTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ITTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colName") ) );
        
        }
        { //::ITTable::GetColumn
        
            typedef void ( ::ITTable::*GetColumn_function_type )( ::std::vector< std::string > &,::std::string const &,unsigned int const,unsigned int ) ;
            
            ITTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ITTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colName"), bp::arg("fromRowIndex"), bp::arg("toRowIndex") ) );
        
        }
        { //::ITTable::GetColumn
        
            typedef void ( ::ITTable::*GetColumn_function_type )( ::std::vector< std::string > &,::std::string const &,::std::vector< unsigned int > const & ) ;
            
            ITTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ITTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colName"), bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::GetColumn
        
            typedef void ( ::ITTable::*GetColumn_function_type )( ::std::vector< std::string > &,unsigned int const,unsigned int const,unsigned int ) ;
            
            ITTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ITTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colIndex"), bp::arg("fromRowIndex"), bp::arg("toRowIndex") ) );
        
        }
        { //::ITTable::GetColumn
        
            typedef void ( ::ITTable::*GetColumn_function_type )( ::std::vector< std::string > &,unsigned int const,::std::vector< unsigned int > const & ) ;
            
            ITTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ITTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colIndex"), bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::GetColumn
        
            typedef void ( ::ITTable::*GetColumn_function_type )( ::std::vector< std::string > &,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ITTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colIndex") ) );
        
        }
        { //::ITTable::GetColumn
        
            typedef void ( ::ITTable::*GetColumn_function_type )( ::std::vector< std::string > &,unsigned int const,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ITTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colIndex"), bp::arg("indexIndex") ) );
        
        }
        { //::ITTable::GetDataType
        
            typedef unsigned char ( ::ITTable::*GetDataType_function_type )( ::std::string const & ) ;
            
            ITTable_exposer.def( 
                "GetDataType"
                , GetDataType_function_type( &::ITTable::GetDataType )
                , ( bp::arg("colName") ) );
        
        }
        { //::ITTable::GetLastRowIndex
        
            typedef unsigned int ( ::ITTable::*GetLastRowIndex_function_type )(  ) ;
            
            ITTable_exposer.def( 
                "GetLastRowIndex"
                , GetLastRowIndex_function_type( &::ITTable::GetLastRowIndex ) );
        
        }
        { //::ITTable::GetNumColumns
        
            typedef unsigned int ( ::ITTable::*GetNumColumns_function_type )(  ) const;
            
            ITTable_exposer.def( 
                "GetNumColumns"
                , GetNumColumns_function_type( &::ITTable::GetNumColumns ) );
        
        }
        { //::ITTable::GetNumIndices
        
            typedef unsigned int ( ::ITTable::*GetNumIndices_function_type )(  ) ;
            
            ITTable_exposer.def( 
                "GetNumIndices"
                , GetNumIndices_function_type( &::ITTable::GetNumIndices ) );
        
        }
        { //::ITTable::GetNumRows
        
            typedef unsigned int ( ::ITTable::*GetNumRows_function_type )(  ) const;
            
            ITTable_exposer.def( 
                "GetNumRows"
                , GetNumRows_function_type( &::ITTable::GetNumRows ) );
        
        }
        { //::ITTable::GetObject
        
            typedef int ( ::ITTable::*GetObject_function_type )( ::UInt32,::Serializer * ) ;
            
            ITTable_exposer.def( 
                "GetObject"
                , GetObject_function_type( &::ITTable::GetObject )
                , ( bp::arg("index"), bp::arg("ser") ) );
        
        }
        { //::ITTable::GetOrientation
        
            typedef ::ITTable::eOrientation ( ::ITTable::*GetOrientation_function_type )(  ) ;
            
            ITTable_exposer.def( 
                "GetOrientation"
                , GetOrientation_function_type( &::ITTable::GetOrientation ) );
        
        }
        { //::ITTable::GetRow
        
            typedef void ( ::ITTable::*GetRow_function_type )( ::std::vector< std::string > &,unsigned int const,::std::string const &,::std::string const & ) ;
            
            ITTable_exposer.def( 
                "GetRow"
                , GetRow_function_type( &::ITTable::GetRow )
                , ( bp::arg("row"), bp::arg("rowIndex"), bp::arg("fromColName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >(), bp::arg("toColName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() ) );
        
        }
        { //::ITTable::GetRow
        
            typedef void ( ::ITTable::*GetRow_function_type )( ::std::vector< std::string > &,unsigned int const,unsigned int const,unsigned int ) ;
            
            ITTable_exposer.def( 
                "GetRow"
                , GetRow_function_type( &::ITTable::GetRow )
                , ( bp::arg("row"), bp::arg("rowIndex"), bp::arg("fromColIndex"), bp::arg("toColIndex") ) );
        
        }
        { //::ITTable::GetRow
        
            typedef ::std::vector< std::string > const & ( ::ITTable::*GetRow_function_type )( unsigned int const ) ;
            
            ITTable_exposer.def( 
                "GetRow"
                , GetRow_function_type( &::ITTable::GetRow )
                , ( bp::arg("rowIndex") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ITTable::InsertColumn
        
            typedef void ( ::ITTable::*InsertColumn_function_type )( ::std::string const &,::std::string const &,::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "InsertColumn"
                , InsertColumn_function_type( &::ITTable::InsertColumn )
                , ( bp::arg("colName"), bp::arg("atColName"), bp::arg("col")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ITTable::InsertColumn
        
            typedef void ( ::ITTable::*InsertColumn_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "InsertColumn"
                , InsertColumn_function_type( &::ITTable::InsertColumn )
                , ( bp::arg("colIndex"), bp::arg("col")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ITTable::InsertColumn
        
            typedef void ( ::ITTable::*InsertColumn_function_type )( unsigned int const,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > >,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > > ) ;
            
            ITTable_exposer.def( 
                "InsertColumn"
                , InsertColumn_function_type( &::ITTable::InsertColumn )
                , ( bp::arg("colIndex"), bp::arg("colBeg"), bp::arg("colEnd") ) );
        
        }
        { //::ITTable::InsertEntry
        
            typedef void ( ::ITTable::*InsertEntry_function_type )( unsigned int const ) ;
            
            ITTable_exposer.def( 
                "InsertEntry"
                , InsertEntry_function_type( &::ITTable::InsertEntry )
                , ( bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::InsertIndexEntry
        
            typedef void ( ::ITTable::*InsertIndexEntry_function_type )( unsigned int const,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "InsertIndexEntry"
                , InsertIndexEntry_function_type( &::ITTable::InsertIndexEntry )
                , ( bp::arg("indexIndex"), bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::InsertRow
        
            typedef unsigned int ( ::ITTable::*InsertRow_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            ITTable_exposer.def( 
                "InsertRow"
                , InsertRow_function_type( &::ITTable::InsertRow )
                , ( bp::arg("atRowIndex"), bp::arg("row")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ITTable::Read
        
            typedef int ( ::ITTable::*Read_function_type )( unsigned int,::Serializer * ) ;
            
            ITTable_exposer.def( 
                "Read"
                , Read_function_type( &::ITTable::Read )
                , ( bp::arg("indexInFile"), bp::arg("ser") ) );
        
        }
        { //::ITTable::RebuildIndex
        
            typedef void ( ::ITTable::*RebuildIndex_function_type )( unsigned int const ) ;
            
            ITTable_exposer.def( 
                "RebuildIndex"
                , RebuildIndex_function_type( &::ITTable::RebuildIndex )
                , ( bp::arg("indexIndex") ) );
        
        }
        { //::ITTable::RebuildIndices
        
            typedef void ( ::ITTable::*RebuildIndices_function_type )(  ) ;
            
            ITTable_exposer.def( 
                "RebuildIndices"
                , RebuildIndices_function_type( &::ITTable::RebuildIndices ) );
        
        }
        { //::ITTable::Search
        
            typedef void ( ::ITTable::*Search_function_type )( ::std::vector< unsigned int > &,::std::vector< std::string > const &,::std::vector< unsigned int > const &,unsigned int const,::ITTable::eSearchType const ) ;
            
            ITTable_exposer.def( 
                "Search"
                , Search_function_type( &::ITTable::Search )
                , ( bp::arg("res"), bp::arg("targets"), bp::arg("colIndices"), bp::arg("indexIndex"), bp::arg("searchType")=::ITTable::eEQUAL ) );
        
        }
        { //::ITTable::Search
        
            typedef void ( ::ITTable::*Search_function_type )( ::std::vector< unsigned int > &,::std::string const &,unsigned int const,::ITTable::eSearchType const ) ;
            
            ITTable_exposer.def( 
                "Search"
                , Search_function_type( &::ITTable::Search )
                , ( bp::arg("res"), bp::arg("target"), bp::arg("colIndex"), bp::arg("searchType")=::ITTable::eEQUAL ) );
        
        }
        { //::ITTable::SetFlags
        
            typedef void ( ::ITTable::*SetFlags_function_type )( ::std::string const &,unsigned char const ) ;
            
            ITTable_exposer.def( 
                "SetFlags"
                , SetFlags_function_type( &::ITTable::SetFlags )
                , ( bp::arg("colName"), bp::arg("flags") ) );
        
        }
        { //::ITTable::SetFlags
        
            typedef int ( ::ITTable::*SetFlags_function_type )( unsigned char const,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "SetFlags"
                , SetFlags_function_type( &::ITTable::SetFlags )
                , ( bp::arg("newOpts"), bp::arg("colIndex") ) );
        
        }
        { //::ITTable::SetSerializer
        
            typedef void ( ::ITTable::*SetSerializer_function_type )( ::Serializer * ) ;
            
            ITTable_exposer.def( 
                "SetSerializer"
                , SetSerializer_function_type( &::ITTable::SetSerializer )
                , ( bp::arg("ser") ) );
        
        }
        { //::ITTable::UpdateCell
        
            typedef void ( ::ITTable::*UpdateCell_function_type )( unsigned int const,::std::string const &,::std::string const & ) ;
            
            ITTable_exposer.def( 
                "UpdateCell"
                , UpdateCell_function_type( &::ITTable::UpdateCell )
                , ( bp::arg("rowIndex"), bp::arg("colName"), bp::arg("value") ) );
        
        }
        { //::ITTable::UpdateCell
        
            typedef int ( ::ITTable::*UpdateCell_function_type )( ::std::string const &,unsigned int const,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "UpdateCell"
                , UpdateCell_function_type( &::ITTable::UpdateCell )
                , ( bp::arg("cell"), bp::arg("colIndex"), bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::UpdateIndex
        
            typedef void ( ::ITTable::*UpdateIndex_function_type )( unsigned int const,unsigned int const ) ;
            
            ITTable_exposer.def( 
                "UpdateIndex"
                , UpdateIndex_function_type( &::ITTable::UpdateIndex )
                , ( bp::arg("indexIndex"), bp::arg("rowIndex") ) );
        
        }
        { //::ITTable::ValidateOptions
        
            typedef void ( ::ITTable::*ValidateOptions_function_type )( unsigned int ) ;
            
            ITTable_exposer.def( 
                "ValidateOptions"
                , ValidateOptions_function_type( &::ITTable::ValidateOptions )
                , ( bp::arg("colIndex") ) );
        
        }
        { //::ITTable::VerifyColumnsIndices
        
            typedef void ( ::ITTable::*VerifyColumnsIndices_function_type )( ::std::vector< unsigned int > const & ) ;
            
            ITTable_exposer.def( 
                "VerifyColumnsIndices"
                , VerifyColumnsIndices_function_type( &::ITTable::VerifyColumnsIndices )
                , ( bp::arg("colIndices") ) );
        
        }
        { //::ITTable::Write
        
            typedef int ( ::ITTable::*Write_function_type )( ::Serializer *,int & ) ;
            
            ITTable_exposer.def( 
                "Write"
                , Write_function_type( &::ITTable::Write )
                , ( bp::arg("ser"), bp::arg("size") ) );
        
        }
        { //::ITTable::WriteObject
        
            typedef int ( ::ITTable::*WriteObject_function_type )( ::Serializer *,int & ) ;
            
            ITTable_exposer.def( 
                "WriteObject"
                , WriteObject_function_type( &::ITTable::WriteObject )
                , ( bp::arg("ser"), bp::arg("size") ) );
        
        }
        { //::ITTable::operator()
        
            typedef ::std::string const & ( ::ITTable::*__call___function_type )( unsigned int const,::std::string const & ) const;
            
            ITTable_exposer.def( 
                "__call__"
                , __call___function_type( &::ITTable::operator() )
                , ( bp::arg("rowIndex"), bp::arg("colName") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ITTable::operator()
        
            typedef ::std::string const & ( ::ITTable::*__call___function_type )( unsigned int const,unsigned int const ) const;
            
            ITTable_exposer.def( 
                "__call__"
                , __call___function_type( &::ITTable::operator() )
                , ( bp::arg("rowIndex"), bp::arg("colIndex") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ITTable::operator=
        
            typedef ::ITTable & ( ::ITTable::*assign_function_type )( ::ITTable const & ) ;
            
            ITTable_exposer.def( 
                "assign"
                , assign_function_type( &::ITTable::operator= )
                , ( bp::arg("inTable") )
                , bp::return_self< >() );
        
        }
        ITTable_exposer.def_readonly( "CASE_INSENSE", ITTable::CASE_INSENSE );
        ITTable_exposer.def_readonly( "CASE_SENSE", ITTable::CASE_SENSE );
        ITTable_exposer.def_readonly( "DT_INTEGER", ITTable::DT_INTEGER );
        ITTable_exposer.def_readonly( "DT_INTEGER_VAL", ITTable::DT_INTEGER_VAL );
        ITTable_exposer.def_readonly( "DT_STRING", ITTable::DT_STRING );
        ITTable_exposer.def_readonly( "DT_STRING_VAL", ITTable::DT_STRING_VAL );
        ITTable_exposer.def_readonly( "W_SPACE_INSENSE", ITTable::W_SPACE_INSENSE );
        ITTable_exposer.def_readonly( "W_SPACE_SENSE", ITTable::W_SPACE_SENSE );
        ITTable_exposer.def( bp::self_ns::str( bp::self ) );
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
        { //::ISTable::AddColumn
        
            typedef void ( ::ISTable::*AddColumn_function_type )( ::std::string const &,::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "AddColumn"
                , AddColumn_function_type( &::ISTable::AddColumn )
                , ( bp::arg("colName"), bp::arg("col")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
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
        { //::ISTable::ClearRow
        
            typedef void ( ::ISTable::*ClearRow_function_type )( unsigned int const ) ;
            
            ISTable_exposer.def( 
                "ClearRow"
                , ClearRow_function_type( &::ISTable::ClearRow )
                , ( bp::arg("rowIndex") ) );
        
        }
        { //::ISTable::CreateIndex
        
            typedef void ( ::ISTable::*CreateIndex_function_type )( ::std::string const &,::std::vector< std::string > const &,unsigned int const ) ;
            
            ISTable_exposer.def( 
                "CreateIndex"
                , CreateIndex_function_type( &::ISTable::CreateIndex )
                , ( bp::arg("indexName"), bp::arg("colNames"), bp::arg("unique")=(unsigned int const)(0) ) );
        
        }
        { //::ISTable::CreateKey
        
            typedef void ( ::ISTable::*CreateKey_function_type )( ::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "CreateKey"
                , CreateKey_function_type( &::ISTable::CreateKey )
                , ( bp::arg("colNames") ) );
        
        }
        { //::ISTable::DeleteColumn
        
            typedef void ( ::ISTable::*DeleteColumn_function_type )( ::std::string const & ) ;
            
            ISTable_exposer.def( 
                "DeleteColumn"
                , DeleteColumn_function_type( &::ISTable::DeleteColumn )
                , ( bp::arg("colName") ) );
        
        }
        { //::ISTable::DeleteIndex
        
            typedef void ( ::ISTable::*DeleteIndex_function_type )( ::std::string const & ) ;
            
            ISTable_exposer.def( 
                "DeleteIndex"
                , DeleteIndex_function_type( &::ISTable::DeleteIndex )
                , ( bp::arg("indexName") ) );
        
        }
        { //::ISTable::DeleteKey
        
            typedef void ( ::ISTable::*DeleteKey_function_type )(  ) ;
            
            ISTable_exposer.def( 
                "DeleteKey"
                , DeleteKey_function_type( &::ISTable::DeleteKey ) );
        
        }
        { //::ISTable::DeleteRow
        
            typedef void ( ::ISTable::*DeleteRow_function_type )( unsigned int const ) ;
            
            ISTable_exposer.def( 
                "DeleteRow"
                , DeleteRow_function_type( &::ISTable::DeleteRow )
                , ( bp::arg("rowIndex") ) );
        
        }
        { //::ISTable::DeleteRows
        
            typedef void ( ::ISTable::*DeleteRows_function_type )( ::std::vector< unsigned int > const & ) ;
            
            ISTable_exposer.def( 
                "DeleteRows"
                , DeleteRows_function_type( &::ISTable::DeleteRows )
                , ( bp::arg("rows") ) );
        
        }
        { //::ISTable::FillColumn
        
            typedef void ( ::ISTable::*FillColumn_function_type )( ::std::string const &,::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "FillColumn"
                , FillColumn_function_type( &::ISTable::FillColumn )
                , ( bp::arg("colName"), bp::arg("col") ) );
        
        }
        { //::ISTable::FillRow
        
            typedef void ( ::ISTable::*FillRow_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "FillRow"
                , FillRow_function_type( &::ISTable::FillRow )
                , ( bp::arg("rowIndex"), bp::arg("row") ) );
        
        }
        { //::ISTable::FindDuplicateRows
        
            typedef void ( ::ISTable::*FindDuplicateRows_function_type )( ::std::vector< std::pair<unsigned int, unsigned int> > &,::std::vector< std::string > const &,bool const,::ITTable::eSearchDir const ) ;
            
            ISTable_exposer.def( 
                "FindDuplicateRows"
                , FindDuplicateRows_function_type( &::ISTable::FindDuplicateRows )
                , ( bp::arg("duplRows"), bp::arg("colNames"), bp::arg("keepDuplRows"), bp::arg("searchDir")=ISTable::eFORWARD ) );
        
        }
        { //::ISTable::FindFirst
        
            typedef unsigned int ( ::ISTable::*FindFirst_function_type )( ::std::vector< std::string > const &,::std::vector< std::string > const &,::std::string const & ) ;
            
            ISTable_exposer.def( 
                "FindFirst"
                , FindFirst_function_type( &::ISTable::FindFirst )
                , ( bp::arg("targets"), bp::arg("colNames"), bp::arg("indexName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() ) );
        
        }
        { //::ISTable::GetColCaseSense
        
            typedef ::Char::eCompareType ( ::ISTable::*GetColCaseSense_function_type )(  ) const;
            
            ISTable_exposer.def( 
                "GetColCaseSense"
                , GetColCaseSense_function_type( &::ISTable::GetColCaseSense ) );
        
        }
        { //::ISTable::GetColumn
        
            typedef void ( ::ISTable::*GetColumn_function_type )( ::std::vector< std::string > &,::std::string const & ) ;
            
            ISTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ISTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colName") ) );
        
        }
        { //::ISTable::GetColumn
        
            typedef void ( ::ISTable::*GetColumn_function_type )( ::std::vector< std::string > &,::std::string const &,unsigned int const,unsigned int ) ;
            
            ISTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ISTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colName"), bp::arg("fromRowIndex"), bp::arg("toRowIndex") ) );
        
        }
        { //::ISTable::GetColumn
        
            typedef void ( ::ISTable::*GetColumn_function_type )( ::std::vector< std::string > &,::std::string const &,::std::vector< unsigned int > const & ) ;
            
            ISTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ISTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colName"), bp::arg("rowIndex") ) );
        
        }
        { //::ISTable::GetColumn
        
            typedef void ( ::ISTable::*GetColumn_function_type )( ::std::vector< std::string > &,::std::string const &,::std::string const & ) ;
            
            ISTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::ISTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colName"), bp::arg("indexName") ) );
        
        }
        { //::ISTable::GetColumnNames
        
            typedef ::std::vector< std::string > const & ( ::ISTable::*GetColumnNames_function_type )(  ) const;
            
            ISTable_exposer.def( 
                "GetColumnNames"
                , GetColumnNames_function_type( &::ISTable::GetColumnNames )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ISTable::GetColumnsIndices
        
            typedef void ( ::ISTable::*GetColumnsIndices_function_type )( ::std::vector< unsigned int > &,::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "GetColumnsIndices"
                , GetColumnsIndices_function_type( &::ISTable::GetColumnsIndices )
                , ( bp::arg("colIndices"), bp::arg("colNames") ) );
        
        }
        { //::ISTable::GetDataType
        
            typedef unsigned char ( ::ISTable::*GetDataType_function_type )( ::std::string const & ) ;
            
            ISTable_exposer.def( 
                "GetDataType"
                , GetDataType_function_type( &::ISTable::GetDataType )
                , ( bp::arg("colName") ) );
        
        }
        { //::ISTable::GetLastRowIndex
        
            typedef unsigned int ( ::ISTable::*GetLastRowIndex_function_type )(  ) ;
            
            ISTable_exposer.def( 
                "GetLastRowIndex"
                , GetLastRowIndex_function_type( &::ISTable::GetLastRowIndex ) );
        
        }
        { //::ISTable::GetModified
        
            typedef bool ( ::ISTable::*GetModified_function_type )(  ) ;
            
            ISTable_exposer.def( 
                "GetModified"
                , GetModified_function_type( &::ISTable::GetModified ) );
        
        }
        { //::ISTable::GetName
        
            typedef ::std::string const & ( ::ISTable::*GetName_function_type )(  ) const;
            
            ISTable_exposer.def( 
                "GetName"
                , GetName_function_type( &::ISTable::GetName )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ISTable::GetNumColumns
        
            typedef unsigned int ( ::ISTable::*GetNumColumns_function_type )(  ) const;
            
            ISTable_exposer.def( 
                "GetNumColumns"
                , GetNumColumns_function_type( &::ISTable::GetNumColumns ) );
        
        }
        { //::ISTable::GetNumIndices
        
            typedef unsigned int ( ::ISTable::*GetNumIndices_function_type )(  ) ;
            
            ISTable_exposer.def( 
                "GetNumIndices"
                , GetNumIndices_function_type( &::ISTable::GetNumIndices ) );
        
        }
        { //::ISTable::GetNumRows
        
            typedef unsigned int ( ::ISTable::*GetNumRows_function_type )(  ) const;
            
            ISTable_exposer.def( 
                "GetNumRows"
                , GetNumRows_function_type( &::ISTable::GetNumRows ) );
        
        }
        { //::ISTable::GetObject
        
            typedef int ( ::ISTable::*GetObject_function_type )( ::UInt32,::Serializer * ) ;
            
            ISTable_exposer.def( 
                "GetObject"
                , GetObject_function_type( &::ISTable::GetObject )
                , ( bp::arg("index"), bp::arg("ser") ) );
        
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
        { //::ISTable::IndexExists
        
            typedef bool ( ::ISTable::*IndexExists_function_type )( ::std::string const & ) ;
            
            ISTable_exposer.def( 
                "IndexExists"
                , IndexExists_function_type( &::ISTable::IndexExists )
                , ( bp::arg("indexName") ) );
        
        }
        { //::ISTable::InsertColumn
        
            typedef void ( ::ISTable::*InsertColumn_function_type )( ::std::string const &,::std::string const &,::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "InsertColumn"
                , InsertColumn_function_type( &::ISTable::InsertColumn )
                , ( bp::arg("colName"), bp::arg("afColName"), bp::arg("col")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ISTable::InsertRow
        
            typedef unsigned int ( ::ISTable::*InsertRow_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            ISTable_exposer.def( 
                "InsertRow"
                , InsertRow_function_type( &::ISTable::InsertRow )
                , ( bp::arg("atRowIndex"), bp::arg("row")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::ISTable::IsColumnPresent
        
            typedef bool ( ::ISTable::*IsColumnPresent_function_type )( ::std::string const & ) ;
            
            ISTable_exposer.def( 
                "IsColumnPresent"
                , IsColumnPresent_function_type( &::ISTable::IsColumnPresent )
                , ( bp::arg("colName") ) );
        
        }
        { //::ISTable::Merge
        
            typedef ::ISTable * ( *Merge_function_type )( ::ISTable &,::ISTable &,unsigned int );
            
            ISTable_exposer.def( 
                "Merge"
                , Merge_function_type( &::ISTable::Merge )
                , ( bp::arg("firstTable"), bp::arg("secondTable"), bp::arg("typeOfMerge")=(unsigned int)(0) )
                    / undefined call policies / );
        
        }
        { //::ISTable::PrintDiff
        
            typedef bool ( ::ISTable::*PrintDiff_function_type )( ::ISTable & ) ;
            
            ISTable_exposer.def( 
                "PrintDiff"
                , PrintDiff_function_type( &::ISTable::PrintDiff )
                , ( bp::arg("inTable") ) );
        
        }
        { //::ISTable::Read
        
            typedef void ( ::ISTable::*Read_function_type )( unsigned int ) ;
            
            ISTable_exposer.def( 
                "Read"
                , Read_function_type( &::ISTable::Read )
                , ( bp::arg("indexInFile") ) );
        
        }
        { //::ISTable::RebuildIndex
        
            typedef void ( ::ISTable::*RebuildIndex_function_type )( ::std::string const & ) ;
            
            ISTable_exposer.def( 
                "RebuildIndex"
                , RebuildIndex_function_type( &::ISTable::RebuildIndex )
                , ( bp::arg("indexName") ) );
        
        }
        { //::ISTable::RebuildIndices
        
            typedef void ( ::ISTable::*RebuildIndices_function_type )(  ) ;
            
            ISTable_exposer.def( 
                "RebuildIndices"
                , RebuildIndices_function_type( &::ISTable::RebuildIndices ) );
        
        }
        { //::ISTable::RenameColumn
        
            typedef void ( ::ISTable::*RenameColumn_function_type )( ::std::string const &,::std::string const & ) ;
            
            ISTable_exposer.def( 
                "RenameColumn"
                , RenameColumn_function_type( &::ISTable::RenameColumn )
                , ( bp::arg("oldColName"), bp::arg("newColName") ) );
        
        }
        { //::ISTable::Search
        
            typedef void ( ::ISTable::*Search_function_type )( ::std::vector< unsigned int > &,::std::string const &,::std::string const &,unsigned int const,::ITTable::eSearchDir const,::ITTable::eSearchType const ) ;
            
            ISTable_exposer.def( 
                "Search"
                , Search_function_type( &::ISTable::Search )
                , ( bp::arg("res"), bp::arg("target"), bp::arg("colName"), bp::arg("fromRowIndex")=(unsigned int const)(0), bp::arg("searchDir")=ISTable::eFORWARD, bp::arg("searchType")=ISTable::eEQUAL ) );
        
        }
        { //::ISTable::Search
        
            typedef void ( ::ISTable::*Search_function_type )( ::std::vector< unsigned int > &,::std::vector< std::string > const &,::std::vector< std::string > const &,unsigned int const,::ITTable::eSearchDir const,::ITTable::eSearchType const,::std::string const & ) ;
            
            ISTable_exposer.def( 
                "Search"
                , Search_function_type( &::ISTable::Search )
                , ( bp::arg("res"), bp::arg("targets"), bp::arg("colNames"), bp::arg("fromRowIndex")=(unsigned int const)(0), bp::arg("searchDir")=ISTable::eFORWARD, bp::arg("searchType")=ISTable::eEQUAL, bp::arg("indexName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() ) );
        
        }
        { //::ISTable::SetFlags
        
            typedef void ( ::ISTable::*SetFlags_function_type )( ::std::string const &,unsigned char const ) ;
            
            ISTable_exposer.def( 
                "SetFlags"
                , SetFlags_function_type( &::ISTable::SetFlags )
                , ( bp::arg("colName"), bp::arg("flags") ) );
        
        }
        { //::ISTable::SetIntersect
        
            typedef void ( *SetIntersect_function_type )( ::std::vector< unsigned int > const &,::std::vector< unsigned int > const &,::std::vector< unsigned int > & );
            
            ISTable_exposer.def( 
                "SetIntersect"
                , SetIntersect_function_type( &::ISTable::SetIntersect )
                , ( bp::arg("a"), bp::arg("b"), bp::arg("ret") ) );
        
        }
        { //::ISTable::SetModified
        
            typedef void ( ::ISTable::*SetModified_function_type )( bool const ) ;
            
            ISTable_exposer.def( 
                "SetModified"
                , SetModified_function_type( &::ISTable::SetModified )
                , ( bp::arg("modified") ) );
        
        }
        { //::ISTable::SetName
        
            typedef void ( ::ISTable::*SetName_function_type )( ::std::string const & ) ;
            
            ISTable_exposer.def( 
                "SetName"
                , SetName_function_type( &::ISTable::SetName )
                , ( bp::arg("name") ) );
        
        }
        { //::ISTable::SetSerializer
        
            typedef void ( ::ISTable::*SetSerializer_function_type )( ::Serializer * ) ;
            
            ISTable_exposer.def( 
                "SetSerializer"
                , SetSerializer_function_type( &::ISTable::SetSerializer )
                , ( bp::arg("ser") ) );
        
        }
        { //::ISTable::SetUnion
        
            typedef void ( *SetUnion_function_type )( ::std::vector< unsigned int > const &,::std::vector< unsigned int > const &,::std::vector< unsigned int > & );
            
            ISTable_exposer.def( 
                "SetUnion"
                , SetUnion_function_type( &::ISTable::SetUnion )
                , ( bp::arg("a"), bp::arg("b"), bp::arg("ret") ) );
        
        }
        { //::ISTable::UpdateCell
        
            typedef void ( ::ISTable::*UpdateCell_function_type )( unsigned int const,::std::string const &,::std::string const & ) ;
            
            ISTable_exposer.def( 
                "UpdateCell"
                , UpdateCell_function_type( &::ISTable::UpdateCell )
                , ( bp::arg("rowIndex"), bp::arg("colName"), bp::arg("value") ) );
        
        }
        { //::ISTable::UpdateIndex
        
            typedef void ( ::ISTable::*UpdateIndex_function_type )( ::std::string const &,unsigned int const ) ;
            
            ISTable_exposer.def( 
                "UpdateIndex"
                , UpdateIndex_function_type( &::ISTable::UpdateIndex )
                , ( bp::arg("indexName"), bp::arg("rowIndex") ) );
        
        }
        { //::ISTable::Write
        
            typedef int ( ::ISTable::*Write_function_type )(  ) ;
            
            ISTable_exposer.def( 
                "Write"
                , Write_function_type( &::ISTable::Write ) );
        
        }
        { //::ISTable::WriteObject
        
            typedef int ( ::ISTable::*WriteObject_function_type )( ::Serializer *,int & ) ;
            
            ISTable_exposer.def( 
                "WriteObject"
                , WriteObject_function_type( &::ISTable::WriteObject )
                , ( bp::arg("ser"), bp::arg("size") ) );
        
        }
        { //::ISTable::operator()
        
            typedef ::std::string const & ( ::ISTable::*__call___function_type )( unsigned int const,::std::string const & ) const;
            
            ISTable_exposer.def( 
                "__call__"
                , __call___function_type( &::ISTable::operator() )
                , ( bp::arg("rowIndex"), bp::arg("colName") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::ISTable::operator=
        
            typedef ::ISTable & ( ::ISTable::*assign_function_type )( ::ISTable const & ) ;
            
            ISTable_exposer.def( 
                "assign"
                , assign_function_type( &::ISTable::operator= )
                , ( bp::arg("inTable") )
                , bp::return_self< >() );
        
        }
        ISTable_exposer.def( bp::self == bp::self );
        ISTable_exposer.def_readonly( "CASE_INSENSE", ISTable::CASE_INSENSE );
        ISTable_exposer.def_readonly( "CASE_SENSE", ISTable::CASE_SENSE );
        ISTable_exposer.def_readonly( "DT_INTEGER", ISTable::DT_INTEGER );
        ISTable_exposer.def_readonly( "DT_INTEGER_VAL", ISTable::DT_INTEGER_VAL );
        ISTable_exposer.def_readonly( "DT_STRING", ISTable::DT_STRING );
        ISTable_exposer.def_readonly( "DT_STRING_VAL", ISTable::DT_STRING_VAL );
        ISTable_exposer.def_readonly( "W_SPACE_INSENSE", ISTable::W_SPACE_INSENSE );
        ISTable_exposer.def_readonly( "W_SPACE_SENSE", ISTable::W_SPACE_SENSE );
        ISTable_exposer.def_readonly( "eBACKWARD", ISTable::eBACKWARD );
        ISTable_exposer.def_readonly( "eCOLUMN_WISE", ISTable::eCOLUMN_WISE );
        ISTable_exposer.def_readonly( "eEQUAL", ISTable::eEQUAL );
        ISTable_exposer.def_readonly( "eFORWARD", ISTable::eFORWARD );
        ISTable_exposer.def_readonly( "eGREATER_THAN", ISTable::eGREATER_THAN );
        ISTable_exposer.def_readonly( "eGREATER_THAN_OR_EQUAL", ISTable::eGREATER_THAN_OR_EQUAL );
        ISTable_exposer.def_readonly( "eLESS_THAN", ISTable::eLESS_THAN );
        ISTable_exposer.def_readonly( "eLESS_THAN_OR_EQUAL", ISTable::eLESS_THAN_OR_EQUAL );
        ISTable_exposer.def_readonly( "eROW_WISE", ISTable::eROW_WISE );
        ISTable_exposer.staticmethod( "Merge" );
        ISTable_exposer.staticmethod( "SetIntersect" );
        ISTable_exposer.staticmethod( "SetUnion" );
        ISTable_exposer.def( bp::self_ns::str( bp::self ) );
    }

    { //::TTable
        typedef bp::class_< TTable > TTable_exposer_t;
        TTable_exposer_t TTable_exposer = TTable_exposer_t( "TTable", bp::init< >() );
        bp::scope TTable_scope( TTable_exposer );
        TTable_exposer.def( bp::init< TTable const & >(( bp::arg("inTable") )) );
        { //::TTable::AddColumn
        
            typedef unsigned int ( ::TTable::*AddColumn_function_type )( ::std::vector< std::string > const & ) ;
            
            TTable_exposer.def( 
                "AddColumn"
                , AddColumn_function_type( &::TTable::AddColumn )
                , ( bp::arg("col")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::TTable::AddTuple
        
            typedef unsigned int ( ::TTable::*AddTuple_function_type )( ::std::vector< std::string > const & ) ;
            
            TTable_exposer.def( 
                "AddTuple"
                , AddTuple_function_type( &::TTable::AddTuple )
                , ( bp::arg("tuple")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::TTable::Clear
        
            typedef void ( ::TTable::*Clear_function_type )(  ) ;
            
            TTable_exposer.def( 
                "Clear"
                , Clear_function_type( &::TTable::Clear ) );
        
        }
        { //::TTable::ClearColumn
        
            typedef void ( ::TTable::*ClearColumn_function_type )( unsigned int const ) ;
            
            TTable_exposer.def( 
                "ClearColumn"
                , ClearColumn_function_type( &::TTable::ClearColumn )
                , ( bp::arg("colIndex") ) );
        
        }
        { //::TTable::ClearTuple
        
            typedef void ( ::TTable::*ClearTuple_function_type )( unsigned int const ) ;
            
            TTable_exposer.def( 
                "ClearTuple"
                , ClearTuple_function_type( &::TTable::ClearTuple )
                , ( bp::arg("tupleIndex") ) );
        
        }
        { //::TTable::DeleteColumn
        
            typedef void ( ::TTable::*DeleteColumn_function_type )( unsigned int const ) ;
            
            TTable_exposer.def( 
                "DeleteColumn"
                , DeleteColumn_function_type( &::TTable::DeleteColumn )
                , ( bp::arg("colIndex") ) );
        
        }
        { //::TTable::DeleteTuple
        
            typedef void ( ::TTable::*DeleteTuple_function_type )( unsigned int const ) ;
            
            TTable_exposer.def( 
                "DeleteTuple"
                , DeleteTuple_function_type( &::TTable::DeleteTuple )
                , ( bp::arg("tupleIndex") ) );
        
        }
        { //::TTable::FillColumn
        
            typedef void ( ::TTable::*FillColumn_function_type )( unsigned int const,::std::vector< std::string > const &,unsigned int const ) ;
            
            TTable_exposer.def( 
                "FillColumn"
                , FillColumn_function_type( &::TTable::FillColumn )
                , ( bp::arg("colIndex"), bp::arg("col"), bp::arg("fromTupleIndex")=(unsigned int const)(0) ) );
        
        }
        { //::TTable::FillColumn
        
            typedef void ( ::TTable::*FillColumn_function_type )( unsigned int const,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > >,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > >,unsigned int const ) ;
            
            TTable_exposer.def( 
                "FillColumn"
                , FillColumn_function_type( &::TTable::FillColumn )
                , ( bp::arg("colIndex"), bp::arg("colBeg"), bp::arg("colEnd"), bp::arg("fromTupleIndex")=(unsigned int const)(0) ) );
        
        }
        { //::TTable::FillTuple
        
            typedef void ( ::TTable::*FillTuple_function_type )( unsigned int const,::std::vector< std::string > const &,unsigned int const ) ;
            
            TTable_exposer.def( 
                "FillTuple"
                , FillTuple_function_type( &::TTable::FillTuple )
                , ( bp::arg("tupleIndex"), bp::arg("tuple"), bp::arg("fromColIndex")=(unsigned int const)(0) ) );
        
        }
        { //::TTable::GetColumn
        
            typedef void ( ::TTable::*GetColumn_function_type )( ::std::vector< std::string > &,unsigned int const,unsigned int const,unsigned int ) ;
            
            TTable_exposer.def( 
                "GetColumn"
                , GetColumn_function_type( &::TTable::GetColumn )
                , ( bp::arg("col"), bp::arg("colIndex"), bp::arg("fromTupleIndex"), bp::arg("toTupleIndex") ) );
        
        }
        { //::TTable::GetNumColumns
        
            typedef unsigned int ( ::TTable::*GetNumColumns_function_type )(  ) const;
            
            TTable_exposer.def( 
                "GetNumColumns"
                , GetNumColumns_function_type( &::TTable::GetNumColumns ) );
        
        }
        { //::TTable::GetNumTuples
        
            typedef unsigned int ( ::TTable::*GetNumTuples_function_type )(  ) const;
            
            TTable_exposer.def( 
                "GetNumTuples"
                , GetNumTuples_function_type( &::TTable::GetNumTuples ) );
        
        }
        { //::TTable::GetTuple
        
            typedef void ( ::TTable::*GetTuple_function_type )( ::std::vector< std::string > &,unsigned int const,unsigned int const,unsigned int ) ;
            
            TTable_exposer.def( 
                "GetTuple"
                , GetTuple_function_type( &::TTable::GetTuple )
                , ( bp::arg("tuple"), bp::arg("tupleIndex"), bp::arg("fromColIndex"), bp::arg("toColIndex") ) );
        
        }
        { //::TTable::GetTuple
        
            typedef ::std::vector< std::string > const & ( ::TTable::*GetTuple_function_type )( unsigned int const ) ;
            
            TTable_exposer.def( 
                "GetTuple"
                , GetTuple_function_type( &::TTable::GetTuple )
                , ( bp::arg("tupleIndex") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::TTable::InsertColumn
        
            typedef unsigned int ( ::TTable::*InsertColumn_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            TTable_exposer.def( 
                "InsertColumn"
                , InsertColumn_function_type( &::TTable::InsertColumn )
                , ( bp::arg("atColIndex"), bp::arg("col")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::TTable::InsertColumn
        
            typedef void ( ::TTable::*InsertColumn_function_type )( unsigned int const,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > >,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > > ) ;
            
            TTable_exposer.def( 
                "InsertColumn"
                , InsertColumn_function_type( &::TTable::InsertColumn )
                , ( bp::arg("atColIndex"), bp::arg("colBeg"), bp::arg("colEnd") ) );
        
        }
        { //::TTable::InsertTuple
        
            typedef void ( ::TTable::*InsertTuple_function_type )( unsigned int const,::std::vector< std::string > const & ) ;
            
            TTable_exposer.def( 
                "InsertTuple"
                , InsertTuple_function_type( &::TTable::InsertTuple )
                , ( bp::arg("tupleIndex"), bp::arg("tuple")=std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >(0ul, ((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >&)((const std::basic_string<char, std::char_traits<char>, std::allocator<char> >*)(& std::basic_string<char, std::char_traits<char>, std::allocator<char> >()))), ((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >&)((const std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >*)(& std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >())))) ) );
        
        }
        { //::TTable::InsertTuple
        
            typedef void ( ::TTable::*InsertTuple_function_type )( unsigned int const,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > >,::__gnu_cxx::__normal_iterator< const std::basic_string< char, std::char_traits< char >, std::allocator< char > >, std::vector< std::string > > ) ;
            
            TTable_exposer.def( 
                "InsertTuple"
                , InsertTuple_function_type( &::TTable::InsertTuple )
                , ( bp::arg("tupleIndex"), bp::arg("tupleBeg"), bp::arg("tupleEnd") ) );
        
        }
        { //::TTable::Read
        
            typedef int ( ::TTable::*Read_function_type )( ::UInt32,::Serializer * ) ;
            
            TTable_exposer.def( 
                "Read"
                , Read_function_type( &::TTable::Read )
                , ( bp::arg("index"), bp::arg("ser") ) );
        
        }
        { //::TTable::Write
        
            typedef int ( ::TTable::*Write_function_type )( ::Serializer *,unsigned int & ) ;
            
            TTable_exposer.def( 
                "Write"
                , Write_function_type( &::TTable::Write )
                , ( bp::arg("ser"), bp::arg("size") ) );
        
        }
        { //::TTable::operator()
        
            typedef ::std::string & ( ::TTable::*__call___function_type )( unsigned int const,unsigned int const ) ;
            
            TTable_exposer.def( 
                "__call__"
                , __call___function_type( &::TTable::operator() )
                , ( bp::arg("tupleIndex"), bp::arg("colIndex") )
                    / undefined call policies / );
        
        }
        { //::TTable::operator()
        
            typedef ::std::string const & ( ::TTable::*__call___function_type )( unsigned int const,unsigned int const ) const;
            
            TTable_exposer.def( 
                "__call__"
                , __call___function_type( &::TTable::operator() )
                , ( bp::arg("tupleIndex"), bp::arg("colIndex") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::TTable::operator=
        
            typedef ::TTable & ( ::TTable::*assign_function_type )( ::TTable const & ) ;
            
            TTable_exposer.def( 
                "assign"
                , assign_function_type( &::TTable::operator= )
                , ( bp::arg("inTable") )
                , bp::return_self< >() );
        
        }
        TTable_exposer.def( bp::self_ns::str( bp::self ) );
    }

    bp::scope().attr("ADD_UPDATE_NULL") = ADD_UPDATE_NULL;

    bp::scope().attr("ASSERT_NULL_DATA_POINTER") = ASSERT_NULL_DATA_POINTER;

    bp::scope().attr("ASSERT_WARNING") = ASSERT_WARNING;

    bp::scope().attr("COLUMN_NAME_NOT_FOUND") = COLUMN_NAME_NOT_FOUND;

    bp::scope().attr("COLUMN_OUT_OF_BOUNDS") = COLUMN_OUT_OF_BOUNDS;

    bp::scope().attr("DELETED_ROW") = DELETED_ROW;

    bp::scope().attr("DOUBLE_CONVERSION_ERROR") = DOUBLE_CONVERSION_ERROR;

    bp::scope().attr("DUPLICATE_ROW") = DUPLICATE_ROW;

    bp::scope().attr("ERROR_NO_FILE_NAVIGATOR") = ERROR_NO_FILE_NAVIGATOR;

    bp::scope().attr("INDEX_CORRUPTED") = INDEX_CORRUPTED;

    bp::scope().attr("INDEX_NAME_NOT_FOUND") = INDEX_NAME_NOT_FOUND;

    bp::scope().attr("INTEGER_CONVERSION_ERROR") = INTEGER_CONVERSION_ERROR;

    bp::scope().attr("INTERNAL_INCONSISTENCY_ERROR") = INTERNAL_INCONSISTENCY_ERROR;

    bp::scope().attr("KEY_ERROR") = KEY_ERROR;

    bp::scope().attr("NEW_COLUMN_LENGTH_ZERO") = NEW_COLUMN_LENGTH_ZERO;

    bp::scope().attr("NOT_A_DATATYPE_ERROR") = NOT_A_DATATYPE_ERROR;

    bp::scope().attr("NOT_FOUND") = NOT_FOUND;

    bp::scope().attr("NO_APPROPRIATE_INDEX") = NO_APPROPRIATE_INDEX;

    bp::scope().attr("NO_TABLE_ERROR") = NO_TABLE_ERROR;

    bp::scope().attr("NO_TREE_ON_COLUMN") = NO_TREE_ON_COLUMN;

    bp::scope().attr("NULL_COMPARISON") = NULL_COMPARISON;

    bp::scope().attr("NULL_SEARCH_LIST") = NULL_SEARCH_LIST;

    bp::scope().attr("REGEX_COMPILE_FAILED") = REGEX_COMPILE_FAILED;

    bp::scope().attr("ROW_OUT_OF_BOUNDS") = ROW_OUT_OF_BOUNDS;

    bp::scope().attr("SOME_COLUMN_NAMES_NOT_FOUND") = SOME_COLUMN_NAMES_NOT_FOUND;

    bp::scope().attr("TABLE_NOT_FOUND") = TABLE_NOT_FOUND;

    bp::scope().attr("TABLE_WARNING") = TABLE_WARNING;
}
#endif
