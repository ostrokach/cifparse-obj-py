#ifndef _MISC_UTIL_
#define _MISC_UTIL_


#include <string>
#include <iostream>
#include <fstream>
#include <functional>

#include "CifFile.h"
#include "DataInfo.h"

#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/util/XMLString.hpp>


XERCES_CPP_NAMESPACE_USE


class StrX
{
  public:
    StrX(const XMLCh* const toTranscode)
    {
        fLocalForm = XMLString::transcode(toTranscode);
    }

    ~StrX()
    {
        delete [] fLocalForm;
    }

    const char* localForm() const
    {
        return(fLocalForm);
    }

  private:
    char* fLocalForm;

};


class IsLostChar : public std::unary_function<char, bool>
{
  public:
    bool operator() (char oneChar) const
    {
        if ((oneChar == '[') || (oneChar == ']'))
        {
            return(true);
        }

        return(false);
    }
};


inline std::ostream& operator<<(std::ostream& target, const StrX& toDump)
{

    target << toDump.localForm();
    return(target);

}


string toString(const XMLCh* toConvert);
void Error(string& err);
void DeleteFile(const string& fileName);
void ResurrectOrigItemNames(CifFile& cifFile, DataInfo& dataInfo);
void CorrectEmptyValuesOfMandatoryItems(CifFile& cifFile, DataInfo& dataInfo);

#endif
