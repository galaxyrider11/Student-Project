#include <iostream>
#include <sstream>
#include <string>
#include <regex>
#include "Roster.h"
#include "Student.h"
using namespace std;

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

Roster::~Roster() {
}

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
        //
        Add(temp[0], temp[1], temp[2], temp[3], stoi(temp[4]),
			stoi(temp[5]), stoi(temp[6]), stoi(temp[7]), tempDegree);
    }
}

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

void Roster::Remove(string studentID) {
	bool found = false;
	
	for(int i = 0; i < rosterSize; i++) {
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

void Roster::PrintAll() {
	//Prints every
    for (Student* student : classRosterArray) {
		if(student != NULL) {
			student->Print();
		}
    }
}

void Roster::PrintAverageDaysInClass(string studentID) {
	int average;
	
	for(Student* student : classRosterArray) {
		if(student->GetStudentID() == studentID) {
			int day1 = student->GetCourseDays1();
			int day2 = student->GetCourseDays2();
			int day3 = student->GetCourseDays3();
			average = (day1 + day2 + day3) / 3;
			
			cout << "Student ID: " << student->GetStudentID() << ", averagde days in course is: ";
			cout << average << endl;
		}
	}
}

void Roster::PrintInvalidEmails() {
	regex pattern("(\\w*\\W*\\.?\\w*\\W*@\\w*\\W*\\.\\w*)");
	
	for(Student* student : classRosterArray) {
		string email = student->GetStudentEmail();
		
		if(!regex_match(email, pattern)) {
			cout << email << "\t : invalid" << endl;
		}
	}
}

void Roster::PrintByDegreeProgram(Degree degree) {
	string degreeString = (degree == 0 ? "SECURITY" : ( degree == 1 ? "NETWORK" : "SOFTWARE" ));
	
	for(Student* student : classRosterArray) {
		if(student->GetDegree() == degreeString) {
			student->Print();
		}
	}
}
