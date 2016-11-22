#include <string>

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/TransService.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>

#include "CifFile.h"
#include "DataInfo.h"

#include "misc_util.h"
#include "PdbMlParserHandler.h"


using namespace std;
XERCES_CPP_NAMESPACE_USE


CifFile* ParsePdbMl(const string& fileName, DataInfo& dataInfo, 
  const bool verbose)
{
    try
    {
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch)
    {
        string err("Error in PdbMlParser [main() method]: Error during"\
          " SAX2 initialization! :\n");
        err += toString(toCatch.getMessage());
        err += ".\n\n";

        Error(err);

        throw InvalidStateException(err, "ParsePdbMl()");
    }

    try
    {
        CifFile* cifFileP = new CifFile(verbose);

        PdbMlParserHandler tHandler(*cifFileP);

        SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();

        parser->setContentHandler(&tHandler);
        parser->setErrorHandler(&tHandler);

        cout << fileName << endl;
        parser->parse(fileName.c_str());
        cout << fileName << endl;

        int errorCount = 0;
        errorCount = parser->getErrorCount();

        if (errorCount > 0)
        {
            throw InvalidStateException("errorCount is " +
              String::IntToString(errorCount), "ParsePdbMl()");
        }

        // Resurrect original item names
        ResurrectOrigItemNames(*cifFileP, dataInfo);

        CorrectEmptyValuesOfMandatoryItems(*cifFileP, dataInfo);

        delete parser;

        XMLPlatformUtils::Terminate();

        return (cifFileP);
    }
    catch (const XMLException& toCatch)
    {
        string err("Error in PdbMlParser [main() method]: A SAX2 error"\
          " occurred:\n");
        err += toString(toCatch.getMessage());
        err += ".\n\n";

        Error(err);

        XMLPlatformUtils::Terminate();

        throw InvalidStateException(err, "ParsePdbMl()");
    }
} /* End of ParsePdbMl() */

