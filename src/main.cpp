
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


// READERS  ==============

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

// END READERS ====================



// HELPER FUNCTIONS =====================

struct course_grade_t
{
    Courses *course;
    bool isOld;
};

course_grade_t getCourseFromGrade(CString *gradeCode)
{
    int courseCount = allCourses->size();

    for (int k = 0; k < courseCount; k++)
    {
        Courses *curCourse = (*allCourses)[k];
        CString newCode = *(curCourse->getNewCourseCode());

        if (newCode == *gradeCode)
        {
            course_grade_t re;
            re.course = curCourse;
            re.isOld = false;
            return re;
        }

        if (curCourse->getOldCourseCode() != NULL)
        {
            CString oldCode = *(curCourse->getOldCourseCode());

            if (oldCode == *gradeCode)
            {
                course_grade_t re;
                re.course = curCourse;
                re.isOld = true;
                return re;
            }
        }
    }
    course_grade_t re;
    re.course = NULL;
    return re;
}

Grades *getNewGrade(CString *newCourseCode, CString *AM)
{
    int allGradesCn = allGrades->size();
    for (int i = 0; i < allGradesCn; i++)
    {
        Grades *grade = (*allGrades)[i];

        if ((*grade->getAM()) == *AM && (*grade->getcourseCode()) == (*newCourseCode))
        {
            return grade;
        }
    }
    return NULL;
}

Students *getStudentByAm(CString *AM)
{
    int studentCn = allStudents->size();
    for (int i = 0; i < studentCn; i++)
    {
        Students *student = (*allStudents)[i];
        if ((*student->getAM()) == (*AM))
        {
            return student;
        }
    }
    return NULL;
}

// END HELPER FUNCTIONS ====================




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
        Grades *grade = (*allGrades)[i];
        course_grade_t course = getCourseFromGrade(grade->getcourseCode());

        if (course.course != NULL)
        {      
            if (course.isOld) {
                CString *newCourseCode = course.course->getNewCourseCode();
                Grades *newGrade = getNewGrade(newCourseCode, grade->getAM());

                if (!newGrade || newGrade->getgrade() != grade->getgrade())
                {
                    if (newGrade)
                    {

                        Students *student = getStudentByAm(grade->getAM());
                        if (student)
                        {
                            CString studentName = *student->getname();
                            CString courseName = *course.course->getNewCourseTitle();
                            float oldGradeVal = grade->getgrade();
                            float newGradeVal = newGrade->getgrade();

                            cout << studentName.getWord() << courseName.getWord() << oldGradeVal << newGradeVal<< endl;
                        }
                        else
                        {
                            cout << "no student found with AM " << grade->getAM()->getWord() << endl;
                        }
                    }
                    else
                    {
                        cout << "new grade not found" << endl;
                    }
    
                }
            }
        } else {
            CString  notFoundCourseCode = *grade->getcourseCode();
            cout<< "course: " << notFoundCourseCode.getWord() << " was not found" << endl;
        }
 
    }
}
