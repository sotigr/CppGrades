
#include <stdio.h>
#include <iostream>

#include "CString.h"
#include "CsvReader.h"
#include "Grades.h"
#include "Students.h"
#include "Lists.h"


using namespace std;
 

vector<Grades*>* readGrades() {
    CsvReader readerGrades("/home/sotig/Desktop/Projects/CppGrades/docs/grades.csv");
    CSV_RESULT * rows = readerGrades.read(true);
  
    int rowCount = rows->size();

    vector<Grades*>* allGrades = new vector<Grades*>();

    for (int i = 0; i < rowCount; i++) {
        auto row = *((*rows)[i]);

        auto AM = row[0];
        auto courseCode = row[1];
        float gradeVal = atof(row[2]->getWord());

        Grades* grade = new Grades(AM, courseCode, gradeVal);

        allGrades->push_back(grade);
        
    }   

    return allGrades;
}

vector<Students*>* readStudents() {
    CsvReader readerStudents("/home/sotig/Desktop/Projects/CppGrades/docs/students.csv");
    CSV_RESULT * rows = readerStudents.read(true);
  
    int rowCount = rows->size();

    vector<Students*>* allStudents = new vector<Students*>();

    for (int i = 0; i < rowCount; i++) {
        auto row = *((*rows)[i]);

        auto AM = row[0];
        auto Surname = row[1];
        auto Name = row[2];

        Students* student = new Students(AM, Name, Surname);
        allStudents->push_back(student);
    }   

    return allStudents;
}

int main()
{ 

    //Read Csv
    vector<Grades*>* allGrades = readGrades(); 
    vector<Students*>* allStudents = readStudents();

}

