#pragma once

#include "student.h"

#include <string>
#include <vector>



using namespace std;


class Roster {

private:
	vector<StudentProfile*> classRosterArray;
	int studentCount;
	
public:
	Roster(const string studentData[], int size);
	~Roster();

	string getStudentIDAt(int index);
	int getClassSize();


	void add(string studentData);
	void remove(string studentID);
	void printStudent(string studentID);
	void printAll();
	int printAverageDays(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(string degreeString);
};