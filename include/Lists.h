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
#include "Students.h"
#include "Courses.h"

using namespace std;

class Lists
{
private:
    vector<Grades *> *gradeList;
    vector<Students *> *studentsList;
    vector<Courses *> *coursesList;

public:
    Lists(vector<Grades *> *, vector<Students *> *, vector<Courses *> *);
    vector<Grades *> *getGradeList();
    vector<Students *> *getStudentsList();
    vector<Courses *> *getOursesList();
};