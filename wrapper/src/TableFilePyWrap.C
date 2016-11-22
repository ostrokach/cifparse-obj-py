#include "boost/python.hpp"

#include <string>
#include <vector>

#include "ISTable.h"
#include "TableFile.h"


namespace bp = boost::python;


#ifndef VLAD_PYTHON_GLUE
vector<string> Py_TableFile__GetBlockNames(TableFile& tableFile)
{
    vector<string> blockNames;
    tableFile.GetBlockNames(blockNames);
    return(blockNames);
}
#endif


#ifndef VLAD_PYTHON_GLUE
vector<string> Py_Block__GetTableNames(Block& block)
{
    vector<string> tableNames;
    block.GetTableNames(tableNames);
    return(tableNames);
}
#endif


struct TableFile_wrapper : TableFile, bp::wrapper< TableFile > {

    TableFile_wrapper(TableFile const & arg )
    : TableFile( arg )
      , bp::wrapper< TableFile >(){
        // copy constructor
        
    }

    TableFile_wrapper(::Char::eCompareType const caseSense=::Char::eCASE_SENSITIVE )
    : TableFile( caseSense )
      , bp::wrapper< TableFile >(){
        // constructor
    
    }

    TableFile_wrapper(::eFileMode const fileMode, ::std::string const & fileName, ::Char::eCompareType const caseSense=::Char::eCASE_SENSITIVE )
    : TableFile( fileMode, fileName, caseSense )
      , bp::wrapper< TableFile >(){
        // constructor
    
    }

    void GetSortedTablesIndices( ::std::vector< unsigned int > & tablesIndices ){
        TableFile::GetSortedTablesIndices( boost::ref(tablesIndices) );
    }

    void GetTableNames( ::std::vector< std::string > & tableNames ){
        TableFile::GetTableNames( boost::ref(tableNames) );
    }

    void GetTablesIndices( ::std::vector< unsigned int > & tablesIndices ){
        TableFile::GetTablesIndices( boost::ref(tablesIndices) );
    }

    unsigned int GetTotalNumTables(  ){
        return TableFile::GetTotalNumTables(  );
    }

    void _AddBlock( ::std::string const & blockName, ::Serializer * serP ){
        TableFile::_AddBlock( blockName, boost::python::ptr(serP) );
    }

    void _GetAllTables(  ){
        TableFile::_GetAllTables(  );
    }

    void _GetNumTablesInBlocks( ::std::vector< unsigned int > & numTablesInBlocks ){
        TableFile::_GetNumTablesInBlocks( boost::ref(numTablesInBlocks) );
    }

    ::ISTable * _GetTablePtr( unsigned int const blockIndex, unsigned int const tableIndex ){
        return TableFile::_GetTablePtr( blockIndex, tableIndex );
    }

    void _ReadFileIndex(  ){
        TableFile::_ReadFileIndex(  );
    }

    void _ReadFileIndexVersion0(  ){
        TableFile::_ReadFileIndexVersion0(  );
    }

    void _ReadFileIndexVersion1(  ){
        TableFile::_ReadFileIndexVersion1(  );
    }

    void _SetStatusInd( ::std::string const & blockName ){
        TableFile::_SetStatusInd( blockName );
    }

    void _WriteFileIndex( ::Serializer * serP, ::std::vector< unsigned int > const & tableLocs ){
        TableFile::_WriteFileIndex( boost::python::ptr(serP), boost::ref(tableLocs) );
    }

};


void InitTableFilePyWrapper()
{
    bp::class_< Block, boost::noncopyable >( "Block", bp::init< std::string const &, Serializer *, bp::optional< eFileMode, Char::eCompareType > >(( bp::arg("name"), bp::arg("serP"), bp::arg("fileMode")=::READ_MODE, bp::arg("caseSense")=::Char::eCASE_SENSITIVE )) )    
        .def( 
            "AddTable"
            , (::ISTable & ( ::Block::* )( ::std::string const &,::Char::eCompareType const ) )( &::Block::AddTable )
            , ( bp::arg("name")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >(), bp::arg("colCaseSense")=::Char::eCASE_SENSITIVE )
            , bp::return_internal_reference<>() )    
        .def( 
            "DeleteTable"
            , (void ( ::Block::* )( ::std::string const & ) )( &::Block::DeleteTable )
            , ( bp::arg("tableName") ) )    
        .def( 
            "GetName"
            , (::std::string const & ( ::Block::* )(  ) const)( &::Block::GetName )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "GetTableNames"
            , &::Py_Block__GetTableNames )
        .def( 
            "GetTable"
            , (::ISTable & ( ::Block::* )( ::std::string const & ) )( &::Block::GetTable )
            , ( bp::arg("tableName") )
            , bp::return_internal_reference<>() )    
        .def( 
            "IsTablePresent"
            , (bool ( ::Block::* )( ::std::string const & ) )( &::Block::IsTablePresent )
            , ( bp::arg("tableName") ) )    
        .def( 
            "Print"
            , (void ( ::Block::* )(  ) )( &::Block::Print ) )    
        .def( 
            "RenameTable"
            , (void ( ::Block::* )( ::std::string const &,::std::string const & ) )( &::Block::RenameTable )
            , ( bp::arg("oldName"), bp::arg("newName") ) )    
        .def( 
            "SetName"
            , (void ( ::Block::* )( ::std::string const & ) )( &::Block::SetName )
            , ( bp::arg("name") ) )    
        .def( 
            "WriteTable"
            , (void ( ::Block::* )( ::ISTable * ) )( &::Block::WriteTable )
            , ( bp::arg("isTableP") ) )    
#ifdef VLAD_DEL
        .def( bp::self == bp::self )    
#endif
        .def_readwrite( "_tables", &Block::_tables );

    { //::TableFile
        typedef bp::class_< TableFile_wrapper > TableFile_exposer_t;
        TableFile_exposer_t TableFile_exposer = TableFile_exposer_t( "TableFile", bp::init< bp::optional< Char::eCompareType > >(( bp::arg("caseSense")=::Char::eCASE_SENSITIVE )) );
        bp::scope TableFile_scope( TableFile_exposer );
        bp::enum_< TableFile::eStatusInd>("eStatusInd")
            .value("eCLEAR_STATUS", TableFile::eCLEAR_STATUS)
            .value("eDUPLICATE_BLOCKS", TableFile::eDUPLICATE_BLOCKS)
            .value("eUNNAMED_BLOCKS", TableFile::eUNNAMED_BLOCKS)
            .export_values()
            ;
        bp::implicitly_convertible< Char::eCompareType const, TableFile >();
        TableFile_exposer.def( bp::init< eFileMode, std::string const &, bp::optional< Char::eCompareType > >(( bp::arg("fileMode"), bp::arg("fileName"), bp::arg("caseSense")=::Char::eCASE_SENSITIVE )) );
        
        { //::TableFile::GetNumBlocks
        
            typedef unsigned int ( ::TableFile::*GetNumBlocks_function_type )(  ) ;
            
            TableFile_exposer.def( 
                "GetNumBlocks"
                , GetNumBlocks_function_type( &::TableFile::GetNumBlocks ) );
        
        }
        { //::TableFile::IsBlockPresent
        
            typedef bool ( ::TableFile::*IsBlockPresent_function_type )( ::std::string const & ) ;
            
            TableFile_exposer.def( 
                "IsBlockPresent"
                , IsBlockPresent_function_type( &::TableFile::IsBlockPresent )
                , ( bp::arg("blockName") ) );
        
        }
        { //::TableFile::GetBlockNames
        
            TableFile_exposer.def( 
                "GetBlockNames"
                , &::Py_TableFile__GetBlockNames );

        }

        { //::TableFile::GetFirstBlockName
        
            typedef ::std::string ( ::TableFile::*GetFirstBlockName_function_type )(  ) ;
            
            TableFile_exposer.def( 
                "GetFirstBlockName"
                , GetFirstBlockName_function_type( &::TableFile::GetFirstBlockName ) );
        
        }

        { //::TableFile::GetBlock
        
            typedef ::Block & ( ::TableFile::*GetBlock_function_type )( ::std::string const & ) ;
            
            TableFile_exposer.def( 
                "GetBlock"
                , GetBlock_function_type( &::TableFile::GetBlock )
                , ( bp::arg("blockName") )
                , bp::return_internal_reference<>() );
        
        }
        { //::TableFile::AddBlock
        
            typedef ::std::string ( ::TableFile::*AddBlock_function_type )( ::std::string const & ) ;
            
            TableFile_exposer.def( 
                "AddBlock"
                , AddBlock_function_type( &::TableFile::AddBlock )
                , ( bp::arg("blockName") ) );
        
        }
        { //::TableFile::RenameBlock
        
            typedef ::std::string ( ::TableFile::*RenameBlock_function_type )( ::std::string const &,::std::string const & ) ;
            
            TableFile_exposer.def( 
                "RenameBlock"
                , RenameBlock_function_type( &::TableFile::RenameBlock )
                , ( bp::arg("oldBlockName"), bp::arg("newBlockName") ) );
        
        }
        { //::TableFile::RenameFirstBlock
        
            typedef ::std::string ( ::TableFile::*RenameFirstBlock_function_type )( ::std::string const & ) ;
            
            TableFile_exposer.def( 
                "RenameFirstBlock"
                , RenameFirstBlock_function_type( &::TableFile::RenameFirstBlock )
                , ( bp::arg("newBlockName") ) );
        
        }
        { //::TableFile::Serialize
        
            typedef void ( ::TableFile::*Serialize_function_type )( ::std::string const & ) ;
            
            TableFile_exposer.def( 
                "Serialize"
                , Serialize_function_type( &::TableFile::Serialize )
                , ( bp::arg("fileName") ) );
        
        }
    }
}

