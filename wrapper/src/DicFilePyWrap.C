#include "boost/python.hpp"

#include <string>
#include <vector>

#include "DicFile.h"
#include "CifFileUtil.h"


namespace bp = boost::python;


#ifdef VLAD_DELETED
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

    }


    // CifFile accessors
    { //::ParseCif
    
        typedef ::CifFile * ( *ParseCif_function_type )( ::std::string const &,bool const );
        
        bp::def( 
            "ParseCif"
            , ParseCif_function_type( &::ParseCif )
            , ( bp::arg("fileName"), bp::arg("verbose")=(bool const)(false) )
            , bp::return_value_policy<bp::manage_new_object>() );
    
    }
}
#endif // DELETED


struct DicFile_wrapper : DicFile, bp::wrapper< DicFile > {

    DicFile_wrapper(DicFile const & arg )
    : DicFile( arg )
      , bp::wrapper< DicFile >(){
        // copy constructor
        
    }

    DicFile_wrapper(::eFileMode const fileMode, ::std::string const & objFileName, bool const verbose=false, ::Char::eCompareType const caseSense=::Char::eCASE_SENSITIVE, unsigned int const maxLineLength=CifFile::STD_CIF_LINE_LENGTH, ::std::string const & nullValue=CifString::UnknownValue )
    : DicFile( fileMode, objFileName, verbose, caseSense, maxLineLength, nullValue )
      , bp::wrapper< DicFile >(){
        // constructor
    
    }

    DicFile_wrapper(bool const verbose=false, ::Char::eCompareType const caseSense=::Char::eCASE_SENSITIVE, unsigned int const maxLineLength=CifFile::STD_CIF_LINE_LENGTH, ::std::string const & nullValue=CifString::UnknownValue )
    : DicFile( verbose, caseSense, maxLineLength, nullValue )
      , bp::wrapper< DicFile >(){
        // constructor
    
    }

    int WriteFormatted( ::std::ostream & cifo, ::ISTable * formatP ){
        return DicFile::WriteFormatted( boost::ref(cifo), boost::python::ptr(formatP) );
    }

    int WriteFormatted( ::std::ostream & cifo, ::TableFile * ddl, ::ISTable * formatP ){
        return DicFile::WriteFormatted( boost::ref(cifo), boost::python::ptr(ddl), boost::python::ptr(formatP) );
    }

    void WriteItemAliases( ::std::ostream & cifo ){
        DicFile::WriteItemAliases( boost::ref(cifo) );
    }

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

};

void InitDicFilePyWrapper()
{
    bp::class_< DicFile_wrapper, bp::bases< CifFile > >( "DicFile", bp::init< eFileMode, std::string const &, bp::optional< bool, Char::eCompareType, unsigned int, std::string const & > >(( bp::arg("fileMode"), bp::arg("objFileName"), bp::arg("verbose")=(bool const)(false), bp::arg("caseSense")=::Char::eCASE_SENSITIVE, bp::arg("maxLineLength")=(unsigned int const)(CifFile::STD_CIF_LINE_LENGTH), bp::arg("nullValue")=CifString::UnknownValue )) )    
        .def( bp::init< bp::optional< bool, Char::eCompareType, unsigned int, std::string const & > >(( bp::arg("verbose")=(bool const)(false), bp::arg("caseSense")=::Char::eCASE_SENSITIVE, bp::arg("maxLineLength")=(unsigned int const)(CifFile::STD_CIF_LINE_LENGTH), bp::arg("nullValue")=CifString::UnknownValue )) )    
#ifdef VLAD_DEL
        .def( 
            "Compress"
            , (void ( ::DicFile::* )( ::CifFile * ) )( &::DicFile::Compress )
            , ( bp::arg("ddl") ) )    
        .def( 
            "GetFormatTable"
            , (::ISTable * ( ::DicFile::* )(  ) )( &::DicFile::GetFormatTable )
                /* undefined call policies */ )    
        .def( 
            "GetRefFile"
            , (::CifFile * ( ::DicFile::* )(  ) )( &::DicFile::GetRefFile )
                /* undefined call policies */ )    
        .def( 
            "WriteFormatted"
            , (int ( ::DicFile::* )( ::std::string const &,::ISTable * ) )( &::DicFile::WriteFormatted )
            , ( bp::arg("cifFileName"), bp::arg("formatP")=0l ) )    
        .def( 
            "WriteFormatted"
            , (int ( ::DicFile::* )( ::std::string const &,::TableFile *,::ISTable * ) )( &::DicFile::WriteFormatted )
            , ( bp::arg("cifFileName"), bp::arg("ddl"), bp::arg("formatP")=0l ) )    
        .def( 
            "WriteFormatted"
            , (int ( DicFile_wrapper::* )( ::std::ostream &,::ISTable * ) )(&DicFile_wrapper::WriteFormatted)
            , ( bp::arg("cifo"), bp::arg("formatP") ) )    
        .def( 
            "WriteFormatted"
            , (int ( DicFile_wrapper::* )( ::std::ostream &,::TableFile *,::ISTable * ) )(&DicFile_wrapper::WriteFormatted)
            , ( bp::arg("cifo"), bp::arg("ddl"), bp::arg("formatP") ) )    
        .def( 
            "WriteItemAliases"
            , (void ( ::DicFile::* )( ::std::string const & ) )( &::DicFile::WriteItemAliases )
            , ( bp::arg("fileName") ) )    
        .def( 
            "WriteItemAliases"
            , (void ( DicFile_wrapper::* )( ::std::ostream & ) )(&DicFile_wrapper::WriteItemAliases)
            , ( bp::arg("cifo") ) )    
        .def( 
            "Write"
            , (void ( ::CifFile::* )( ::std::string const &,bool const,bool const ) )( &::CifFile::Write )
            , ( bp::arg("cifFileName"), bp::arg("sortTables")=(bool const)(false), bp::arg("writeEmptyTables")=(bool const)(false) ) )    
        .def( 
            "Write"
            , (void ( ::CifFile::* )( ::std::string const &,::std::vector< std::string > const &,bool const ) )( &::CifFile::Write )
            , ( bp::arg("cifFileName"), bp::arg("tableOrder"), bp::arg("writeEmptyTables")=(bool const)(false) ) )    
        .def( 
            "Write"
            , (void ( ::CifFile::* )( ::std::ostream &,bool const,bool const ) )( &::CifFile::Write )
            , ( bp::arg("outStream"), bp::arg("sortTables")=(bool const)(false), bp::arg("writeEmptyTables")=(bool const)(false) ) )    
        .def( 
            "Write"
            , (void ( DicFile_wrapper::* )( ::std::ostream &,::std::vector<std::string, std::allocator<std::string> > const &,bool const ) )(&DicFile_wrapper::Write)
            , ( bp::arg("cifo"), bp::arg("catOrder"), bp::arg("writeEmptyTables")=(bool const)(false) ) )    
        .def( 
            "Write"
            , (void ( DicFile_wrapper::* )( ::std::ostream &,::std::vector<unsigned int, std::allocator<unsigned int> > &,bool const ) )(&DicFile_wrapper::Write)
            , ( bp::arg("cifo"), bp::arg("tables"), bp::arg("writeEmptyTables")=(bool const)(false) ) )    
        .def( 
            "_IsQuotableText"
            , (int ( DicFile_wrapper::* )( ::std::string const & ) )(&DicFile_wrapper::_IsQuotableText)
            , ( bp::arg("itemValue") ) )    
        .def( 
            "_PrintHeaderedItems"
            , (void ( DicFile_wrapper::* )( ::std::ostream &,::std::vector<std::string, std::allocator<std::string> > const &,::std::vector<unsigned int, std::allocator<unsigned int> > const &,::std::vector<CifFile::eIdentType,std::allocator<CifFile::eIdentType> > const ) )(&DicFile_wrapper::_PrintHeaderedItems)
            , ( bp::arg("cifo"), bp::arg("colNames"), bp::arg("colWidths"), bp::arg("colPrintType") ) )    
        .def( 
            "_PrintItemIdent"
            , (void ( DicFile_wrapper::* )( ::std::ostream &,unsigned int & ) )(&DicFile_wrapper::_PrintItemIdent)
            , ( bp::arg("cifo"), bp::arg("linePos") ) )    
        .def( 
            "_PrintItemName"
            , (void ( DicFile_wrapper::* )( ::std::ostream &,::std::string const &,::std::string const &,unsigned int & ) )(&DicFile_wrapper::_PrintItemName)
            , ( bp::arg("cifo"), bp::arg("category"), bp::arg("itemName"), bp::arg("linePos") ) )    
        .def( 
            "_PrintPostItemSeparator"
            , (void ( DicFile_wrapper::* )( ::std::ostream &,unsigned int &,bool const,unsigned int const ) )(&DicFile_wrapper::_PrintPostItemSeparator)
            , ( bp::arg("cifo"), bp::arg("linePos"), bp::arg("ident")=(bool const)(false), bp::arg("numSpaces")=(unsigned int const)(1) ) )
#endif
;

   { //::GetDictFile
    
        typedef ::DicFile * ( *GetDictFile_function_type )( ::DicFile *,::std::string const &,::std::string const &,bool const,::eFileMode const );
        
        bp::def( 
            "GetDictFile"
            , GetDictFile_function_type( &::GetDictFile )
            , ( bp::arg("ddlFileP"), bp::arg("dictFileName"), bp::arg("dictSdbFileName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >(), bp::arg("verbose")=(bool const)(false), bp::arg("fileMode")=::READ_MODE )
                , bp::return_value_policy<bp::manage_new_object>() );
    
    }

    { //::CheckDict
    
        typedef void ( *CheckDict_function_type )( ::DicFile *,::DicFile *,::std::string const &,bool const );
        
        bp::def( 
            "CheckDict"
            , CheckDict_function_type( &::CheckDict )
            , ( bp::arg("dictFileP"), bp::arg("ddlFileP"), bp::arg("dictFileName"), bp::arg("extraChecks")=(bool const)(false) ) );
    
    }

}
