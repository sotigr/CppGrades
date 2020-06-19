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

class Courses
{
private:
    CString newCourseCode;
    CString newCourseTitle;
    CString oldCourseCode;
    CString oldCourseTitle;
    bool oldExists;

public:
    Courses(CString &, CString &, CString &, CString &, bool);
    Courses(Courses &);

    CString *getNewCourseCode();
    CString *getNewCourseTitle();
    CString *getOldCourseCode();
    CString *getOldCourseTitle();
    bool const getOldExists();
};