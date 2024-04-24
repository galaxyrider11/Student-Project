#include "Student.h"
#include "Degree.h"
#include "Roster.h"
#include <iostream>
using namespace std;

int main() {
    string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brandon,Owen,bowe208@wgu.edu,31,10,12,15,SOFTWARE"};

    //Student testStudent1("1234", "Bob", "Jones", "gay@gay.com", 25, 1, 2, 3, NETWORK);
    //Student testStudent2;

    Roster studentRoster(studentData); 
    studentRoster.PrintAll();

    //testStudent1.Print();
    //testStudent2.Print();

    return 0;
}