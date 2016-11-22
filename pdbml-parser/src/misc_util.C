#include <string>
#include <algorithm>

#include "CifString.h"
#include "ISTable.h"
#include "misc_util.h"


using std::ofstream;
using std::ios;
using std::cout;
using std::endl;


static const string PDBML_PARSER_LOG_FILE("PdbMlParser.log");


static string RemoveLostCharacters(const string& inString);


string toString(const XMLCh* toConvert)
{

    StrX strX(toConvert);
    return(string(strX.localForm()));

}


void Error(string& err)
{

    ofstream out(PDBML_PARSER_LOG_FILE.c_str(), ios::app);
    out << err << endl;
    out.close();

}


void DeleteFile(const string& fileName)
{

    unlink(fileName.c_str());

}


void ResurrectOrigItemNames(CifFile& cifFile, DataInfo& dataInfo)
{
    vector<string> blockNames;
    string origItemName;
    string nonResItemName;
    string categoryName;
    ISTable* tableP = NULL;

    cifFile.GetBlockNames(blockNames);

    for (unsigned int blockI = 0; blockI < blockNames.size(); blockI++)
    {
        // Get the list of all original combo items of all categories
        const vector<string>& origComboItems = dataInfo.GetItemsNames();

        Block& block = cifFile.GetBlock(blockNames[blockI]);

        for (unsigned int itemI = 0; itemI < origComboItems.size(); itemI++)
        {
            // Get original item name from combo item name
            CifString::GetItemFromCifItem(origItemName,
              origComboItems[itemI]);

            if (origItemName.empty())
            {
                // VLAD ERROR HANDLING
                // Report error.
            }

            // Remove lost characters and search for non-resurrected item
            // in the converted CIF file.
            nonResItemName = RemoveLostCharacters(origItemName);

            if (origItemName.size() == nonResItemName.size())
            {
                // No lost characters found.
                continue;
            }

            // Rename the item in CIF file.

            // Get category name from combo item name
            CifString::GetCategoryFromCifItem(categoryName,
              origComboItems[itemI]);

            if (categoryName.empty())
            {
                // VLAD ERROR HANDLING
                // Report error.
            }

            tableP = block.GetTablePtr(categoryName);

            if (tableP == NULL)
            {
                continue;
            }

            if (tableP->IsColumnPresent(nonResItemName))
            {
                tableP->RenameColumn(nonResItemName, origItemName);
            }
        } // for (each original item)

    } // for (each block)

    blockNames.clear();
} /* End of ResurrectOrigItemNames() */


void CorrectEmptyValuesOfMandatoryItems(CifFile& cifFile, DataInfo& dataInfo)
{

    vector<string> blockNames;
    vector<string> tableNames;
    ISTable* tableP = NULL;
    string mandItemName;
    string cell;

    cifFile.GetBlockNames(blockNames);

    for (unsigned int blockI = 0; blockI < blockNames.size(); blockI++)
    {
        Block& block = cifFile.GetBlock(blockNames[blockI]);

        block.GetTableNames(tableNames);

        for (unsigned int tableI = 0; tableI < tableNames.size(); tableI++)
        {
            tableP = block.GetTablePtr(tableNames[tableI]);

            const vector<string>& comboMandItems =
              dataInfo.GetCatKeys(tableP->GetName());

            for (unsigned int itemI = 0; itemI < comboMandItems.size(); itemI++)
            {
                // Get original item name from combo item name
                CifString::GetItemFromCifItem(mandItemName,
                  comboMandItems[itemI]);

                if (mandItemName.empty())
                {
                    // VLAD ERROR HANDLING
                    // Report error.
                }

                if (!tableP->IsColumnPresent(mandItemName))
                {
                    // VLAD - ERROR HANDLING
                    continue;
                }

                for (unsigned int rowI = 0; rowI < tableP->GetNumRows();
                  rowI++)
                {
                    cell = (*tableP)(rowI, mandItemName);
                    if (cell.empty())
                    {
                        tableP->UpdateCell(rowI, mandItemName, ".");
                    }
                } // For all values of mandatory items
            } // For all mandatory items

        } // For all tables

        tableNames.clear();
    } // For all blocks

    blockNames.clear();

} /* End of CorrectEmptyValuesOfMandatoryItems() */


string RemoveLostCharacters(const string& inString)
{

    if (inString.empty())
    {
        string errString = "ERROR: Detected empty string where it should" \
          " not have been detected!\n";
        Error(errString);
        return(inString);
    }

    string outString = inString;

    string tmpString(inString);

    string::iterator iter = remove_if(tmpString.begin(), tmpString.end(),
      IsLostChar());

    if (iter == tmpString.end())
    {
        return(outString);
    }

    // Remove all the lost characters from the string.
    outString.assign(tmpString.begin(), iter);

    return(outString);

} /* End of RemoveLostCharacters() */
