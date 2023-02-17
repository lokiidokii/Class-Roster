#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "roster.h"
#include "student.h"

using namespace std;

const static int totalStudents = 5;
Student* classRosterArray[totalStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

//constructor
Roster::Roster() {};
//destructor
Roster::~Roster() {
    for (int i = 0; i < totalStudents; i++)
    {
        cout << "Dynamic destructor called for " << classRosterArray[i]->getstudentID() << endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
};

Student** Roster::getStudent(){
    return classRosterArray;
}
//parsing with regex
void Roster::parseArray(const string studentData[]){
    regex regex("\\,"); //split at comma
    for (int i = 0; i < 5; i++)
    {
        string tempString = studentData[i];
        std::vector<string> studentDataElements(
            std::sregex_token_iterator(tempString.begin(), tempString.end(), regex, -1), std::sregex_token_iterator());
        DegreeProgram dp = DegreeProgram::UNDECIDED;
            if (studentDataElements.at(8).back() == 'Y') dp = DegreeProgram::SECURITY; //'Y' = securit'Y'
            if (studentDataElements.at(8).back() == 'K') dp = DegreeProgram::NETWORK; //'K' = networ'K'
            if (studentDataElements.at(8).back() == 'E') dp = DegreeProgram::SOFTWARE; //'E' = softwar'E'
            add(studentDataElements.at(0),
                studentDataElements.at(1),
                studentDataElements.at(2),
                studentDataElements.at(3),
                stoi(studentDataElements.at(4)),
                stoi(studentDataElements.at(5)),
                stoi(studentDataElements.at(6)),
                stoi(studentDataElements.at(7)),
                dp);
    }
};

//public void add(string studentID, string fName, string lName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
//listed for readability
void Roster::add(string studentID,
                 string fName,
                 string lName,
                 string email,
                 int age,
                 int daysInCourse1,
                 int daysInCourse2,
                 int daysInCourse3,
                 DegreeProgram degreeProgram)
{
        int courseDays[Student::daysInArray]{daysInCourse1, daysInCourse2, daysInCourse3};
    //this is why last index is -1 bc first one is in slot 0
        classRosterArray[++studentIndex] = new Student(studentID, fName, lName, email, age, courseDays, degreeProgram);

};

//public void printAll()
void Roster::printAll()
{
    for (int i = 0; i <= Roster::studentIndex; i++)
    {
        if (classRosterArray[i] == nullptr){}
        else { classRosterArray[i]->print();
        }
    }
};

//public void printInvalidEmails()
void Roster::printInvalidEmails()
{
    cout << endl << "!! INVALID EMAIL ADDRESS !! \nNote: A valid email should contain '@' and '.' + should not include any spaces ' ' \nPLEASE RE-ENTER YOUR EMAIL: " << endl;
        for (int i = 0; i < totalStudents; i++)
        {
            if ((classRosterArray[i]->getemail()).find('@') == -1) {
                cout << classRosterArray[i]->getemail() << endl;
            }
            else if ((classRosterArray[i]->getemail()).find('.') == -1) {
                cout << classRosterArray[i]->getemail() << endl;
            }
            else if ((classRosterArray[i]->getemail()).find(' ') != -1) {
                cout << classRosterArray[i]->getemail() << endl;
            }
        }
};

//public void printAverageDaysInCourse(string studentID)
void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= Roster::studentIndex; i++)
    {
        if (classRosterArray[i]->getstudentID() == studentID) {
            cout << studentID << " : ";
            cout << ((classRosterArray[i]->getdaysInCourse()[0]
                + classRosterArray[i]->getdaysInCourse()[1]
                + classRosterArray[i]->getdaysInCourse()[2])
                / 3) << endl;
        }
    }
};

//public void printByDegreeProgram(DegreeProgram degreeProgram)
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    for (int i = 0; i <= Roster::studentIndex; i++) {
        if (Roster::classRosterArray[i]->getdegreeProgram() == degreeProgram) classRosterArray[i]->print();
    }
    cout << endl;
};

//public void remove(string studentID)
void Roster::removeStudent(string studentID)
{
    bool removeStudent = false;
    for (int i = 0; i <= Roster::studentIndex; i++)
    {
        if (classRosterArray[i]->getstudentID() == studentID) {
            removeStudent = true;
            if (i < 5 - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[5 - 1];
                classRosterArray[totalStudents - 1] = temp;
            }
            Roster::studentIndex--;
        }

    }
    if (removeStudent) {
        cout << studentID << " STUDENT REMOVED: " << endl;
        this->printAll();
    }
    else cout << studentID << " STUDENT NOT FOUND" << endl;
};
