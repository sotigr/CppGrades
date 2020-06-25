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
#define CSV_RESULT vector<vector<CString*>*>

using namespace std;

class CsvReader
{
private:
    char *path;

public:
    CsvReader(const char *filePath);
    ~CsvReader();
    CSV_RESULT * read(const bool skipFirstLine);
};
