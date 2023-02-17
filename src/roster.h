#pragma once
#include <vector>
#include <string>
#include <regex>

#include "student.h"

//create Roster class
class Roster
{
private:
    int studentIndex = -1; //increments every time we add a student
    const static int totalStudents = 5; //size of array
    //create array of pointers 'classRosterArray' to hold data provided in the 'studentData Table'
    Student* classRosterArray[totalStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };
    
public:
//constructor
Roster();
//destructor
~Roster();
//create an obj for ea student using data from studentData
Student** getStudent();
//parsing method
void parseArray(const string studentData[]);
    
//public void add(string studentID, string fName, string lName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
void add(string studentID,
         string fName,
         string lName,
         string email,
         int age,
         int daysInCourse1,
         int daysInCourse2,
         int daysInCourse3,
         DegreeProgram degreeProgram);

//public void printAll()
void printAll();

//public void printAverageDaysInCourse(string studentID)
void printAverageDaysInCourse(string studentID);

//public void printInvalidEmails()
void printInvalidEmails();

//public void printByDegreeProgram(DegreeProgram degreeProgram)
void printByDegreeProgram(DegreeProgram degreeProgram);

//public void remove(string studentID)
void removeStudent(string studentID);

};



