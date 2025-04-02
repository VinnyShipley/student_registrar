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

	void add(string studentData);
	void remove(string studentID);
	void printAll();
};