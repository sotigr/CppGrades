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
#include "Grades.h"

using namespace std;

class Students
{
private:
    CString AM;
    CString name;
    CString sName;
    vector<Grades *> studentsGrades;

public:
    Students(CString &, CString &, CString &, vector<Grades *>);
    Students(Students &);

    CString *getAM();
    CString *getname();
    CString *getSName();
    vector<Grades *> *getStudentsGrades();
};