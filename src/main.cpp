
#include <stdio.h>
#include <iostream>

#include "CString.h"
#include "CsvReader.h"

using namespace std;

int main()
{
    CString s("markoulhs");

    s.print();

    CsvReader reader("test.txt", 0);
    vector<char **> *rows = reader.read();
}
