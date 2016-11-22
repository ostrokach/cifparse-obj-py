#include <string>

#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/sax2/Attributes.hpp>

#include "ISTable.h"
#include "TableFile.h"

#include "PdbMlParserHandler.h"
#include "misc_util.h"


using std::cout;
using std::endl;


PdbMlParserHandler::PdbMlParserHandler(TableFile& tableFile) :
  _tableFile(tableFile)
{

    Clear();

}


PdbMlParserHandler::~PdbMlParserHandler()
{

}


void PdbMlParserHandler::startElement(const XMLCh *const uri,
  const XMLCh *const localname, const XMLCh *const qname,
  const Attributes& attrs)
{

    string element = toString(localname);

    if (_inDataBlock)
    {
        if (_inTable)
        {
            if (_inRow)
            {
                if (!_inCell)
                {
                    // Next cell in row
                    _inCell = true;

                    // Check if the column exists. If not, add it.
                    if (!(_isTableP->IsColumnPresent(element)))
                    {
                        _isTableP->AddColumn(element);
                        // VLAD ERROR HANDLING
                    }
                    _currCellName = element;
                }
                else
                {
                    _ErrMessage(string("Error in column organization"\
                      "within row"), element);
                }
            }
            else if (element == _isTableP->GetName())
            {
                // VLAD INVESTIGATE. HOW IS SOME FAILURE IN OBJECT CREATION
                // AFECTING THIS AND OTHER FLAGS AND IN MORE GENERAL HOW
                // IS ANY FAILURE AFFECTING ANY STATE

                // Start of a new row
                _inRow = true;

                _GetAttributes(attrs);

                // VLAD: ASSUMPTION IS THAT ALL REPEATED CATEGORIES WILL
                // HAVE THE SAME KEY IDENTIFIERS. OTHERWISE THIS CODE WILL
                // NOT WORK. SEE WITH JOHN THE PROPER OPERATION.
                // The first instance of category should define the key columns.
                if (_isTableP->GetNumColumns() == 0)
                {
                    _keyColNames.clear();

                    for (unsigned int index = 0; index < _currRowNames.size();
                      index++)
                    {
                        _isTableP->AddColumn(_currRowNames[index]);

                        // Save key column name
                        _keyColNames.push_back(_currRowNames[index]);
                    }
                }

                // Just add the row to the table, even if it has the same
                // key as some existing row. The duplicate rows will be
                // removed prior to writing the table to the TableFile.
                // Searching for duplicate rows here would be too expensive
                // in terms of performance.

                // Add the row (with empty cell values) so that cell
                // update can be used.
                _isTableP->AddRow();
            }
            else
            {
                _ErrMessage(string("Error in row organization"), element);
            }
        }
        else
        {
            string currentTableName = _ExtractTableName(element);

            if (!currentTableName.empty())
            {
                // Start of a new table
                _inTable = true;

                // Check to see if this is a duplicate table.
                Block& block = _tableFile.GetBlock(_currBlockName);
                bool tablePresent = block.IsTablePresent(currentTableName);
                if (tablePresent == true)
                {
                    // Table is already present. Get the pointer to it.
                    // Issue warning and continue with processing.
                    // VLAD CODE FINISH IT
                    _isTableP =
                      block.GetTablePtr(currentTableName);
                }
                else
                {
                    // Table is not present. Create a new table.
                    _isTableP = new ISTable(currentTableName,
                      _tableFile.GetCaseSensitivity());
                    // VLAD ERROR HANDLING
                }
            }
            else
            {
                _ErrMessage(string("Error in table organization"), element);
            }
        }
    }
    else if (element == ELEMENT_DATABLOCK)
    {
        // Start of a datablock
        _inDataBlock = true;

        string dataBlockName = _GetDataBlockName(attrs);
        if (!dataBlockName.empty())
        {
            // Attribute denoting datablock name is present. Get the
            // datablock name and see if it was encountered before.
            int blockPresent = _tableFile.IsBlockPresent(dataBlockName);
            if (blockPresent == 1)
            {
                // Block is already present. Just issue warning and continue
                // with processing.
                // VLAD CODE FINISH IT
            }
            else
            {
                // Block is not present. Add it and set to use it.
                _currBlockName = _tableFile.AddBlock(dataBlockName);
            }
        }
        else
        {
            // No datablockName attribute. WHAT DO WE DO? ASK JOHN
            // VLAD CODE FINISH IT
        }
    }
    else
    {
        _ErrMessage(string("Error in database organization"), element);
    }

    //  printState(element);

}


void PdbMlParserHandler::endElement(const XMLCh *const uri,
  const XMLCh *const localname, const XMLCh *const qname)
{

    string element = toString(localname);

    if (_inCell)
    {
        if (element == _currCellName)
        {
            _inCell = false;
            _currCellName.erase();
        }
        else
        {
            _ErrMessage(string("Error in column organization within row"),
              element);
        }
    }
    else if (_inRow)
    {
        if (element == _isTableP->GetName())
        {
            _inRow = false;
            _SaveRow();
        }
        else
        {
            _ErrMessage(string("Error in row organization"), element);
        }
    }
    else if (_inTable)
    {
        string tableName = _ExtractTableName(element);
        if (tableName == _isTableP->GetName())
        {
            _inTable = false;
            _SaveTable();
            _isTableP = NULL;
        }
        else
        {
            _ErrMessage(string("Error in table organization"), element);
        }
    }
    else if (_inDataBlock)
    {
        if (element == ELEMENT_DATABLOCK)
        {
            _inDataBlock = false;
            // VLAD INVESTIGATE: DO WE NEED TO DO ANY RESSETING OF STATE
            // AT THE END OF DATABLOCK
        }
        else
        {
            _ErrMessage(string("Error in database organization"), element);
        }
    }
    else
    {
        _ErrMessage(string("Error in organization"), element);
    }

}


#if XERCES_VERSION_MAJOR == 2 && XERCES_VERSION_MINOR == 8 &&                   XERCES_VERSION_REVISION == 0
void PdbMlParserHandler::characters(const XMLCh *const chars,
  const unsigned int length)
#else
void PdbMlParserHandler::characters(const XMLCh *const chars,
  const XMLSize_t length)
#endif
{

    if (_inCell)
    {
        if (_currRowNames.empty())
        {
            // Store name and value in row.
            _currRowNames.push_back(_currCellName);
            _currRowValues.push_back(toString(chars));
        }
        else
        {
            // Check if the _currCellName is the last name stored in
            // _currRowNames.

            // This processing is needed for the following reason:
            // When the value contains escape characters (special letter
            // combinations preceeded by an "&"), XML parser slices this
            // value and calls this method whenever it encounters an escaped
            // character. For example, for a value "one&apos;two&apos;three",
            // this method will be called three times and "chars" would have
            // values "one", "'two" and "'three". In order to get the original
            // value, all these have to be concatenated.
            if (_currRowNames[_currRowNames.size() - 1] == _currCellName)
            {
                // The name was already stored in the array. This processing
                // is due to presence of escape characters in the value.
                _currRowValues[_currRowNames.size() - 1] += toString(chars);
            }
            else
            {
                // Store name and value in row.
                _currRowNames.push_back(_currCellName);
                _currRowValues.push_back(toString(chars));
            }
        } // If _currRowNames not empty
    } // If in cell

}


void PdbMlParserHandler::warning(const SAXParseException& e)
{

    string err("Warning in PdbMlParserHandler [warning() method]:\nWarning"\
      " at file: ");
    err += toString(e.getSystemId());
    err += ", line ";
    err += String::IntToString(e.getLineNumber());
    err += ", char ";
    err += String::IntToString(e.getColumnNumber());
    err += ".\nMessage: ";
    err += toString(e.getMessage());
    err += ".\n";

    Error(err);

}


void PdbMlParserHandler::error(const SAXParseException& e)
{

    string err("Error in PdbMlParserHandler [error() method]:\nError"\
      " at file:\n");
    err += toString(e.getSystemId());
    err += ", line ";
    err += String::IntToString(e.getLineNumber());
    err += ", char ";
    err += String::IntToString(e.getColumnNumber());
    err += ".\nMessage: ";
    err += toString(e.getMessage());
    err += ".\n";

    Error(err);

}


void PdbMlParserHandler::fatalError(const SAXParseException& e)
{

    string err("Fatal Error in PdbMlParserHandler [fatalError()"\
      " method]:\nFatal Error at file:\n");
    err += toString(e.getSystemId());
    err += ", line ";
    err += String::IntToString(e.getLineNumber());
    err += ", char ";
    err += String::IntToString(e.getColumnNumber());
    err += ".\nMessage: ";
    err += toString(e.getMessage());
    err += ".\n";

    Error(err);

}


void PdbMlParserHandler::printState(const string& element)
{

    cout << "  Element " << element << " len " << element.size() << endl;
    cout << "  Current Datablock Name " <<  _currBlockName <<
      endl;
    cout << "  Current Table Name " <<  _isTableP->GetName() << endl;
    cout << "  Current Cell Name " << _currCellName << endl;

    cout << "  _inDataBlock " << _inDataBlock << endl;
    cout << "  _inTable " << _inTable  << endl;
    cout << "  _inRow " << _inRow << endl;
    cout << "  _inCell " << _inCell << endl;

    cout << " -------------------------------------------------------"\
      "-------" << endl;

}


void PdbMlParserHandler::Clear()
{

    _inDataBlock = false;
    _inTable = false;
    _inRow = false;
    _inCell = false;

    _currRowNames.clear();
    _currRowValues.clear();

    _currCellName.clear();
    _currBlockName.clear();

    _isTableP = NULL;

}


void PdbMlParserHandler::_GetAttributes(const Attributes& attrs)
{

    _currRowNames.clear();
    _currRowValues.clear();

    for (unsigned int index = 0; index < attrs.getLength(); index++)
    {
        _currRowNames.push_back(toString(attrs.getLocalName(index)));
        _currRowValues.push_back(toString(attrs.getValue(index)));
    }

}


string PdbMlParserHandler::_GetDataBlockName(const Attributes& attrs)
{

    string dataBlockName;

    for (unsigned int index = 0; index < attrs.getLength(); index++)
    {
        if (toString(attrs.getLocalName(index)) == ATTRIBUTE_DATABLOCK)
        {
            dataBlockName = toString(attrs.getValue(index));
            break;
        }
    }

    return(dataBlockName);

}


string PdbMlParserHandler::_ExtractTableName(const string& tableContName)
{

    string tableName;

    unsigned int len = tableContName.size();

    if (len > TABLE_CONTAINER_SUFFIX.size())
    {
        unsigned int ipos = tableContName.find(TABLE_CONTAINER_SUFFIX,
          len - TABLE_CONTAINER_SUFFIX.size());
        if (ipos > 0 && ipos < len)
        {
            tableName = tableContName.substr(0, tableContName.size() -
              TABLE_CONTAINER_SUFFIX.size());
        }
    }

    return(tableName);

}


void PdbMlParserHandler::_SaveRow(void)
{

    unsigned int currRowIndex = _isTableP->GetLastRowIndex();

    for (unsigned int index = 0; index < _currRowValues.size(); index++)
    {
        _isTableP->UpdateCell(currRowIndex, _currRowNames[index],
          _currRowValues[index]);
    }

}


void PdbMlParserHandler::_SaveTable()
{

    if (_isTableP == NULL)
    {
        return;
    }

    // Remove duplicate rows from the table
    vector<pair<unsigned int, unsigned int> > duplRows;

    // First search for duplicate rows, but do not remove them. This
    // is because, we need to get info from the original table in order
    // to issue the warning. The search goes backward, which will enable
    // keeping the last row and removing all duplicate ones prior to that
    // This is in accordance with the principle that the last entry is the
    // valid entry.
    _isTableP->FindDuplicateRows(duplRows, _keyColNames, true,
      ISTable::eBACKWARD);

    if (!duplRows.empty())
    {
        string errString;

        errString = "WARNING: In category \"" + _isTableP->GetName() +
          "\", " + "for the category key(s):" + "\n";

        errString += "  ";

        for (unsigned int colIndex = 0; colIndex < _keyColNames.size();
          colIndex++)
        {
            errString += "\"";
            errString += _keyColNames[colIndex];
            errString += "\"";
            if (colIndex != _keyColNames.size() - 1) 
            {
                errString += ", ";
            }
        }
        errString += "\n";

        errString += "found duplicate key(s) value: \n";
        errString += "  ";

        string cell;

        for (unsigned int colIndex = 0; colIndex < _keyColNames.size();
          colIndex++)
        {
            cell = (*_isTableP)(duplRows[duplRows.size() - 1].second,
              _keyColNames[colIndex]);

            errString += "\"";
            errString += cell;
            errString += "\"";
            if (colIndex != _keyColNames.size() - 1) 
            {
                errString += ", ";
            }
        }
        errString += "\n";

        // Issue warning
        Error(errString);

        // Delete duplicate rows
        vector<unsigned int> duplRowIndices;
        for (unsigned int rowI = 0; rowI < duplRows.size(); rowI++)
        {
            duplRowIndices.push_back(duplRows[rowI].first);
        }

        _isTableP->DeleteRows(duplRowIndices);
    }

    cout << "Saving " << _isTableP->GetNumColumns() << " columns and " <<
      _isTableP->GetNumRows() << " rows " << " in table " <<
      _isTableP->GetName() << endl;

    Block& block = _tableFile.GetBlock(_currBlockName);    

    block.WriteTable(_isTableP);

}


void PdbMlParserHandler::_ErrMessage(const string& err, const string& element)
{

    string errm(err);

    errm += " at element ";
    errm += element;

    Error(errm);

}

