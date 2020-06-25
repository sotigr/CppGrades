#include "CsvReader.h"

CsvReader::CsvReader(const char *filePath)
{
    path = new char[strlen(filePath)];
    strcpy(path, filePath); 
}

CsvReader::~CsvReader()
{
    delete [] path; 
}

CSV_RESULT * CsvReader::read(const bool skipFirstLine)
{
    CSV_RESULT * rows = new CSV_RESULT();
    ifstream infile(path);

    int bufferSize = 1024;
    char line[bufferSize];
    
    int cn = 0;

    while( infile.getline( line, bufferSize ) )
    {  
        if (!(skipFirstLine && cn == 0)) { 

            CString * str = new CString(line);

            vector<CString*>* data = str->split(";");

            rows->push_back(data); 

        }
        cn++;
    }

    return rows; 
}
