#include "CsvReader.h"

CsvReader::CsvReader(const char *filePath, const int *numOfCols)
{
    strcpy(path, filePath);
    cols = (int*)malloc(sizeof(int));
    memcpy(cols, &numOfCols, sizeof(int));
}

// CsvReader::~CsvReader()
// {
//     delete [] path;
//     delete cols;
// }

vector<char **> *CsvReader::read()
{
    vector<char **> *rows = new vector<char **>();
    ifstream infile("test.txt");

    char line[1024];
    
    int cn = 0;

    while( infile.getline( line, 1024 ) )
    { 
        cout << strlen(line) << endl; 
        cout << line << endl;

        int len = strlen(line);

        //TODO IMPLEMENT SPLIT FUNCTION IN CString class
        
        cn++;
    }

    return rows;
}
