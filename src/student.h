#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;
    
//create the Student class w/relevant info
class Student
{
public:
    const static int daysInArray = 3;
private:
        string studentID;
        string fName;
        string lName;
        string email;
        int age;
        int daysInCourse[daysInArray];
        DegreeProgram degreeProgram;
public:
    Student(); //default
    //full constructor, listing like this for readability
    Student(string studentID,
            string fName,
            string lName,
            string email,
            int age,
            int daysInCourse[],
            DegreeProgram degreeProgram);
    
//getters for ea instance var from pt D1
    string getstudentID();
    string getfName();
    string getlName();
    string getemail();
    int getage();
    const int* getdaysInCourse();
    DegreeProgram getdegreeProgram();
    
//setters for ea instance var from pt D1
    void setid(string studentID);
    void setfName(string fName);
    void setlName(string lName);
    void setemail(string email);
    void setage(int age);
    void setdaysInCourse(const int daysInCourse[]);
    void setdegreeProgram(DegreeProgram degreeProgram);

//print() to print student data
    void print();
 
//deconstructor
    ~Student();
};
