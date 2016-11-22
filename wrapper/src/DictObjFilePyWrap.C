#include "boost/python.hpp"

#include <string>
#include <vector>

#include "DictObjFile.h"


namespace bp = boost::python;

struct ObjContInfo_wrapper : ObjContInfo, bp::wrapper< ObjContInfo > {

    ObjContInfo_wrapper( )
    : ObjContInfo( )
      , bp::wrapper< ObjContInfo >(){
        // null constructor
    
    }

};

struct ObjCont_wrapper : ObjCont, bp::wrapper< ObjCont > {

    ObjCont_wrapper(::Serializer & ser, ::DicFile & dicFile, ::std::string const & blockName, ::std::string const & id, ::ObjContInfo const & objContInfo )
    : ObjCont( boost::ref(ser), boost::ref(dicFile), blockName, id, boost::ref(objContInfo) )
      , bp::wrapper< ObjCont >(){
        // constructor
    
    }

    virtual void Build(  ) {
        if( bp::override func_Build = this->get_override( "Build" ) )
            func_Build(  );
        else
            this->ObjCont::Build(  );
    }
    
    
    void default_Build(  ) {
        ObjCont::Build( );
    }

    virtual void BuildItems( ::std::vector< std::vector< std::string > > & combo, unsigned int const configIndex ){
        if( bp::override func_BuildItems = this->get_override( "BuildItems" ) )
            func_BuildItems( boost::ref(combo), configIndex );
        else
            this->ObjCont::BuildItems( boost::ref(combo), configIndex );
    }

    void BuildItems( ::std::vector< std::vector< std::string > > & combo, unsigned int const configIndex, ::std::string const & value ){
        ObjCont::BuildItems( boost::ref(combo), configIndex, value );
    }

    virtual void Read( ::UInt32 which, unsigned int Index=0 ) {
        if( bp::override func_Read = this->get_override( "Read" ) )
            func_Read( which, Index );
        else
            this->ObjCont::Read( which, Index );
    }
    
    
    void default_Read( ::UInt32 which, unsigned int Index=0 ) {
        ObjCont::Read( which, Index );
    }

    virtual ::UInt32 Write(  ) {
        if( bp::override func_Write = this->get_override( "Write" ) )
            return func_Write(  );
        else
            return this->ObjCont::Write(  );
    }
    
    
    ::UInt32 default_Write(  ) {
        return ObjCont::Write( );
    }

};


struct DictObjCont_wrapper : DictObjCont, bp::wrapper< DictObjCont > {

    DictObjCont_wrapper(::Serializer & ser, ::DicFile & dicFile, ::std::string const & blockName )
    : DictObjCont( boost::ref(ser), boost::ref(dicFile), blockName )
      , bp::wrapper< DictObjCont >(){
        // constructor
    
    }

    virtual void Build(  ) {
        if( bp::override func_Build = this->get_override( "Build" ) )
            func_Build(  );
        else
            this->DictObjCont::Build(  );
    }
    
    
    void default_Build(  ) {
        DictObjCont::Build( );
    }

    virtual void Read( ::UInt32 which, unsigned int Index=0 ) {
        if( bp::override func_Read = this->get_override( "Read" ) )
            func_Read( which, Index );
        else
            this->DictObjCont::Read( which, Index );
    }
    
    
    void default_Read( ::UInt32 which, unsigned int Index=0 ) {
        DictObjCont::Read( which, Index );
    }

    virtual ::UInt32 Write(  ) {
        if( bp::override func_Write = this->get_override( "Write" ) )
            return func_Write(  );
        else
            return this->DictObjCont::Write(  );
    }
    
    
    ::UInt32 default_Write(  ) {
        return DictObjCont::Write( );
    }

};


void InitDictObjFilePyWrapper()
{

#ifdef VLAD_DELETED
    { //::ObjContInfo
        typedef bp::class_< ObjContInfo_wrapper, boost::noncopyable > ObjContInfo_exposer_t;
        ObjContInfo_exposer_t ObjContInfo_exposer = ObjContInfo_exposer_t( "ObjContInfo", bp::no_init );
        bp::scope ObjContInfo_scope( ObjContInfo_exposer );
        bp::class_< ObjContInfo::Cat >( "Cat" )    
            .def_readwrite( "catName", &ObjContInfo::Cat::catName )    
            .def_readwrite( "col1", &ObjContInfo::Cat::col1 )    
            .def_readwrite( "inheritance", &ObjContInfo::Cat::inheritance )    
            .def_readwrite( "items", &ObjContInfo::Cat::items )    
            .def_readwrite( "nonDefaultValue", &ObjContInfo::Cat::nonDefaultValue );
        bp::class_< ObjContInfo::Item >( "Item" )    
            .def_readwrite( "descr", &ObjContInfo::Item::descr )    
            .def_readwrite( "itemName", &ObjContInfo::Item::itemName );
        ObjContInfo_exposer.def( bp::init< >() );
        { //::ObjContInfo::AddCat
        
            typedef void ( ::ObjContInfo::*AddCat_function_type )( ::std::string const & ) ;
            
            ObjContInfo_exposer.def( 
                "AddCat"
                , AddCat_function_type( &::ObjContInfo::AddCat )
                , ( bp::arg("catName") ) );
        
        }
        { //::ObjContInfo::AddCat
        
            typedef void ( ::ObjContInfo::*AddCat_function_type )( ::std::string const &,::std::string const &,bool const,bool const ) ;
            
            ObjContInfo_exposer.def( 
                "AddCat"
                , AddCat_function_type( &::ObjContInfo::AddCat )
                , ( bp::arg("catName"), bp::arg("col1"), bp::arg("nonDefaultValue")=(bool const)(false), bp::arg("inheritance")=(bool const)(false) ) );
        
        }
        { //::ObjContInfo::AddItem
        
            typedef void ( ::ObjContInfo::*AddItem_function_type )( ::std::string const &,::std::string const & ) ;
            
            ObjContInfo_exposer.def( 
                "AddItem"
                , AddItem_function_type( &::ObjContInfo::AddItem )
                , ( bp::arg("descr"), bp::arg("itemName") ) );
        
        }
        { //::ObjContInfo::GetItemIndex
        
            typedef unsigned int ( ::ObjContInfo::*GetItemIndex_function_type )( ::std::string const &,::std::string const & ) const;
            
            ObjContInfo_exposer.def( 
                "GetItemIndex"
                , GetItemIndex_function_type( &::ObjContInfo::GetItemIndex )
                , ( bp::arg("catName"), bp::arg("itemName") ) );
        
        }
        { //::ObjContInfo::GetItemIndices
        
            typedef ::std::pair< unsigned int, unsigned int > ( ::ObjContInfo::*GetItemIndices_function_type )( ::std::string const &,::std::string const & ) const;
            
            ObjContInfo_exposer.def( 
                "GetItemIndices"
                , GetItemIndices_function_type( &::ObjContInfo::GetItemIndices )
                , ( bp::arg("catName"), bp::arg("itemName") ) );
        
        }
        ObjContInfo_exposer.def_readwrite( "_catMap", &ObjContInfo::_catMap );
        ObjContInfo_exposer.def_readwrite( "_cats", &ObjContInfo::_cats );
        ObjContInfo_exposer.def_readwrite( "_objContInfoDescr", &ObjContInfo::_objContInfoDescr );
    }
#endif

    bp::class_< ObjCont_wrapper, boost::noncopyable >( "ObjCont", bp::init< Serializer &, DicFile &, std::string const &, std::string const &, ObjContInfo const & >(( bp::arg("ser"), bp::arg("dicFile"), bp::arg("blockName"), bp::arg("id"), bp::arg("objContInfo") )) )    
        .def( 
            "Build"
            , (void ( ::ObjCont::* )(  ) )(&::ObjCont::Build)
            , (void ( ObjCont_wrapper::* )(  ) )(&ObjCont_wrapper::default_Build) )    
        .def( 
            "BuildItems"
            , (void ( ObjCont_wrapper::* )( ::std::vector< std::vector< std::string > > &,unsigned int const ) )(&ObjCont_wrapper::BuildItems)
            , ( bp::arg("combo"), bp::arg("configIndex") ) )    
        .def( 
            "BuildItems"
            , (void ( ObjCont_wrapper::* )( ::std::vector<std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > >,std::allocator<std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > > > &,unsigned int const,::std::string const & ) )(&ObjCont_wrapper::BuildItems)
            , ( bp::arg("combo"), bp::arg("configIndex"), bp::arg("value") ) )    
        .def( 
            "GetAttribute"
            , (::std::vector< std::string > const & ( ::ObjCont::* )( ::std::string const &,::std::string const & ) const)( &::ObjCont::GetAttribute )
            , ( bp::arg("catName"), bp::arg("itemName") )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "GetName"
            , (::std::string const & ( ::ObjCont::* )(  ) const)( &::ObjCont::GetName )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "Init"
            , (void ( ::ObjCont::* )(  ) )( &::ObjCont::Init ) )    
        .def( 
            "Print"
            , (void ( ::ObjCont::* )(  ) const)( &::ObjCont::Print ) )    
        .def( 
            "Read"
            , (void ( ::ObjCont::* )( ::UInt32,unsigned int ) )(&::ObjCont::Read)
            , (void ( ObjCont_wrapper::* )( ::UInt32,unsigned int ) )(&ObjCont_wrapper::default_Read)
            , ( bp::arg("which"), bp::arg("Index")=(unsigned int)(0) ) )    
        .def( 
            "SetVerbose"
            , (void ( ::ObjCont::* )( bool ) )( &::ObjCont::SetVerbose )
            , ( bp::arg("verbose") ) )    
        .def( 
            "Write"
            , (::UInt32 ( ::ObjCont::* )(  ) )(&::ObjCont::Write)
            , (::UInt32 ( ObjCont_wrapper::* )(  ) )(&ObjCont_wrapper::default_Write) );

    bp::class_< DictObjCont_wrapper, bp::bases< ObjCont >, boost::noncopyable >( "DictObjCont", bp::init< Serializer &, DicFile &, std::string const & >(( bp::arg("ser"), bp::arg("dicFile"), bp::arg("blockName") )) )    
        .def( 
            "Build"
            , (void ( ::DictObjCont::* )(  ) )(&::DictObjCont::Build)
            , (void ( DictObjCont_wrapper::* )(  ) )(&DictObjCont_wrapper::default_Build) )    
        .def( 
            "Print"
            , (void ( ::DictObjCont::* )(  ) )( &::DictObjCont::Print ) )    
        .def( 
            "Read"
            , (void ( ::DictObjCont::* )( ::UInt32,unsigned int ) )(&::DictObjCont::Read)
            , (void ( DictObjCont_wrapper::* )( ::UInt32,unsigned int ) )(&DictObjCont_wrapper::default_Read)
            , ( bp::arg("which"), bp::arg("Index")=(unsigned int)(0) ) )    
        .def( 
            "Write"
            , (::UInt32 ( ::DictObjCont::* )(  ) )(&::DictObjCont::Write)
            , (::UInt32 ( DictObjCont_wrapper::* )(  ) )(&DictObjCont_wrapper::default_Write) );


    bp::class_< DictObjFile, boost::noncopyable >( "DictObjFile", bp::init< std::string const &, bp::optional< eFileMode, bool, std::string const & > >(( bp::arg("persStorFileName"), bp::arg("fileMode")=::READ_MODE, bp::arg("verbose")=(bool const)(false), bp::arg("dictSdbFileName")=std::basic_string<char, std::char_traits<char>, std::allocator<char> >() )) )    
        .def( 
            "Build"
            , (void ( ::DictObjFile::* )(  ) )( &::DictObjFile::Build ) )    
        .def( 
            "GetDictObjCont"
            , (::DictObjCont & ( ::DictObjFile::* )( ::std::string const & ) )( &::DictObjFile::GetDictObjCont )
            , ( bp::arg("dictName") )
                , bp::return_internal_reference<>() )    
#ifdef VLAD_LATER
        .def( 
            "GetDictionaryNames"
            , (void ( ::DictObjFile::* )( ::std::vector< std::string > & ) )( &::DictObjFile::GetDictionaryNames )
            , ( bp::arg("dictNames") ) )    
#endif
        .def( 
            "GetNumDictionaries"
            , (unsigned int ( ::DictObjFile::* )(  ) )( &::DictObjFile::GetNumDictionaries ) )    
        .def( 
            "Print"
            , (void ( ::DictObjFile::* )(  ) )( &::DictObjFile::Print ) )    
        .def( 
            "Read"
            , (void ( ::DictObjFile::* )(  ) )( &::DictObjFile::Read ) )    
        .def( 
            "Write"
            , (void ( ::DictObjFile::* )(  ) )( &::DictObjFile::Write ) );

}

