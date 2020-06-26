#include "Courses.h"
#include "CString.h"
#include "Grades.h"
#include "Students.h"
using namespace std;
 

Students::Students(CString *AM, CString *name, CString *sName)
{
    this->AM = AM;
    this->name = name;
    this->sName = sName; 
    
}


Students::Students(Students &s)
{
    AM = new CString(*s.AM);
    name = new CString(*s.name);
    sName = new CString(*s.sName); 
}

CString *Students::getAM()
{
    return AM;
}

CString *Students::getname()
{
    return name;
}

CString *Students::getSName()
{
    return sName;
}

vector<Grades *> *Students::getStudentsGrades()
{
    return studentsGrades;
}
 