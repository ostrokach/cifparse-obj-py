//$$FILE$$
//$$VERSION$$
//$$DATE$$
//$$LICENSE$$


#include <string>
#include <vector> 
#include <algorithm>

#include "GenString.h"
#include "GenCont.h"


using std::string;
using std::vector;
using std::find_if;
using std::bind2nd;


GenCont::GenCont()
{

}


GenCont::~GenCont()
{

}


bool GenCont::IsInVector(const string& element,
  const vector<string>& contVector, const Char::eCompareType compareType)
{
    vector<string>::const_iterator where = find_if(contVector.begin(),
      contVector.end(), bind2nd(StringEqualTo(compareType), element));
 
    return (where != contVector.end());
}


bool GenCont::IsInVectorCi(const string& element,
  const vector<string>& contVector)
{
    return (IsInVector(element, contVector, Char::eCASE_INSENSITIVE));
}

