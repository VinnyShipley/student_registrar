#include <iostream>
#include <string>
#include <sstream>
#include "student.h"
#include <vector>

using namespace std;

//Constructor -------------------------------------------------------------------
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


//Setters------------------------------------------------------------------------
void StudentProfile::setStudentID(string studentID) {
	this->studentID = studentID;
};

void StudentProfile::setFirstName(string firstName) {
	this->firstName = firstName;
};

void StudentProfile::setLastName(string lastName) {
	this->lastName = lastName;
};

void StudentProfile::setEmail(string email) {
	this->email = email;
};

void StudentProfile::setAge(int age) {
	this->age = age;
};

void StudentProfile::setDaysToComplete(const vector<int>& daysToComplete) {
	this->daysToComplete = daysToComplete;
};

void StudentProfile::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
};




//Getters------------------------------------------------------------------------
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


//Prints Student Profile --------------------------------------------------------
void StudentProfile::print() {

	cout << "Student ID: " << getStudentID() << '\t';
	cout << "Student Name: " << getFirstName() << " " << this->getLastName() << '\t';
	cout << "Student E-mail Address: " << getEmail() << '\t';
	cout << "Student Age: " << getAge() << '\t';

	cout << "Days Left in Classes: ";
	for (int days : getDaysToComplete()) {
		cout << days << " ";
	}
	cout << '\t';

	cout << "Major: " << getDegreeProgramString() << '\t';
	cout << endl;
	cout << endl;
};
