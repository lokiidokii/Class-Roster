#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

//constructor using all input parameters
Student::Student()
{
    this->studentID = ""; //set to empty string > Null to avoid errors
    this->fName = "";
    this->lName = "";
    this->email = "";
    this->age = 0;
    //prob not necessary with so few but doing this way since it's more likely for irl application:
    for (int i=0; i < daysInArray; i++) this->daysInCourse[i] = 0;
    this->degreeProgram = DegreeProgram::UNDECIDED;
};

//full constructor, listing like this for readability
Student::Student(string studentID,
                 string fName,
                 string lName,
                 string email,
                 int age,
                 int daysInCourse[],
                 DegreeProgram degreeProgram)
{
    this->studentID = studentID;
    this->fName = fName;
    this->lName = lName;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysInArray; i++) this->daysInCourse[i] = daysInCourse[i];
    this->degreeProgram = degreeProgram;
};

//getters for ea instance var from pt D1
string Student::getstudentID() { return this->studentID; }
string Student::getfName() { return this->fName; }
string Student::getlName() { return this->lName; }
string Student::getemail() { return this->email; }
int Student::getage() { return this->age; }
const int* Student::getdaysInCourse() { return this->daysInCourse; }
DegreeProgram Student::getdegreeProgram() { return degreeProgram; }

//setters for ea instance var from pt D1
void Student::setid(string studentID) { this->studentID = studentID; }
void Student::setfName(string fName) { this->fName = fName; }
void Student::setlName(string lName){ this-> lName = lName; }
void Student::setemail(string email) { this-> email = email; }
void Student::setage(int age) { this-> age = age; }
void Student::setdaysInCourse(const int daysInCourse[])
{
    for (int i = 0; i < daysInArray; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setdegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//print() student data
void Student::print(){
    cout << "Student ID:\t" << this->studentID << " |" << '\t';
    cout << "Name:\t" << this->fName << '\t';
    cout << this->lName << " |" << '\t';
    cout << "Email:\t" << this->email << " |" << '\t';
    cout << "Age:\t" << this->age << " |" << '\t';
    cout << "Days In Course:\t" << this->daysInCourse[0] << "," << '\t';
    cout << this->daysInCourse[1] << "," << '\t';
    cout << this->daysInCourse[2] << " |" << '\t';
    cout << "Degree Program:\t" << degreeProgramString[(int)this->degreeProgram] << '\t';
    cout << endl;
};

//destructor
Student::~Student()
{};
