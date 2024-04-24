#ifndef STUDENT_H
#define STUDENT_H
#include "Degree.h"
#include <string>

using namespace std;

class Student {
    public:
        Student();
        Student(string studentID, string firstName, string lastName, string studentEmail, int studentAge, int courseDays1, int courseDays2, int courseDays3, Degree degreeProgram);
        string GetStudentID();
        string GetFirstName();
        string GetLastName();
        string GetStudentEmail();
        int GetStudentAge();
        int GetCourseDays1();
		int GetCourseDays2();
		int GetCourseDays3();
		string GetNumCourseDays();
        string GetDegree();
        void SetStudentID(string studentID);
        void SetFirstName(string newFirstName);
        void SetLastName(string newLastName);
        void SetStudentEmail(string newEmail);
        void SetStudentAge(int newAge);
        void SetNumCourseDays(int courseDays1, int courseDays2, int courseDays3);
        void SetDegree(Degree newDegree);
        void Print();
    private:
        string studentID;
        string firstName;
        string lastName;
        string studentEmail;
        int studentAge;
        int numCourseDays[3];
        Degree degreeProgram;
};

#endif
