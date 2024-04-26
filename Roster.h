/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\
|	Author:	Brandon Owen													|
|	Date:	04/20/24														|
|	File:	Roster.h														|
|	Class:	C867 Scripting and Programming - Applications					|
|	Use:	Stores, modifies, and prints student objects stored in			|
|			an array of pointers. There are 6 files total for this			|
|			project.														|
|			This file is the header file for the Roster class and			|
|			holds the constructor and destructor for that class				|
\+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
#ifndef ROSTER_H
#define ROSTER_H
#include "Student.h"
using namespace std;

class Roster {
    public:
        Roster(string studentData[5]);
		~Roster();
        void ParseData(string studentData[5]);
        void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
        void Remove(string studentID);
        void PrintAll();
        void PrintAverageDaysInClass(string studentID);
        void PrintInvalidEmails();
        void PrintByDegreeProgram(Degree degree);
    private:
        Student* classRosterArray[5];
		int rosterSize;
};

#endif
