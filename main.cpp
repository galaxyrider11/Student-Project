/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\
|	Author:	Brandon Owen													|
|	Date:	04/20/24														|
|	File:	main.cpp														|
|	Class:	C867 Scripting and Programming - Applications					|
|	Use:	Stores, modifies, and prints student objects stored in			|
|			an array of pointers. There are 6 files total for this			|
|			project.														|
|			Student.cpp and Student.h form the Student class.				|
|			Roster.cpp and Roster.h form the Roster class.					|
|			Degree.h stores the custome enum data type for degrees.			|
|																			|
|	Run:	g++ -std=c++11 main.cpp Student.cpp Roster.cpp -o main			|
\+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
#include "Student.h"
#include "Degree.h"
#include "Roster.h"
#include <iostream>
using namespace std;

void PrintHeader() {
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 012098634" << endl;
	cout << "Name: Brandon Owen" << endl << endl;
}

int main() {
    string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Brandon,Owen,bowe208@wgu.edu,31,10,12,15,SOFTWARE"};
	
	//Initialize the array of pointers for the student objects
    Roster studentRoster(studentData);
	
	PrintHeader();
	
	cout << "Displaying all students:" << endl;
	studentRoster.PrintAll();
	cout << endl;
	
	cout << "Displaying invalid emails:" << endl;
	studentRoster.PrintInvalidEmails();
	cout << endl;
	
	cout << "Displaying average days in course:" << endl;
	studentRoster.PrintAverageDaysInClass("A1");
	studentRoster.PrintAverageDaysInClass("A2");
	studentRoster.PrintAverageDaysInClass("A3");
	studentRoster.PrintAverageDaysInClass("A4");
	studentRoster.PrintAverageDaysInClass("A5");
	cout << endl;
	
	cout << "Showing students in degree program: SOFTWARE" << endl;
	studentRoster.PrintByDegreeProgram(SOFTWARE);
	cout << endl;
	
	cout << "Removing A3:" << endl;
	studentRoster.Remove("A3");
	studentRoster.PrintAll();
	cout << endl;
	
	cout << "Removing A3 again:" << endl;
	studentRoster.Remove("A3");
	cout << endl;
	
	cout << "DONE" << endl;

    return 0;
}
