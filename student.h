#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "degree.h"


using namespace std;

class StudentProfile {
	
	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		vector<int> daysToComplete;
		DegreeProgram degreeProgram;

	public:


		// Constructor
		StudentProfile(string studentData) {
			stringstream ss(studentData);
			string temp;


			//Parsers
			getline(ss, studentID, ',');

			getline(ss, firstName, ',');

			getline(ss, lastName, ',');

			getline(ss, email, ',');

			getline(ss, temp, ',');

			cout << "Converting age from: [" << temp << "]" << endl;
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
			};
		};


		// Getters
		string getStudentID() const {
			return studentID;
		};

		string getFirstName() const {
			return firstName;
		};

		string getLastName() const {
			return lastName;
		};

		string getEmail() const {
			return email;
		};

		int getAge() const {
			return age;
		};

		const vector<int>& getDaysToComplete() const {
			return daysToComplete;
		};

		string getDegreeProgram() const {
			switch (degreeProgram) {
			case DegreeProgram::SECURITY:
				return "Security";
			case DegreeProgram::NETWORK:
				return "Network";
			case DegreeProgram::SOFTWARE:
				return "Software";
			default:
				return "Unknown";
			};
		};


		//Setters
		void setStudentID(string studentID) {
			this->studentID = studentID;
		};

		void setFirstName(string firstName) {
			this->firstName = firstName;
		};

		void setLastName(string lastName) {
			this->lastName = lastName;
		};

		void setEmail(string email) {
			this->email = email;
		};

		void setAge(int age) {
			this->age = age;
		};

		void setDaysToComplete(const vector<int>& daysToComplete) {
			this->daysToComplete = daysToComplete;
		};

		void setDegreeProgram(DegreeProgram degreeProgram) {
			this->degreeProgram = degreeProgram;
		};

		// Print indivisual Student profile
		void print() {

			cout << "Student ID: " << this->getStudentID() << endl;
			cout << "Student Name: " << this->getFirstName() << " " << this->getLastName() << endl;
			cout << "Student E-mail Address: " << this->getEmail() << endl;
			cout << "Student Age: " << this->getAge() << endl;

			cout << "Days Left in Classes: ";
			for (int days : this->getDaysToComplete()) {
				cout << days << " ";
			}
			cout << endl;

			cout << "Major: " << this->getDegreeProgram() << endl;
		};

};