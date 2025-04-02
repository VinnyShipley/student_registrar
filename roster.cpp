#include <iostream>
#include <string>
#include "roster.h"


using namespace std;


Roster::Roster(const string studentData[], int size) {
	for (int i = 0; i < size; i++) {
		classRosterArray.push_back(new StudentProfile(studentData[i]));
	};
}

Roster::~Roster() {
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		delete classRosterArray[i];
	}
}

// Adds a student to ClassRoster Array

void Roster::add(string studentData) {
	classRosterArray.push_back(new StudentProfile(studentData));
	cout << "Student added: ";
	classRosterArray.back()->print(*classRosterArray.back());
}


//Removes a student from ClassRoster Array
void Roster::remove(string studentID) {
	bool found = false;

	for (size_t i = 0; i < classRosterArray.size(); i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray.erase(classRosterArray.begin() + i);
			found = true;
			cout << "Student " << studentID << " removed." << endl;
			break;
		};
	};

		if (!found) {
			cout << "Error: Student with ID " << studentID << " not found." << endl;
		};

}


// Prints Roster Table
void Roster::printAll() {
	for (int i = 0; classRosterArray.size(); i++) {
		classRosterArray[i]->print(*(classRosterArray[i]));
	};
};