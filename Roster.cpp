/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\
|	Author:	Brandon Owen													|
|	Date:	04/20/24														|
|	File:	Roster.cpp														|
|	Class:	C867 Scripting and Programming - Applications					|
|	Use:	Stores, modifies, and prints student objects stored in			|
|			an array of pointers. There are 6 files total for this			|
|			project.														|
|			This file is the implementation file for the Roster class		|
|			and holds all the functions and data for that class				|
\+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include "Roster.h"
#include "Student.h"
using namespace std;

//---------------------------------------------------------------------------
//			Constructor for the Roster class
//				Takes an array of comma separated strings as input
//---------------------------------------------------------------------------
Roster::Roster(string studentData[5]) {
    //Assigns each index of the classRosterArray with the address of a unique Student object
    classRosterArray[0] = new Student();
    classRosterArray[1] = new Student();
    classRosterArray[2] = new Student();
    classRosterArray[3] = new Student();
    classRosterArray[4] = new Student();
	
	//Divides the size (in bytes) of the array by the number of bytes in each student object
	//This gives us the number of indexes in the array which we use for array iteration later
	rosterSize = sizeof(classRosterArray) / sizeof(Student*);
	
    ParseData(studentData);
}

//---------------------------------------------------------------------------
//			Destructor for the Roster class
//---------------------------------------------------------------------------
Roster::~Roster() {
	
}

//---------------------------------------------------------------------------
//			ParsData() function
//				Takes an array of comma separated strings as input
//				Separates the values into individual strings and ints
//				These are sent to the Add function to be added to the roster
//---------------------------------------------------------------------------
void Roster::ParseData(string studentData[5]) {
    char delimiter = ',';
    Degree tempDegree;
    string token;
    string temp[9];
    int j;

    //Extracts each piece of data of the comma-separated list provided in main.cpp
	//and saves each part in the string array temp[]
    for(int i = 0; i < rosterSize; ++i) {
        stringstream ss(studentData[i]);

        j = 0;

        while(getline(ss, token, delimiter)) {
            temp[j] = token;
            ++j;
        }

        //Converts the enum data type to a string so it can be sent to the Add method
        tempDegree = (temp[8] == "SECURITY" ? SECURITY : ( temp[8] == "NETWORK" ? NETWORK : SOFTWARE));
        //Sends the pieces of data extracted from the stringstream to be added to the Student Roster
        Add(temp[0], temp[1], temp[2], temp[3], stoi(temp[4]),
			stoi(temp[5]), stoi(temp[6]), stoi(temp[7]), tempDegree);
    }
}

//---------------------------------------------------------------------------
//			Add() function
//				Takes a collections of strings and ints as input
//				Those values are then set for the Student object
//---------------------------------------------------------------------------
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
    //Extracts the index of the pointer array it needs to modify from the student ID number
    int index = stoi(studentID.substr(1,1));
    
    //Subtracts 1 from index since IDs start at 1, and the index of arrays starts at 0
    classRosterArray[index-1]->SetStudentID(studentID);
    classRosterArray[index-1]->SetFirstName(firstName);
    classRosterArray[index-1]->SetLastName(lastName);
    classRosterArray[index-1]->SetStudentEmail(emailAddress);
    classRosterArray[index-1]->SetStudentAge(age);
    classRosterArray[index-1]->SetNumCourseDays(daysInCourse1, daysInCourse2, daysInCourse3);
    classRosterArray[index-1]->SetDegree(degree);
}

//---------------------------------------------------------------------------
//			Remove() function
//				Takes a Student ID as a string input
//				Removes the Student object that matches that ID
//---------------------------------------------------------------------------
void Roster::Remove(string studentID) {
	bool found = false;
	
	for(int i = 0; i < rosterSize; i++) {
		//Only deletes the Student object if it isn't already NULL
		if(classRosterArray[i] != NULL && classRosterArray[i]->GetStudentID() == studentID) {
			classRosterArray[i]->~Student();
			classRosterArray[i] = nullptr;
			delete classRosterArray[i];
			found = true;
		}
	}
	
	if(!found) {
		cout << "The student with ID " << studentID << " was not found." << endl;
	}
}

//---------------------------------------------------------------------------
//			PrintAll() function
//				Takes no input
//				Calls the Print() function of every Student object
//---------------------------------------------------------------------------
void Roster::PrintAll() {
	//Prints every student object that isn't null
    for (Student* student : classRosterArray) {
		if(student != NULL) {
			student->Print();
		}
    }
}

//---------------------------------------------------------------------------
//			PrintAverageDaysInClass() function
//				Takes a Student ID as a string input
//				Calcuates the average days for that student
//				Prints that average to standard out
//---------------------------------------------------------------------------
void Roster::PrintAverageDaysInClass(string studentID) {
	int average;
	
	//Iterate through each student object in the array of pointers
	for(Student* student : classRosterArray) {
		//Only calculates the average for the provided student ID
		if(student->GetStudentID() == studentID) {
			int day1 = student->GetCourseDays1();
			int day2 = student->GetCourseDays2();
			int day3 = student->GetCourseDays3();
			//Actual average calculation
			average = (day1 + day2 + day3) / 3;
			
			cout << "Student ID: " << student->GetStudentID() << ", averagde days in course is: ";
			cout << average << endl;
		}
	}
}

//---------------------------------------------------------------------------
//			PrintInvalidEmails() function
//				Takes no input
//				Uses regex to determine if Student emails are valid
//				Prints invalid emails to standard out
//---------------------------------------------------------------------------
void Roster::PrintInvalidEmails() {
	//Creates a pattern x@x.x to compare with the email addresses
	//The characters on either side of the @ can contain letters, numbers, and symbols
	//The characters after the required period can only contain letters and numbers
	regex pattern("(\\w*\\W*\\.?\\w*\\W*@\\w*\\W*\\.\\w*)");
	
	for(Student* student : classRosterArray) {
		string email = student->GetStudentEmail();
		
		if(!regex_match(email, pattern)) {
			cout << email << "\t : invalid" << endl;
		}
	}
}

//---------------------------------------------------------------------------
//			PrintByDegreeProgram() function
//				Takes an enum Degree input
//				Prints Students with that degree to standard out
//---------------------------------------------------------------------------
void Roster::PrintByDegreeProgram(Degree degree) {
	string degreeString;
	
	//Gets the string value of the enum Degree
	switch(degree) {
		case 0: degreeString = "SECURITY";
		case 1: degreeString = "NETWORK";
		case 2: degreeString = "SOFTWARE";
	}
	
	//Only prints student objects whose degrees match the provided parameter
	for(Student* student : classRosterArray) {
		if(student->GetDegree() == degreeString) {
			student->Print();
		}
	}
}
