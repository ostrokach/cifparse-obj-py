//  File:        PdbMlParserHandler.h
//  Updated:     Oct 13, 2005 J. Westbrook
//
//  Skeleton PdbMl parser example class...  
//
//


#ifndef PDBML_PARSER_HANDLER_H
#define PDBML_PARSER_HANDLER_H


#include <vector>
#include <map>

#include <xercesc/sax2/DefaultHandler.hpp>
#include <xercesc/sax2/Attributes.hpp>

#include "TableFile.h"


XERCES_CPP_NAMESPACE_USE


static const string ELEMENT_DATABLOCK      = "datablock";
static const string ATTRIBUTE_DATABLOCK    = "datablockName";
static const string TABLE_CONTAINER_SUFFIX = "Category";


class PdbMlParserHandler : public DefaultHandler
{

  public:
    PdbMlParserHandler(TableFile& tableFile);

    ~PdbMlParserHandler();

    void startElement(const XMLCh *const uri,
                      const XMLCh *const localname,
                      const XMLCh *const qname,
                      const Attributes& attrs);

    void endElement(const XMLCh *const uri, 
                    const XMLCh *const localname, 
                    const XMLCh *const qname);

#if XERCES_VERSION_MAJOR == 2 && XERCES_VERSION_MINOR == 8 &&                   XERCES_VERSION_REVISION == 0
    void characters(const XMLCh *const chars,
                    const unsigned int length);
#else
    void characters(const XMLCh *const chars,
                    const XMLSize_t length);
#endif

    void warning(const SAXParseException& exception);
    void error(const SAXParseException& exception);
    void fatalError(const SAXParseException& exception);

    void printState(const string& element);

  private:
    bool _inDataBlock;
    bool _inTable;
    bool _inRow;
    bool _inCell;

    std::vector<string> _currRowNames;
    std::vector<string> _currRowValues;

    string _currCellName;
    string _currBlockName;

    TableFile& _tableFile;
    ISTable* _isTableP;
    // VLAD IMPROVE: THINK OF STORING THE KEY COLUMN INDICES IN THE
    // ISTABLE OBJECT, BUT LEAVING THE OPTION NOT TO CREATE THE INDEX
    // EVEN IF KEY IS SPECIFIED
    vector<string> _keyColNames;

    void Clear();

    void _GetAttributes(const Attributes& attrs);
    string _GetDataBlockName(const Attributes& attrs);
    string _ExtractTableName(const string& tableContName);

    void _SaveRow();
    void _SaveTable();

    void _ErrMessage(const string& err, const string& element);

};

// Note that the above semicolon after the closing curly brace is a must,
// otherwise the code will not compile. This is probably due to the Xerces
// macro XERCES_CPP_NAMESPACE_USE that indicates using Xerces namespace.


#endif
