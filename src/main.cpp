
#include <stdio.h>
#include <iostream>

#include "CString.h"
#include "CsvReader.h"
#include "Grades.h"
#include "Students.h"
#include "Courses.h"
#include "Lists.h"

using namespace std;

vector<Grades *> *allGrades;
vector<Students *> *allStudents;
vector<Courses *> *allCourses;

vector<Grades *> *readGrades()
{
    CsvReader readerGrades("/home/sotig/Desktop/Projects/CppGrades/docs/grades.csv");
    CSV_RESULT *rows = readerGrades.read(true);

    int rowCount = rows->size();

    vector<Grades *> *allGrades = new vector<Grades *>();

    for (int i = 0; i < rowCount; i++)
    {
        auto row = *((*rows)[i]);

        auto AM = row[0];
        auto courseCode = row[1];
        float gradeVal = atof(row[2]->getWord());

        Grades *grade = new Grades(AM, courseCode, gradeVal);

        allGrades->push_back(grade);
    }

    return allGrades;
}

vector<Students *> *readStudents()
{
    CsvReader readerStudents("/home/sotig/Desktop/Projects/CppGrades/docs/students.csv");
    CSV_RESULT *rows = readerStudents.read(true);

    int rowCount = rows->size();

    vector<Students *> *allStudents = new vector<Students *>();

    for (int i = 0; i < rowCount; i++)
    {
        auto row = *((*rows)[i]);

        auto AM = row[0];
        auto Surname = row[1];
        auto Name = row[2];

        Students *student = new Students(AM, Name, Surname);
        allStudents->push_back(student);
    }

    return allStudents;
}

vector<Courses *> *readCourses()
{
    CsvReader readerCourses("/home/sotig/Desktop/Projects/CppGrades/docs/courses.csv");
    CSV_RESULT *rows = readerCourses.read(true);

    int rowCount = rows->size();

    vector<Courses *> *allCourses = new vector<Courses *>();

    for (int i = 0; i < rowCount; i++)
    {
        auto row = *((*rows)[i]);

        bool hasOld = row.size() > 2;

        CString *oldCode = NULL;
        CString *oldTitle = NULL;
        CString *newCode = NULL;
        CString *newTitle = NULL;

        if (hasOld)
        {
            newCode = row[0];
            newTitle = row[1];
            oldCode = row[2];
            oldTitle = row[3];
        }
        else
        {
            newCode = row[0];
            newTitle = row[1];
        }

        Courses *course = new Courses(newCode, newTitle, oldCode, oldTitle, hasOld);
        allCourses->push_back(course);
    }

    return allCourses;
}



Courses * getCourseFromGrade(CString *gradeCode)
{
    int courseCount = allCourses->size();

    for (int k = 0; k < courseCount; k++)
    {
        Courses *curCourse = (*allCourses)[k];
        CString newCode = *(curCourse->getNewCourseCode());

        if (newCode == *gradeCode)
        { 
            return curCourse;
        }

        if (curCourse->getOldCourseCode() != NULL)
        {
            CString oldCode = *(curCourse->getOldCourseCode());
 
            if (oldCode == *gradeCode)
            { 
                return curCourse;
            }
        }
    }

    return NULL;
}

int main()
{

    //Read Csv
    allGrades = readGrades();
    allStudents = readStudents();
    allCourses = readCourses();

    int gradeCn = allGrades->size();
    int courseCount = allCourses->size();
    for (int i = 0; i < gradeCn; i++)
    { 
          Courses *course = getCourseFromGrade(((*allGrades)[i]->getcourseCode()));

        if (course != NULL)
        { 
            course->getNewCourseTitle()->print();
        }
        // cout<< course->getNewCourseTitle()->getWord() << isNewCode<<endl;
    }
}
