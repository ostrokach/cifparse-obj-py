#include "boost/python.hpp"

#include <string>
#include <vector>

#include "CifDataInfo.h"


namespace bp = boost::python;


struct CifDataInfo_wrapper : CifDataInfo, bp::wrapper< CifDataInfo > {

    CifDataInfo_wrapper(CifDataInfo const & arg )
    : CifDataInfo( arg )
      , bp::wrapper< CifDataInfo >(){
        // copy constructor
        
    }

    CifDataInfo_wrapper(::DicFile & dictFile )
    : CifDataInfo( boost::ref(dictFile) )
      , bp::wrapper< CifDataInfo >(){
        // constructor
    
    }

    virtual void GetCatItemsNames( ::std::vector< std::string > & itemsNames, ::std::string const & catName ) {
        if( bp::override func_GetCatItemsNames = this->get_override( "GetCatItemsNames" ) )
            func_GetCatItemsNames( boost::ref(itemsNames), catName );
        else
            this->CifDataInfo::GetCatItemsNames( boost::ref(itemsNames), catName );
    }
    
    
    void default_GetCatItemsNames( ::std::vector< std::string > & itemsNames, ::std::string const & catName ) {
        CifDataInfo::GetCatItemsNames( boost::ref(itemsNames), catName );
    }

    virtual void GetVersion( ::std::string & version ) {
        if( bp::override func_GetVersion = this->get_override( "GetVersion" ) )
            func_GetVersion( version );
        else
            this->CifDataInfo::GetVersion( version );
    }
    
    
    void default_GetVersion( ::std::string & version ) {
        CifDataInfo::GetVersion( version );
    }

    virtual bool IsCatDefined( ::std::string const & catName ) const  {
        if( bp::override func_IsCatDefined = this->get_override( "IsCatDefined" ) )
            return func_IsCatDefined( catName );
        else
            return this->CifDataInfo::IsCatDefined( catName );
    }
    
    
    bool default_IsCatDefined( ::std::string const & catName ) const  {
        return CifDataInfo::IsCatDefined( catName );
    }

    virtual bool IsItemDefined( ::std::string const & itemName ) {
        if( bp::override func_IsItemDefined = this->get_override( "IsItemDefined" ) )
            return func_IsItemDefined( itemName );
        else
            return this->CifDataInfo::IsItemDefined( itemName );
    }
    
    
    bool default_IsItemDefined( ::std::string const & itemName ) {
        return CifDataInfo::IsItemDefined( itemName );
    }

    virtual bool AreAllKeyItems( ::std::string const & catName, ::std::vector< std::string > const & attribsNames ) {
        if( bp::override func_AreAllKeyItems = this->get_override( "AreAllKeyItems" ) )
            return func_AreAllKeyItems( catName, boost::ref(attribsNames) );
        else
            return this->DataInfo::AreAllKeyItems( catName, boost::ref(attribsNames) );
    }
    
    
    bool default_AreAllKeyItems( ::std::string const & catName, ::std::vector< std::string > const & attribsNames ) {
        return DataInfo::AreAllKeyItems( catName, boost::ref(attribsNames) );
    }

    virtual void GetItemsTypes( ::std::vector< eTypeCode > & attribsTypes, ::std::string const & catName, ::std::vector< std::string > const & attribsNames ) {
        if( bp::override func_GetItemsTypes = this->get_override( "GetItemsTypes" ) )
            func_GetItemsTypes( boost::ref(attribsTypes), catName, boost::ref(attribsNames) );
        else
            this->DataInfo::GetItemsTypes( boost::ref(attribsTypes), catName, boost::ref(attribsNames) );
    }
    
    
    void default_GetItemsTypes( ::std::vector< eTypeCode > & attribsTypes, ::std::string const & catName, ::std::vector< std::string > const & attribsNames ) {
        DataInfo::GetItemsTypes( boost::ref(attribsTypes), catName, boost::ref(attribsNames) );
    }

    virtual bool IsItemMandatory( ::std::string const & itemName ) {
        if( bp::override func_IsItemMandatory = this->get_override( "IsItemMandatory" ) )
            return func_IsItemMandatory( itemName );
        else
            return this->DataInfo::IsItemMandatory( itemName );
    }
    
    
    bool default_IsItemMandatory( ::std::string const & itemName ) {
        return DataInfo::IsItemMandatory( itemName );
    }

    virtual bool IsKeyItem( ::std::string const & catName, ::std::string const & attribName, ::Char::eCompareType const compareType=::Char::eCASE_SENSITIVE ) {
        if( bp::override func_IsKeyItem = this->get_override( "IsKeyItem" ) )
            return func_IsKeyItem( catName, attribName, compareType );
        else
            return this->DataInfo::IsKeyItem( catName, attribName, compareType );
    }
    
    
    bool default_IsKeyItem( ::std::string const & catName, ::std::string const & attribName, ::Char::eCompareType const compareType=::Char::eCASE_SENSITIVE ) {
        return DataInfo::IsKeyItem( catName, attribName, compareType );
    }

    virtual bool IsSimpleDataType( ::std::string const & itemName ) {
        if( bp::override func_IsSimpleDataType = this->get_override( "IsSimpleDataType" ) )
            return func_IsSimpleDataType( itemName );
        else
            return this->DataInfo::IsSimpleDataType( itemName );
    }
    
    
    bool default_IsSimpleDataType( ::std::string const & itemName ) {
        return DataInfo::IsSimpleDataType( itemName );
    }

    virtual bool IsUnknownValueAllowed( ::std::string const & catName, ::std::string const & attribName ) {
        if( bp::override func_IsUnknownValueAllowed = this->get_override( "IsUnknownValueAllowed" ) )
            return func_IsUnknownValueAllowed( catName, attribName );
        else
            return this->DataInfo::IsUnknownValueAllowed( catName, attribName );
    }
    
    
    bool default_IsUnknownValueAllowed( ::std::string const & catName, ::std::string const & attribName ) {
        return DataInfo::IsUnknownValueAllowed( catName, attribName );
    }

    virtual bool MustConvertItem( ::std::string const & catName, ::std::string const & attribName ) {
        if( bp::override func_MustConvertItem = this->get_override( "MustConvertItem" ) )
            return func_MustConvertItem( catName, attribName );
        else
            return this->DataInfo::MustConvertItem( catName, attribName );
    }
    
    
    bool default_MustConvertItem( ::std::string const & catName, ::std::string const & attribName ) {
        return DataInfo::MustConvertItem( catName, attribName );
    }

    virtual void StandardizeEnumItem( ::std::string & value, ::std::string const & catName, ::std::string const & attribName ) {
        if( bp::override func_StandardizeEnumItem = this->get_override( "StandardizeEnumItem" ) )
            func_StandardizeEnumItem( value, catName, attribName );
        else
            this->DataInfo::StandardizeEnumItem( value, catName, attribName );
    }
    
    
    void default_StandardizeEnumItem( ::std::string & value, ::std::string const & catName, ::std::string const & attribName ) {
        DataInfo::StandardizeEnumItem( value, catName, attribName );
    }

    virtual ::eTypeCode _GetDataType( ::std::string const & itemName ) {
        if( bp::override func__GetDataType = this->get_override( "_GetDataType" ) )
            return func__GetDataType( itemName );
        else
            return this->DataInfo::_GetDataType( itemName );
    }
    
    
    ::eTypeCode default__GetDataType( ::std::string const & itemName ) {
        return DataInfo::_GetDataType( itemName );
    }

};


void InitCifDataInfoPyWrapper()
{
    { //::CifDataInfo
        typedef bp::class_< CifDataInfo_wrapper, bp::bases< DataInfo > > CifDataInfo_exposer_t;
        CifDataInfo_exposer_t CifDataInfo_exposer = CifDataInfo_exposer_t( "CifDataInfo", bp::init< DicFile & >(( bp::arg("dictFile") )) );
        bp::scope CifDataInfo_scope( CifDataInfo_exposer );
        bp::implicitly_convertible< DicFile &, CifDataInfo >();
        { //::CifDataInfo::GetCatAttribute
        
            typedef ::std::vector< std::string > const & ( ::CifDataInfo::*GetCatAttribute_function_type )( ::std::string const &,::std::string const &,::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "GetCatAttribute"
                , GetCatAttribute_function_type(&::CifDataInfo::GetCatAttribute)
                , ( bp::arg("catName"), bp::arg("refCatName"), bp::arg("refAttrName") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CifDataInfo::GetCatItemsNames
        
            typedef void ( ::CifDataInfo::*GetCatItemsNames_function_type )( ::std::vector< std::string > &,::std::string const & ) ;
            typedef void ( CifDataInfo_wrapper::*default_GetCatItemsNames_function_type )( ::std::vector< std::string > &,::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "GetCatItemsNames"
                , GetCatItemsNames_function_type(&::CifDataInfo::GetCatItemsNames)
                , default_GetCatItemsNames_function_type(&CifDataInfo_wrapper::default_GetCatItemsNames)
                , ( bp::arg("itemsNames"), bp::arg("catName") ) );
        
        }
        { //::CifDataInfo::GetCatKeys
        
            typedef ::std::vector< std::string > const & ( ::CifDataInfo::*GetCatKeys_function_type )( ::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "GetCatKeys"
                , GetCatKeys_function_type(&::CifDataInfo::GetCatKeys)
                , ( bp::arg("catName") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CifDataInfo::GetCatNames
        
            typedef ::std::vector< std::string > const & ( ::CifDataInfo::*GetCatNames_function_type )(  ) ;
            
            CifDataInfo_exposer.def( 
                "GetCatNames"
                , GetCatNames_function_type(&::CifDataInfo::GetCatNames)
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CifDataInfo::GetItemAttribute
        
            typedef ::std::vector< std::string > const & ( ::CifDataInfo::*GetItemAttribute_function_type )( ::std::string const &,::std::string const &,::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "GetItemAttribute"
                , GetItemAttribute_function_type(&::CifDataInfo::GetItemAttribute)
                , ( bp::arg("itemName"), bp::arg("refCatName"), bp::arg("refAttrName") )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CifDataInfo::GetItemsNames
        
            typedef ::std::vector< std::string > const & ( ::CifDataInfo::*GetItemsNames_function_type )(  ) ;
            
            CifDataInfo_exposer.def( 
                "GetItemsNames"
                , GetItemsNames_function_type(&::CifDataInfo::GetItemsNames)
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CifDataInfo::GetVersion
        
            typedef void ( ::CifDataInfo::*GetVersion_function_type )( ::std::string & ) ;
            typedef void ( CifDataInfo_wrapper::*default_GetVersion_function_type )( ::std::string & ) ;
            
            CifDataInfo_exposer.def( 
                "GetVersion"
                , GetVersion_function_type(&::CifDataInfo::GetVersion)
                , default_GetVersion_function_type(&CifDataInfo_wrapper::default_GetVersion)
                , ( bp::arg("version") ) );
        
        }
        { //::CifDataInfo::IsCatDefined
        
            typedef bool ( ::CifDataInfo::*IsCatDefined_function_type )( ::std::string const & ) const;
            typedef bool ( CifDataInfo_wrapper::*default_IsCatDefined_function_type )( ::std::string const & ) const;
            
            CifDataInfo_exposer.def( 
                "IsCatDefined"
                , IsCatDefined_function_type(&::CifDataInfo::IsCatDefined)
                , default_IsCatDefined_function_type(&CifDataInfo_wrapper::default_IsCatDefined)
                , ( bp::arg("catName") ) );
        
        }
        { //::CifDataInfo::IsItemDefined
        
            typedef bool ( ::CifDataInfo::*IsItemDefined_function_type )( ::std::string const & ) ;
            typedef bool ( CifDataInfo_wrapper::*default_IsItemDefined_function_type )( ::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "IsItemDefined"
                , IsItemDefined_function_type(&::CifDataInfo::IsItemDefined)
                , default_IsItemDefined_function_type(&CifDataInfo_wrapper::default_IsItemDefined)
                , ( bp::arg("itemName") ) );
        
        }
        { //::DataInfo::AreAllKeyItems
        
            typedef bool ( ::DataInfo::*AreAllKeyItems_function_type )( ::std::string const &,::std::vector< std::string > const & ) ;
            typedef bool ( CifDataInfo_wrapper::*default_AreAllKeyItems_function_type )( ::std::string const &,::std::vector< std::string > const & ) ;
            
            CifDataInfo_exposer.def( 
                "AreAllKeyItems"
                , AreAllKeyItems_function_type(&::DataInfo::AreAllKeyItems)
                , default_AreAllKeyItems_function_type(&CifDataInfo_wrapper::default_AreAllKeyItems)
                , ( bp::arg("catName"), bp::arg("attribsNames") ) );
        
        }
        { //::DataInfo::GetItemsTypes
        
            typedef void ( ::DataInfo::*GetItemsTypes_function_type )( ::std::vector< eTypeCode > &,::std::string const &,::std::vector< std::string > const & ) ;
            typedef void ( CifDataInfo_wrapper::*default_GetItemsTypes_function_type )( ::std::vector< eTypeCode > &,::std::string const &,::std::vector< std::string > const & ) ;
            
            CifDataInfo_exposer.def( 
                "GetItemsTypes"
                , GetItemsTypes_function_type(&::DataInfo::GetItemsTypes)
                , default_GetItemsTypes_function_type(&CifDataInfo_wrapper::default_GetItemsTypes)
                , ( bp::arg("attribsTypes"), bp::arg("catName"), bp::arg("attribsNames") ) );
        
        }
        { //::DataInfo::IsItemMandatory
        
            typedef bool ( ::DataInfo::*IsItemMandatory_function_type )( ::std::string const &,::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "IsItemMandatory"
                , IsItemMandatory_function_type( &::DataInfo::IsItemMandatory )
                , ( bp::arg("catName"), bp::arg("attribName") ) );
        
        }
        { //::DataInfo::IsItemMandatory
        
            typedef bool ( ::DataInfo::*IsItemMandatory_function_type )( ::std::string const & ) ;
            typedef bool ( CifDataInfo_wrapper::*default_IsItemMandatory_function_type )( ::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "IsItemMandatory"
                , IsItemMandatory_function_type(&::DataInfo::IsItemMandatory)
                , default_IsItemMandatory_function_type(&CifDataInfo_wrapper::default_IsItemMandatory)
                , ( bp::arg("itemName") ) );
        
        }
        { //::DataInfo::IsKeyItem
        
            typedef bool ( ::DataInfo::*IsKeyItem_function_type )( ::std::string const &,::std::string const &,::Char::eCompareType const ) ;
            typedef bool ( CifDataInfo_wrapper::*default_IsKeyItem_function_type )( ::std::string const &,::std::string const &,::Char::eCompareType const ) ;
            
            CifDataInfo_exposer.def( 
                "IsKeyItem"
                , IsKeyItem_function_type(&::DataInfo::IsKeyItem)
                , default_IsKeyItem_function_type(&CifDataInfo_wrapper::default_IsKeyItem)
                , ( bp::arg("catName"), bp::arg("attribName"), bp::arg("compareType")=::Char::eCASE_SENSITIVE ) );
        
        }
        { //::DataInfo::IsSimpleDataType
        
            typedef bool ( ::DataInfo::*IsSimpleDataType_function_type )( ::std::string const & ) ;
            typedef bool ( CifDataInfo_wrapper::*default_IsSimpleDataType_function_type )( ::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "IsSimpleDataType"
                , IsSimpleDataType_function_type(&::DataInfo::IsSimpleDataType)
                , default_IsSimpleDataType_function_type(&CifDataInfo_wrapper::default_IsSimpleDataType)
                , ( bp::arg("itemName") ) );
        
        }
        { //::DataInfo::IsUnknownValueAllowed
        
            typedef bool ( ::DataInfo::*IsUnknownValueAllowed_function_type )( ::std::string const &,::std::string const & ) ;
            typedef bool ( CifDataInfo_wrapper::*default_IsUnknownValueAllowed_function_type )( ::std::string const &,::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "IsUnknownValueAllowed"
                , IsUnknownValueAllowed_function_type(&::DataInfo::IsUnknownValueAllowed)
                , default_IsUnknownValueAllowed_function_type(&CifDataInfo_wrapper::default_IsUnknownValueAllowed)
                , ( bp::arg("catName"), bp::arg("attribName") ) );
        
        }
        { //::DataInfo::MustConvertItem
        
            typedef bool ( ::DataInfo::*MustConvertItem_function_type )( ::std::string const &,::std::string const & ) ;
            typedef bool ( CifDataInfo_wrapper::*default_MustConvertItem_function_type )( ::std::string const &,::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "MustConvertItem"
                , MustConvertItem_function_type(&::DataInfo::MustConvertItem)
                , default_MustConvertItem_function_type(&CifDataInfo_wrapper::default_MustConvertItem)
                , ( bp::arg("catName"), bp::arg("attribName") ) );
        
        }
        { //::DataInfo::StandardizeEnumItem
        
            typedef void ( ::DataInfo::*StandardizeEnumItem_function_type )( ::std::string &,::std::string const &,::std::string const & ) ;
            typedef void ( CifDataInfo_wrapper::*default_StandardizeEnumItem_function_type )( ::std::string &,::std::string const &,::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "StandardizeEnumItem"
                , StandardizeEnumItem_function_type(&::DataInfo::StandardizeEnumItem)
                , default_StandardizeEnumItem_function_type(&CifDataInfo_wrapper::default_StandardizeEnumItem)
                , ( bp::arg("value"), bp::arg("catName"), bp::arg("attribName") ) );
        
        }
        { //::DataInfo::_GetDataType
        
            typedef ::eTypeCode ( ::DataInfo::*_GetDataType_function_type )( ::std::string const & ) ;
            typedef ::eTypeCode ( CifDataInfo_wrapper::*default__GetDataType_function_type )( ::std::string const & ) ;
            
            CifDataInfo_exposer.def( 
                "_GetDataType"
                , _GetDataType_function_type(&::DataInfo::_GetDataType)
                , default__GetDataType_function_type(&CifDataInfo_wrapper::default__GetDataType)
                , ( bp::arg("itemName") ) );
        
        }
    }

}

