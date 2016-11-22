#include "boost/python.hpp"

#include <string>
#include <vector>

#include "DataInfo.h"


namespace bp = boost::python;


struct DataInfo_wrapper : DataInfo, bp::wrapper< DataInfo > {

    DataInfo_wrapper( )
    : DataInfo( )
      , bp::wrapper< DataInfo >(){
        // null constructor
    
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

    virtual ::std::vector< std::string > const & GetCatAttribute( ::std::string const & catName, ::std::string const & refCatName, ::std::string const & refAttribName ){
        throw std::logic_error("warning W1049: This method could not be overriden in Python - method returns reference to local variable!");
    }

    virtual ::std::vector< std::string > const & GetCatKeys( ::std::string const & catName ){
        throw std::logic_error("warning W1049: This method could not be overriden in Python - method returns reference to local variable!");
    }

    virtual ::std::vector< std::string > const & GetCatNames(  ){
        throw std::logic_error("warning W1049: This method could not be overriden in Python - method returns reference to local variable!");
    }

    virtual ::std::vector< std::string > const & GetItemAttribute( ::std::string const & itemName, ::std::string const & refCatName, ::std::string const & refAttribName ){
        throw std::logic_error("warning W1049: This method could not be overriden in Python - method returns reference to local variable!");
    }

    virtual ::std::vector< std::string > const & GetItemsNames(  ){
        throw std::logic_error("warning W1049: This method could not be overriden in Python - method returns reference to local variable!");
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

    virtual void GetVersion( ::std::string & version ){
        bp::override func_GetVersion = this->get_override( "GetVersion" );
        func_GetVersion( version );
    }

    virtual bool IsCatDefined( ::std::string const & catName ) const {
        bp::override func_IsCatDefined = this->get_override( "IsCatDefined" );
        return func_IsCatDefined( catName );
    }

    virtual bool IsItemDefined( ::std::string const & itemName ){
        bp::override func_IsItemDefined = this->get_override( "IsItemDefined" );
        return func_IsItemDefined( itemName );
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


void InitDataInfoPyWrapper()
{
    bp::class_< DataInfo_wrapper, boost::noncopyable >( "DataInfo", bp::init< >() )    
        .def( 
            "AreAllKeyItems"
            , (bool ( ::DataInfo::* )( ::std::string const &,::std::vector< std::string > const & ) )(&::DataInfo::AreAllKeyItems)
            , (bool ( DataInfo_wrapper::* )( ::std::string const &,::std::vector< std::string > const & ) )(&DataInfo_wrapper::default_AreAllKeyItems)
            , ( bp::arg("catName"), bp::arg("attribsNames") ) )    
        .def( 
            "AreItemsValuesValid"
            , (bool ( ::DataInfo::* )( ::std::string const &,::std::vector< std::string > const &,::std::vector< unsigned int > const &,::std::vector< bool > const &,::std::vector< std::string > const &,::Char::eCompareType const ) )( &::DataInfo::AreItemsValuesValid )
            , ( bp::arg("catName"), bp::arg("attribsNames"), bp::arg("attribsIndices"), bp::arg("allowedNullAttribs"), bp::arg("values"), bp::arg("compareType")=::Char::eCASE_SENSITIVE ) )    
        .def( 
            "GetCatAttribute"
            , bp::pure_virtual( (::std::vector< std::string > const & ( ::DataInfo::* )( ::std::string const &,::std::string const &,::std::string const & ) )(&::DataInfo::GetCatAttribute) )
            , ( bp::arg("catName"), bp::arg("refCatName"), bp::arg("refAttribName") )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "GetCatKeys"
            , bp::pure_virtual( (::std::vector< std::string > const & ( ::DataInfo::* )( ::std::string const & ) )(&::DataInfo::GetCatKeys) )
            , ( bp::arg("catName") )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "GetCatNames"
            , bp::pure_virtual( (::std::vector< std::string > const & ( ::DataInfo::* )(  ) )(&::DataInfo::GetCatNames) )
            , bp::return_value_policy< bp::copy_const_reference >() )    
#ifdef VLAD_MOD
        .def( 
            "GetChildrenKeys"
            , (::std::vector< std::vector< std::vector< std::string > > > & ( ::DataInfo::* )( ::std::vector< std::string > const & ) )( &::DataInfo::GetChildrenKeys )
            , ( bp::arg("parComboKey") )
            , bp::return_value_policy< bp::copy_const_reference >() )    
                /* undefined call policies */ )    
        .def( 
            "GetComboKeys"
            , (::std::vector< std::vector< std::string > > const & ( ::DataInfo::* )( ::std::string const & ) )( &::DataInfo::GetComboKeys )
            , ( bp::arg("catName") )
            , bp::return_value_policy< bp::copy_const_reference >() )    
#endif
        .def( 
            "GetItemAttribute"
            , bp::pure_virtual( (::std::vector< std::string > const & ( ::DataInfo::* )( ::std::string const &,::std::string const &,::std::string const & ) )(&::DataInfo::GetItemAttribute) )
            , ( bp::arg("itemName"), bp::arg("refCatName"), bp::arg("refAttribName") )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "GetItemsNames"
            , bp::pure_virtual( (::std::vector< std::string > const & ( ::DataInfo::* )(  ) )(&::DataInfo::GetItemsNames) )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "GetItemsTypes"
            , (void ( ::DataInfo::* )( ::std::vector< eTypeCode > &,::std::string const &,::std::vector< std::string > const & ) )(&::DataInfo::GetItemsTypes)
            , (void ( DataInfo_wrapper::* )( ::std::vector< eTypeCode > &,::std::string const &,::std::vector< std::string > const & ) )(&DataInfo_wrapper::default_GetItemsTypes)
            , ( bp::arg("attribsTypes"), bp::arg("catName"), bp::arg("attribsNames") ) )    
        .def( 
            "GetVersion"
            , bp::pure_virtual( (void ( ::DataInfo::* )( ::std::string & ) )(&::DataInfo::GetVersion) )
            , ( bp::arg("version") ) )    
        .def( 
            "IsCatDefined"
            , bp::pure_virtual( (bool ( ::DataInfo::* )( ::std::string const & ) const)(&::DataInfo::IsCatDefined) )
            , ( bp::arg("catName") ) )    
        .def( 
            "IsItemDefined"
            , bp::pure_virtual( (bool ( ::DataInfo::* )( ::std::string const & ) )(&::DataInfo::IsItemDefined) )
            , ( bp::arg("itemName") ) )    
        .def( 
            "IsItemMandatory"
            , (bool ( ::DataInfo::* )( ::std::string const &,::std::string const & ) )( &::DataInfo::IsItemMandatory )
            , ( bp::arg("catName"), bp::arg("attribName") ) )    
        .def( 
            "IsItemMandatory"
            , (bool ( ::DataInfo::* )( ::std::string const & ) )(&::DataInfo::IsItemMandatory)
            , (bool ( DataInfo_wrapper::* )( ::std::string const & ) )(&DataInfo_wrapper::default_IsItemMandatory)
            , ( bp::arg("itemName") ) )    
        .def( 
            "IsKeyItem"
            , (bool ( ::DataInfo::* )( ::std::string const &,::std::string const &,::Char::eCompareType const ) )(&::DataInfo::IsKeyItem)
            , (bool ( DataInfo_wrapper::* )( ::std::string const &,::std::string const &,::Char::eCompareType const ) )(&DataInfo_wrapper::default_IsKeyItem)
            , ( bp::arg("catName"), bp::arg("attribName"), bp::arg("compareType")=::Char::eCASE_SENSITIVE ) )    
        .def( 
            "IsSimpleDataType"
            , (bool ( ::DataInfo::* )( ::std::string const & ) )(&::DataInfo::IsSimpleDataType)
            , (bool ( DataInfo_wrapper::* )( ::std::string const & ) )(&DataInfo_wrapper::default_IsSimpleDataType)
            , ( bp::arg("itemName") ) )    
        .def( 
            "IsUnknownValueAllowed"
            , (bool ( ::DataInfo::* )( ::std::string const &,::std::string const & ) )(&::DataInfo::IsUnknownValueAllowed)
            , (bool ( DataInfo_wrapper::* )( ::std::string const &,::std::string const & ) )(&DataInfo_wrapper::default_IsUnknownValueAllowed)
            , ( bp::arg("catName"), bp::arg("attribName") ) )    
        .def( 
            "MustConvertItem"
            , (bool ( ::DataInfo::* )( ::std::string const &,::std::string const & ) )(&::DataInfo::MustConvertItem)
            , (bool ( DataInfo_wrapper::* )( ::std::string const &,::std::string const & ) )(&DataInfo_wrapper::default_MustConvertItem)
            , ( bp::arg("catName"), bp::arg("attribName") ) )    
        .def( 
            "StandardizeEnumItem"
            , (void ( ::DataInfo::* )( ::std::string &,::std::string const &,::std::string const & ) )(&::DataInfo::StandardizeEnumItem)
            , (void ( DataInfo_wrapper::* )( ::std::string &,::std::string const &,::std::string const & ) )(&DataInfo_wrapper::default_StandardizeEnumItem)
            , ( bp::arg("value"), bp::arg("catName"), bp::arg("attribName") ) )    
        .def( 
            "_GetDataType"
            , (::eTypeCode ( ::DataInfo::* )( ::std::string const & ) )(&::DataInfo::_GetDataType)
            , (::eTypeCode ( DataInfo_wrapper::* )( ::std::string const & ) )(&DataInfo_wrapper::default__GetDataType)
            , ( bp::arg("itemName") ) );

}

