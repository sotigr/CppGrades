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

using namespace std;

class Grades
{
private:
    CString* AM;
    CString* courseCode;
    float grade;

public:
    Grades(CString *, CString *, float);
    Grades(Grades &);
    

    CString *getAM();
    CString *getcourseCode();
    float getgrade();
};
