#include "Courses.h"
#include "CString.h"
#include "Grades.h"
#include "Students.h"
#include "Lists.h"
using namespace std;

Lists::Lists(vector<Grades *> &vg, vector<Students *> &vs, vector<Courses *> &vc)
{
    gradeList = vg;
    studentsList = vs;
    oursesList = vc;
}

vector<Grades *> *Lists::getGradeList()
{
    return &gradeList;
}

vector<Students *> *Lists::getStudentsList()
{
    return &studentsList;
}

vector<Courses *> *Lists::etOursesList()
{
    return &oursesList;
}