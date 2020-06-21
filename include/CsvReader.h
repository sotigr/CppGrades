#pragma once
#include <stdio.h>
#include <new>
#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <sstream>
#include <cstring>
#include "CString.h"
#include <fstream>

using namespace std;

class CsvReader
{
private:
    char *path;
    int *cols;

public:
    CsvReader(const char *filePath, const int *numOfCols);
    // ~CsvReader();
    vector<char **> *read();
};
