/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\
|	Author:	Brandon Owen													|
|	Date:	04/20/24														|
|	File:	Student.cpp														|
|	Class:	C867 Scripting and Programming - Applications					|
|	Use:	Stores, modifies, and prints student objects stored in			|
|			an array of pointers. There are 6 files total for this			|
|			project.														|
|			This file is the implementation file for the Student class		|
|			and holds all the functions and data for that class				|
\+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
#include <iostream>
#include <string>
#include <cstdio>
#include "Student.h"
using namespace std;

//---------------------------------------------------------------------------
//			Default constructor for the Student class
//---------------------------------------------------------------------------
Student::Student() {
    this->studentID = "0000";
    this->firstName = "Test";
    this->lastName = "Account";
    this->studentEmail = "test@none.com";
    this->studentAge = 18;
    this->SetNumCourseDays(0, 0, 0);
    this->degreeProgram = SECURITY;
}

//---------------------------------------------------------------------------
//			Custom constructor for the Student class
//---------------------------------------------------------------------------
Student::Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int courseDays1, int courseDays2, int courseDays3, Degree degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->studentEmail = studentEmail;
    this->studentAge = studentAge;
    this->SetNumCourseDays(courseDays1, courseDays2, courseDays3);
    this->degreeProgram = degreeProgram;
}

//---------------------------------------------------------------------------
//			Destructor for the Student class
//---------------------------------------------------------------------------
Student::~Student() {
	
}

//---------------------------------------------------------------------------
//			GetStudentID() function
//				Takes no input
//				Returns the student's ID string
//---------------------------------------------------------------------------
string Student::GetStudentID() {
    return studentID;
}

//---------------------------------------------------------------------------
//			GetFirstName() function
//				Takes no input
//				Returns the student's first name string
//---------------------------------------------------------------------------
string Student::GetFirstName() {
    return firstName;
}

//---------------------------------------------------------------------------
//			GetLastName() function
//				Takes no input
//				Returns the student's first name string
//---------------------------------------------------------------------------
string Student::GetLastName() {
    return lastName;
}

//---------------------------------------------------------------------------
//			GetStudentEmail() function
//				Takes no input
//				Returns the student's email string
//---------------------------------------------------------------------------
string Student::GetStudentEmail() {
    return studentEmail;
}

//---------------------------------------------------------------------------
//			GetStudentAge() function
//				Takes no input
//				Returns the student's age int
//---------------------------------------------------------------------------
int Student::GetStudentAge() {
    return studentAge;
}

//---------------------------------------------------------------------------
//			GetCourseDays1() function
//				Takes no input
//				Returns the student's first course day int
//---------------------------------------------------------------------------
int Student::GetCourseDays1() {
	return this->numCourseDays[0];
}

//---------------------------------------------------------------------------
//			GetCourseDays2() function
//				Takes no input
//				Returns the student's second course day int
//---------------------------------------------------------------------------
int Student::GetCourseDays2() {
	return this->numCourseDays[1];
}

//---------------------------------------------------------------------------
//			GetCourseDays3() function
//				Takes no input
//				Returns the student's third course day int
//---------------------------------------------------------------------------
int Student::GetCourseDays3() {
	return this->numCourseDays[2];
}

//---------------------------------------------------------------------------
//			GetNumCourseDays() function
//				Takes no input
//				Returns the student's 3 course days as a string
//---------------------------------------------------------------------------
string Student::GetNumCourseDays() {
	string returnString = "[";
	
	returnString += to_string(this->GetCourseDays1()) + ",";
	returnString += to_string(this->GetCourseDays2()) + ",";
	returnString += to_string(this->GetCourseDays3()) + "]";
	
	return returnString;
}

//---------------------------------------------------------------------------
//			GetDegree() function
//				Takes no input
//				Returns the student's degree as a string
//---------------------------------------------------------------------------

string Student::GetDegree() {
	//Converts the enumerated data type to a string since we can only access its index normally
	switch(degreeProgram) {
		case 0: return "SECURITY";
		case 1: return "NETWORK";
		case 2: return "SOFTWARE";
	}
}

//---------------------------------------------------------------------------
//			SetNumCourseDays() function
//				Takes 3 integers as input
//				Sets the course days for that student
//---------------------------------------------------------------------------
void Student::SetNumCourseDays(int courseDays1, int courseDays2, int courseDays3) {
    this->numCourseDays[0] = courseDays1;
    this->numCourseDays[1] = courseDays2;
    this->numCourseDays[2] = courseDays3;
}

//---------------------------------------------------------------------------
//			SetStudentID() function
//				Takes a string as input
//				Sets the student's ID with that string
//---------------------------------------------------------------------------
void Student::SetStudentID(string studentID) {
    this->studentID = studentID;
}

//---------------------------------------------------------------------------
//			SetFirstName() function
//				Takes a string as input
//				Sets the student's first name with that string
//---------------------------------------------------------------------------
void Student::SetFirstName(string newFirstName) {
    firstName = newFirstName;
}

//---------------------------------------------------------------------------
//			SetLastName() function
//				Takes a string as input
//				Sets the student's last name with that string
//---------------------------------------------------------------------------
void Student::SetLastName(string newLastName) {
    lastName = newLastName;
}

//---------------------------------------------------------------------------
//			SetStudentEmail() function
//				Takes a string as input
//				Sets the student's email with that string
//---------------------------------------------------------------------------
void Student::SetStudentEmail(string newEmail) {
    studentEmail = newEmail;
}

//---------------------------------------------------------------------------
//			SetStudentAge() function
//				Takes an int as input
//				Sets the student's age with that string
//---------------------------------------------------------------------------
void Student::SetStudentAge(int newAge) {
    studentAge = newAge;
}

//---------------------------------------------------------------------------
//			SetDegree() function
//				Takes a string as input
//				Sets the student's degree with that Degree
//---------------------------------------------------------------------------
void Student::SetDegree(Degree newDegree) {
    degreeProgram = newDegree;
}

//---------------------------------------------------------------------------
//			Print() function
//				Takes no input
//				Prints the student information to standard out
//				Using tabs is messy with different length strings
//				 so I used formatted printing instead, but left the
//				 tab version commented out so you could see how I did it
//---------------------------------------------------------------------------
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
