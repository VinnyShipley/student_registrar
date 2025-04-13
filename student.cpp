#include <iostream>
#include <string>
#include <sstream>
#include "student.h"
#include <vector>

using namespace std;

//Constructor
StudentProfile::StudentProfile(string studentData) {
	stringstream ss(studentData);
	string temp;


	//Parsers
	getline(ss, studentID, ',');
	getline(ss, firstName, ',');
	getline(ss, lastName, ',');
	getline(ss, email, ',');
	getline(ss, temp, ',');
	

	try {
		age = stoi(temp);
	}
	catch (const invalid_argument& e) {
		cerr << "Invalid argument: " << e.what() << " for value: " << temp << endl;
		age = 0;
	}
	catch (const out_of_range& e) {
		cerr << "Out of range: " << e.what() << " for value: " << temp << endl;
		age = 0;
	}

	while (getline(ss, temp, ',')) {
		if (temp == "SECURITY" || temp == "NETWORK" || temp == "SOFTWARE") {
			if (temp == "SECURITY") degreeProgram = DegreeProgram::SECURITY;
			else if (temp == "NETWORK") degreeProgram = DegreeProgram::NETWORK;
			else if (temp == "SOFTWARE") degreeProgram = DegreeProgram::SOFTWARE;
			break;
		}
		else {
			daysToComplete.push_back(stoi(temp));
		};
	}
};

//Getters
string StudentProfile::getStudentID() const {
	return this->studentID;
}

string StudentProfile::getFirstName() const {
	return this->firstName;
}

string StudentProfile::getLastName() const {
	return this->lastName;
}

string StudentProfile::getEmail() const {
	return this->email;
}

int StudentProfile::getAge() const {
	return this->age;
}

vector<int> StudentProfile::getDaysToComplete() const {
	return this->daysToComplete;
}

DegreeProgram StudentProfile::getDegreeProgram() const {
	return this->degreeProgram;
}

string StudentProfile::getDegreeProgramString() const {
	return degreeProgramToString(this->degreeProgram);
}



void StudentProfile::print() {

	cout << "Student ID: " << getStudentID() << endl;
	cout << "Student Name: " << getFirstName() << " " << this->getLastName() << endl;
	cout << "Student E-mail Address: " << getEmail() << endl;
	cout << "Student Age: " << getAge() << endl;

	cout << "Days Left in Classes: ";
	for (int days : getDaysToComplete()) {
		cout << days << " ";
	}
	cout << endl;

	cout << "Major: " << getDegreeProgram() << endl;
	cout << endl;
};
