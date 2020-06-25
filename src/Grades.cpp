#include "Courses.h"
#include "CString.h"
#include "Grades.h"
using namespace std;

Grades::Grades(CString *AM, CString *courseCode, float grade)
{
    this->AM = AM;
    this->courseCode = courseCode;
    this->grade = grade;
}

Grades::Grades(Grades &g)
{
    AM = g.AM;
    courseCode = g.courseCode;
    grade = g.grade;
}

CString *Grades::getAM()
{
    return AM;
}

CString *Grades::getcourseCode()
{
    return courseCode;
}

float Grades::getgrade()
{
    return grade;
}