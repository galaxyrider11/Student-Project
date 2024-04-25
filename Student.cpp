#include <iostream>
#include <string>
#include <cstdio>
#include "Student.h"
using namespace std;


Student::Student() {
    this->studentID = "0000";
    this->firstName = "Test";
    this->lastName = "Account";
    this->studentEmail = "test@none.com";
    this->studentAge = 100;
    this->SetNumCourseDays(100, 100, 100);
    this->degreeProgram = SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int courseDays1, int courseDays2, int courseDays3, Degree degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->studentEmail = studentEmail;
    this->studentAge = studentAge;
    this->SetNumCourseDays(courseDays1, courseDays2, courseDays3);
    this->degreeProgram = degreeProgram;
}

Student::~Student() {
	
}

string Student::GetStudentID() {
    return studentID;
}

string Student::GetFirstName() {
    return firstName;
}

string Student::GetLastName() {
    return lastName;
}

string Student::GetStudentEmail() {
    return studentEmail;
}

int Student::GetStudentAge() {
    return studentAge;
}

void Student::SetNumCourseDays(int courseDays1, int courseDays2, int courseDays3) {
    this->numCourseDays[0] = courseDays1;
    this->numCourseDays[1] = courseDays2;
    this->numCourseDays[2] = courseDays3;
}

int Student::GetCourseDays1() {
	return this->numCourseDays[0];
}

int Student::GetCourseDays2() {
	return this->numCourseDays[1];
}

int Student::GetCourseDays3() {
	return this->numCourseDays[2];
}

string Student::GetNumCourseDays() {
	string returnString = "[";
	
	returnString += to_string(this->GetCourseDays1()) + ",";
	returnString += to_string(this->GetCourseDays2()) + ",";
	returnString += to_string(this->GetCourseDays3()) + "]";
	
	return returnString;
}

string Student::GetDegree() {
    //Converts the enumerated data type to a string since we can only access its index normally
	switch(degreeProgram) {
		case 0: return "SECURITY";
		case 1: return "NETWORK";
		case 2: return "SOFTWARE";
	}
}

void Student::SetStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::SetFirstName(string newFirstName) {
    firstName = newFirstName;
}

void Student::SetLastName(string newLastName) {
    lastName = newLastName;
}

void Student::SetStudentEmail(string newEmail) {
    studentEmail = newEmail;
}

void Student::SetStudentAge(int newAge) {
    studentAge = newAge;
}

void Student::SetDegree(Degree newDegree) {
    degreeProgram = newDegree;
}

void Student::Print() {
    //Prints the information from one Student instance with a tab between each piece of data
    //cout << studentID << "\t" << firstName << "\t" << lastName << "\t" << studentEmail;
    //cout << "\t" << studentAge << "\t" << this->GetNumCourseDays() << "\t" << this->GetDegree() << endl;

    //Uses printf to format the print string so all columns have the same width
    //The - in front of the numbers ensures the columns are left-aligned
    printf("%-10s %-10s %-10s %-25s %-7d %-15s %-10s \n", 
        studentID.c_str(), 
        firstName.c_str(), 
        lastName.c_str(), 
        studentEmail.c_str(), 
        studentAge, 
        this->GetNumCourseDays().c_str(), 
        this->GetDegree().c_str());
}
