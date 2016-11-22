#include <exception>
#include <string>
#include <string.h>


#include "CifFile.h"
#include "DictObjFile.h"
#include "DictDataInfo.h"
#include "CifFileUtil.h"
#include "CifDataInfo.h"

#include "PdbMlFileUtil.h"


using std::exception;
using std::string;
using std::cerr;
using std::endl;


class CmdLineOpts
{
  public:
    string xmlFileName;
    string dictOdbFileName;
    string dictSdbFileName;
    string dictName;
    bool verbose;
    string progName;

    CmdLineOpts(int argc, char* argv[]);

    void Usage();
};


int main(int argc, char* argv[])
{
    try
    { 
        CmdLineOpts opts(argc, argv);

        CifFile* cifFileP = NULL;

        if (!opts.dictOdbFileName.empty())
        {
            DictObjFile dictObjFile(opts.dictOdbFileName);

            dictObjFile.Read();

            DictObjCont& dictObjCont =
              dictObjFile.GetDictObjCont(opts.dictName);

            DictDataInfo dictDataInfo(dictObjCont);

            cifFileP = ParsePdbMl(opts.xmlFileName, dictDataInfo, true);
        }
        else
        {
            DicFile* dictFileP = GetDictFile(NULL, string(),
              opts.dictSdbFileName);

            CifDataInfo cifDataInfo(*dictFileP);

            cifFileP = ParsePdbMl(opts.xmlFileName, cifDataInfo, true);
        }

        string cifFileName = opts.xmlFileName + ".cif";

        cifFileP->Write(cifFileName);

        delete (cifFileP);
    }
    catch (const exception& exc)
    {
        cerr << exc.what();

        return (1);
    }
} /* End of main() */


CmdLineOpts::CmdLineOpts(int argc, char* argv[])
{
    progName = argv[0];
    if (argc < 7)
    {
        Usage();
        throw InvalidOptionsException();
    }

    verbose = false;

    for (unsigned int i = 1; i < (unsigned int)argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (strcmp(argv[i], "-xml") == 0)
            {
                i++;
                xmlFileName = argv[i];
            }
            else if (strcmp(argv[i], "-df") == 0)
            {
                i++;
                dictOdbFileName = argv[i];
            }
            else if (strcmp(argv[i], "-dictSdbFile") == 0)
            {
                i++;
                dictSdbFileName = argv[i];
            }
            else if (strcmp(argv[i], "-dict") == 0)
            {
                i++;
                dictName = argv[i];
            }
            else if (strcmp(argv[i], "-v") == 0)
            {
	        verbose = true;
            }
            else
            {
                Usage();
                throw InvalidOptionsException();
            }
        }
        else
        {
            Usage();
            throw InvalidOptionsException();
        }
    }

    if (xmlFileName.empty())
    {
        Usage();
        throw InvalidOptionsException();
    }

    if (dictOdbFileName.empty() && dictSdbFileName.empty())
    {
        Usage();
        throw InvalidOptionsException();
    }

    if (!dictOdbFileName.empty() && !dictSdbFileName.empty())
    {
        Usage();
        throw InvalidOptionsException();
    }

    if (dictName.empty())
    {
        Usage();
        throw InvalidOptionsException();
    }
}


void CmdLineOpts::Usage()
{
    cerr << progName << " usage =  " << endl;
    cerr << "  -xml <xml_file_name> " << endl;
    cerr << "  -df <dict_object_file_name> | -dictSdbFile "\
      "<dict_SDB_file_name>" << endl;
    cerr << "  -dictName <dict_name> " << endl;
    cerr << "  [-v (verbose)]"  << endl;
}

