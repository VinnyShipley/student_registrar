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
	classRosterArray.back()->print();
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

};


// Pulls Student ID for printing specific profile in main
string Roster::getStudentIDAt(int index) {
	if (index >= 0 && index < static_cast<int>(classRosterArray.size()))
	{
		return classRosterArray[index]->getStudentID();
	}
	return "";
};

// Grabs Roster Size
int Roster::getClassSize() {
	return classRosterArray.size();
};


// Prints individul Student Profile
void Roster::printStudent(string studentID) {
	for (StudentProfile* student : classRosterArray) {
		if (student->getStudentID() == studentID) {
			student->print();
			return;
		};
	};
};

// Prints Roster Table
void Roster::printAll() {
	for (int i = 0; i < classRosterArray.size(); i++) {
		classRosterArray[i]->print();
	};
};

int Roster::printAverageDays(string studentID) {
	for (StudentProfile* student : classRosterArray) {
		if (student->getStudentID() == studentID) {
			int total = 0;
			for (int days : student->getDaysToComplete()) {
				total += days;
			}
			int average = total / 3;
			return average;
		}
	}
	// Student not found; return a flag value like -1
	return -1;
};

void Roster::printInvalidEmails() {
	vector<string> invalidEmails;

	for (StudentProfile* student : classRosterArray) {
		string email = student->getEmail();

		bool hasSpace = email.find(' ') != string::npos;
		bool hasAt = email.find('@') != string::npos;
		bool hasDot = email.find('.') != string::npos;

		if (hasSpace || !hasAt || !hasDot) {
			invalidEmails.push_back(email);
		}
	}

	if (invalidEmails.empty()) {
		cout << "No invalid emails found." << endl;
	}
	else {
		cout << "Invalid emails:" << endl;
		for (const string& email : invalidEmails) {
			cout << "- " << email << endl;
		}
	}
}


