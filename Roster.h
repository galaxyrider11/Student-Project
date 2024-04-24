#ifndef ROSTER_H
#define ROSTER_H
#include "Student.h"
using namespace std;

class Roster {
    public:
        Roster(string studentData[5]);
        void ParseData(string studentData[5]);
        void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
        void Remove();
        void PrintAll();
        void PrintAverageDaysInClass(string studentID);
        void PrintInvalidEmails();
        void PrintByDegreeProgram(Degree degree);
    private:
        Student* classRosterArray[5];
};

#endif
