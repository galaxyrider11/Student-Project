#include <iostream>
#include <sstream>
#include <string>
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

    ParseData(studentData);
}

void Roster::ParseData(string studentData[5]) {
    char delimiter = ',';
    Degree tempDegree;
    string token;
    string temp[9];
    int j;

    //Extracts each piece of data of the comma-separated list provided in main.cpp
    for(int i = 0; i < 5; ++i) {
        stringstream ss(studentData[i]);

        j = 0;

        while(getline(ss, token, delimiter)) {
            temp[j] = token;
            ++j;
        }

        //Converts the enum data type to a string so it can be sent to the Add method
        tempDegree = temp[8] == "SECURITY" ? SECURITY : ( temp[8] == "NETWORK" ? NETWORK : SOFTWARE );
        //
        Add(temp[0], temp[1], temp[2], temp[3], stoi(temp[4]), stoi(temp[5]), stoi(temp[6]), stoi(temp[7]), tempDegree);
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

void Roster::Remove() {
    
}

void Roster::PrintAll() {
    for (int i = 0; i < 5; ++i) {
        classRosterArray[i]->Print();
    }
}

void Roster::PrintAverageDaysInClass() {

}

void Roster::PrintInvalidEmails() {

}

void Roster::PrintByDegreeProgram() {
    
}