#include "boost/python.hpp"

#include <string>
#include <vector>

#include "CifFile.h"
#include "CifFileUtil.h"


namespace bp = boost::python;


#ifndef VLAD_PYTHON_GLUE
string Py_CifFile__GetAttributeValue(CifFile& cifFile,
  const std::string& blockName, const std::string& catName,
  const std::string& attribName)
{
    string attribValue;

    cifFile.GetAttributeValue(attribValue, blockName, catName, attribName);

    return (attribValue);
}


string Py_CifFile__GetAttributeValueIf(CifFile& cifFile,
  const std::string& blockName, const std::string& catName,
  const std::string& attribName, const std::string& condAttribName,
  const std::string& condAttribValue)
{
    string attribValue;

    cifFile.GetAttributeValueIf(attribValue, blockName, catName, attribName,
      condAttribName, condAttribValue);

    return (attribValue);
}


vector<string> Py_CifFile__GetAttributeValues(CifFile& cifFile,
  const std::string& blockName, const std::string& catName,
  const std::string& attribName)
{
    vector<string> attribValues;

    cifFile.GetAttributeValues(attribValues, blockName, catName, attribName);

    return (attribValues);
}


vector<string> Py_CifFile__GetAttributeValuesIf(CifFile& cifFile,
  const std::string& blockName, const std::string& catName,
  const std::string& attribName, const std::string& condAttribName,
  const std::string& condAttribValue)
{
    vector<string> attribValues;

    cifFile.GetAttributeValuesIf(attribValues, blockName, catName, attribName,
      condAttribName, condAttribValue);

    return (attribValues);
}
#endif


struct CifFile_wrapper : CifFile, bp::wrapper< CifFile > {

    CifFile_wrapper(::eFileMode const fileMode, ::std::string const & fileName, bool const verbose=false, ::Char::eCompareType const caseSense=::Char::eCASE_SENSITIVE, unsigned int const maxLineLength=CifFile::STD_CIF_LINE_LENGTH, ::std::string const & nullValue=CifString::UnknownValue )
    : CifFile( fileMode, fileName, verbose, caseSense, maxLineLength, nullValue )
      , bp::wrapper< CifFile >(){
        // constructor
    
    }

    CifFile_wrapper(bool const verbose=false, ::Char::eCompareType const caseSense=::Char::eCASE_SENSITIVE, unsigned int const maxLineLength=CifFile::STD_CIF_LINE_LENGTH, ::std::string const & nullValue=CifString::UnknownValue )
    : CifFile( verbose, caseSense, maxLineLength, nullValue )
      , bp::wrapper< CifFile >(){
        // constructor
    
    }

    CifFile_wrapper(CifFile const & arg )
    : CifFile( arg )
      , bp::wrapper< CifFile >(){
        // copy constructor
        
    }

#ifdef VLAD_DELETED
    void Write( ::std::ostream & cifo, ::std::vector< std::string > const & catOrder, bool const writeEmptyTables=false ){
        CifFile::Write( boost::ref(cifo), boost::ref(catOrder), writeEmptyTables );
    }

    void Write( ::std::ostream & cifo, ::std::vector< unsigned int > & tables, bool const writeEmptyTables=false ){
        CifFile::Write( boost::ref(cifo), boost::ref(tables), writeEmptyTables );
    }

    int _IsQuotableText( ::std::string const & itemValue ){
        return CifFile::_IsQuotableText( itemValue );
    }

    void _PrintHeaderedItems( ::std::ostream & cifo, ::std::vector< std::string > const & colNames, ::std::vector< unsigned int > const & colWidths, ::std::vector< CifFile::eIdentType > const colPrintType ){
        CifFile::_PrintHeaderedItems( boost::ref(cifo), boost::ref(colNames), boost::ref(colWidths), colPrintType );
    }

    void _PrintItemIdent( ::std::ostream & cifo, unsigned int & linePos ){
        CifFile::_PrintItemIdent( boost::ref(cifo), linePos );
    }

    void _PrintItemName( ::std::ostream & cifo, ::std::string const & category, ::std::string const & itemName, unsigned int & linePos ){
        CifFile::_PrintItemName( boost::ref(cifo), category, itemName, linePos );
    }

    void _PrintPostItemSeparator( ::std::ostream & cifo, unsigned int & linePos, bool const ident=false, unsigned int const numSpaces=1 ){
        CifFile::_PrintPostItemSeparator( boost::ref(cifo), linePos, ident, numSpaces );
    }
#endif

};


void InitCifFilePyWrapper()
{
    { //::CifFile
        typedef bp::class_< CifFile_wrapper, bp::bases<TableFile> > CifFile_exposer_t;
        CifFile_exposer_t CifFile_exposer = CifFile_exposer_t( "CifFile", bp::init< eFileMode, std::string const &, bp::optional< bool, Char::eCompareType, unsigned int, std::string const & > >(( bp::arg("fileMode"), bp::arg("fileName"), bp::arg("verbose")=(bool const)(false), bp::arg("caseSense")=::Char::eCASE_SENSITIVE, bp::arg("maxLineLength")=(unsigned int const)(CifFile::STD_CIF_LINE_LENGTH), bp::arg("nullValue")=CifString::UnknownValue )) );
        bp::scope CifFile_scope( CifFile_exposer );
        bp::enum_< CifFile::eQuoting>("eQuoting")
            .value("eSINGLE", CifFile::eSINGLE)
            .value("eDOUBLE", CifFile::eDOUBLE)
            .export_values()
            ;
        CifFile_exposer.def( bp::init< bp::optional< bool, Char::eCompareType, unsigned int, std::string const & > >(( bp::arg("verbose")=(bool const)(false), bp::arg("caseSense")=::Char::eCASE_SENSITIVE, bp::arg("maxLineLength")=(unsigned int const)(CifFile::STD_CIF_LINE_LENGTH), bp::arg("nullValue")=CifString::UnknownValue )) );

        { //::CifFile::Write
        
            typedef void ( ::CifFile::*Write_function_type )( ::std::string const &,bool const,bool const ) ;
            
            CifFile_exposer.def( 
                "Write"
                , Write_function_type( &::CifFile::Write )
                , ( bp::arg("cifFileName"), bp::arg("sortTables")=(bool const)(false), bp::arg("writeEmptyTables")=(bool const)(false) ) );
        
        }
        { //::CifFile::GetSrcFileName
        
            typedef ::std::string const & ( ::CifFile::*GetSrcFileName_function_type )(  ) ;
            
            CifFile_exposer.def( 
                "GetSrcFileName"
                , GetSrcFileName_function_type( &::CifFile::GetSrcFileName )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CifFile::GetParsingDiags
        
            typedef ::std::string const & ( ::CifFile::*GetParsingDiags_function_type )(  ) ;
            
            CifFile_exposer.def( 
                "GetParsingDiags"
                , GetParsingDiags_function_type( &::CifFile::GetParsingDiags )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CifFile::GetAttributeValue
        
            typedef void ( ::CifFile::*GetAttributeValue_function_type )( ::std::string &,::std::string const &,::std::string const &,::std::string const & ) ;
            
            CifFile_exposer.def( 
                "GetAttributeValue"
                , &::Py_CifFile__GetAttributeValue
#ifdef VLAD_DEL
                , GetAttributeValue_function_type( &::CifFile::GetAttributeValue )
                , ( bp::arg("attribVal"), bp::arg("blockId"), bp::arg("category"), bp::arg("attribute") )
#endif
                 );
        
        }
        { //::CifFile::GetAttributeValueIf
        
            typedef void ( ::CifFile::*GetAttributeValueIf_function_type )( ::std::string &,::std::string const &,::std::string const &,::std::string const &,::std::string const &,::std::string const & ) ;
            
            CifFile_exposer.def( 
                "GetAttributeValueIf"
                , &::Py_CifFile__GetAttributeValueIf
#ifdef VLAD_DEL
                , GetAttributeValueIf_function_type( &::CifFile::GetAttributeValueIf )
                , ( bp::arg("attribVal"), bp::arg("blockId"), bp::arg("category"), bp::arg("attributeA"), bp::arg("attributeB"), bp::arg("valB") )
#endif
                 );
        
        }
        { //::CifFile::GetAttributeValues
        
            typedef void ( ::CifFile::*GetAttributeValues_function_type )( ::std::vector< std::string > &,::std::string const &,::std::string const &,::std::string const & ) ;
            
            CifFile_exposer.def( 
                "GetAttributeValues"
                , &::Py_CifFile__GetAttributeValues
#ifdef VLAD_DEL
                , GetAttributeValues_function_type( &::CifFile::GetAttributeValues )
                , ( bp::arg("strings"), bp::arg("blockId"), bp::arg("category"), bp::arg("attribute") )
#endif
                );
        
        }
        { //::CifFile::GetAttributeValuesIf
        
            typedef void ( ::CifFile::*GetAttributeValuesIf_function_type )( ::std::vector< std::string > &,::std::string const &,::std::string const &,::std::string const &,::std::string const &,::std::string const & ) ;
            
            CifFile_exposer.def( 
                "GetAttributeValuesIf"
                , &::Py_CifFile__GetAttributeValuesIf
#ifdef VLAD_DEL
                , GetAttributeValuesIf_function_type( &::CifFile::GetAttributeValuesIf )
                , ( bp::arg("strings"), bp::arg("blockId"), bp::arg("category"), bp::arg("attributeA"), bp::arg("attributeB"), bp::arg("valB") )
#endif
                 );
        
        }
        { //::CifFile::IsAttributeValueDefined
        
            typedef bool ( ::CifFile::*IsAttributeValueDefined_function_type )( ::std::string const &,::std::string const &,::std::string const & ) ;
            
            CifFile_exposer.def( 
                "IsAttributeValueDefined"
                , IsAttributeValueDefined_function_type( &::CifFile::IsAttributeValueDefined )
                , ( bp::arg("blockId"), bp::arg("category"), bp::arg("attribute") ) );
        
        }
        { //::CifFile::SetAttributeValue
        
            typedef void ( ::CifFile::*SetAttributeValue_function_type )( ::std::string const &,::std::string const &,::std::string const &,::std::string const &,bool const ) ;
            
            CifFile_exposer.def( 
                "SetAttributeValue"
                , SetAttributeValue_function_type( &::CifFile::SetAttributeValue )
                , ( bp::arg("blockId"), bp::arg("category"), bp::arg("attribute"), bp::arg("value"), bp::arg("create")=(bool const)(false) ) );
        
        }
        { //::CifFile::SetAttributeValueIf
        
            typedef void ( ::CifFile::*SetAttributeValueIf_function_type )( ::std::string const &,::std::string const &,::std::string const &,::std::string const &,::std::string const &,::std::string const &,bool const ) ;
            
            CifFile_exposer.def( 
                "SetAttributeValueIf"
                , SetAttributeValueIf_function_type( &::CifFile::SetAttributeValueIf )
                , ( bp::arg("blockId"), bp::arg("category"), bp::arg("attributeA"), bp::arg("valA"), bp::arg("attributeB"), bp::arg("valB"), bp::arg("create")=(bool const)(false) ) );
        
        }
        { //::CifFile::SetAttributeValueIfNull
        
            typedef void ( ::CifFile::*SetAttributeValueIfNull_function_type )( ::std::string const &,::std::string const &,::std::string const &,::std::string const & ) ;
            
            CifFile_exposer.def( 
                "SetAttributeValueIfNull"
                , SetAttributeValueIfNull_function_type( &::CifFile::SetAttributeValueIfNull )
                , ( bp::arg("blockId"), bp::arg("category"), bp::arg("attribute"), bp::arg("value") ) );
        
        }
        { //::CifFile::SetAttributeValues
        
            typedef void ( ::CifFile::*SetAttributeValues_function_type )( ::std::string const &,::std::string const &,::std::string const &,::std::vector< std::string > const & ) ;
            
            CifFile_exposer.def( 
                "SetAttributeValues"
                , SetAttributeValues_function_type( &::CifFile::SetAttributeValues )
                , ( bp::arg("blockId"), bp::arg("category"), bp::arg("attribute"), bp::arg("values") ) );
        
        }

    }


    // CifFile accessors
    { //::ParseCif
    
        typedef ::CifFile * ( *ParseCif_function_type )( ::std::string const &,bool const,::Char::eCompareType const,unsigned int const,::std::string const &,::std::string const & );
        
        bp::def( 
            "ParseCif"
            , ParseCif_function_type( &::ParseCif )
            , ( bp::arg("fileName"), bp::arg("verbose")=(bool const)(false), bp::arg("caseSense")=::Char::eCASE_SENSITIVE, bp::arg("maxLineLength")=(unsigned int const)(CifFile::STD_CIF_LINE_LENGTH), bp::arg("nullValue")=CifString::UnknownValue, bp::arg("parseLogFileName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() )
            , bp::return_value_policy<bp::manage_new_object>() );
    
    }

    { //::CheckCif
    
        typedef void ( *CheckCif_function_type )( ::CifFile *,::DicFile *,::std::string const &,bool const );
        
        bp::def( 
            "CheckCif"
            , CheckCif_function_type( &::CheckCif )
            , ( bp::arg("cifFileP"), bp::arg("dictFileP"), bp::arg("cifFileName"), bp::arg("extraCifChecks")=(bool const)(false) ) );
    
    }

}

