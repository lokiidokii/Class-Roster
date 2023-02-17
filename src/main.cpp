#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

int main()
{

    cout << "---------------------------------------------" << endl;
    cout << "Scripting and Programming Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Programmer: Hannah R Bergman" << endl;
    cout << "---------------------------------------------" << endl << endl;
    
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Hannah,Bergman,hbergm3@wgu.edu,30,7,7,30,SOFTWARE"
    };
    
    const int totalStudents = 5;

    Roster classRoster; //create instance of Roster class 'classRoster'
    
    classRoster.parseArray(studentData); //add ea student to 'classRoster'
   
    cout << "DISPLAYING ALL STUDENTS: " << endl;
    
    classRoster.printAll();
    cout << endl;
    
    classRoster.printInvalidEmails();
    cout << endl;

    //loop through classRoster array
    cout << "AVERAGE DAYS IN COURSES FOR EACH STUDENT: " << endl;
    for (int i = 0; i < totalStudents; i++) classRoster.printAverageDaysInCourse(classRoster.getStudent()[i]->getstudentID());
    cout << endl;
    
    //print by degree program, software degrees
    cout << "STUDENTS IN THE SOFTWARE DEGREE PROGRAM: " << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    
   //remove student A3
    cout << "!! REMOVING STUDENT A3 !!" << endl;
    classRoster.removeStudent("A3");
    cout << endl;
    
    //print all students
    cout << "DISPLAYING ALL STUDENTS: " << endl;
    classRoster.printAll();
    cout << endl;
    classRoster.removeStudent("A3");
    //expected: the above line should print a message saying such a student with this ID was not found
    
//implement the destructor to release memory allocated dynamically in Roster
    char exitSign = 'a';
        while (exitSign != 'q') {
            cout << endl << "Please enter 'q' to quit";
            cin >> exitSign;
            cout << endl << endl;
        }
    
     return 0;
}
