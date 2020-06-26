#include "Courses.h"
#include "CString.h"
using namespace std;

Courses::Courses(CString *newCC, CString *newCT, CString *oldCC, CString *oldCT, bool oldExists)
{
    newCourseCode = newCC;
    newCourseTitle = newCT;
    oldCourseCode = oldCC;
    oldCourseTitle = oldCT;
    this->oldExists = oldExists;
}

Courses::Courses(Courses &c)
{
    newCourseCode = new CString(*c.newCourseCode);
    newCourseTitle = new CString(*c.newCourseTitle);
    oldCourseCode = new CString(*c.oldCourseCode);
    oldCourseTitle = new CString(*c.oldCourseTitle);
    oldExists = c.oldExists;
}

CString *Courses::getNewCourseCode()
{
    return newCourseCode;
}

CString *Courses::getNewCourseTitle()
{
    return newCourseTitle;
}

CString *Courses::getOldCourseCode()
{
    return oldCourseCode;
}

CString *Courses::getOldCourseTitle()
{
    return oldCourseTitle;
}

bool const Courses::getOldExists()
{
    return oldExists;
}