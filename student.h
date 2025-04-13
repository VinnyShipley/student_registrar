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
		StudentProfile(string studentData);


		// Getters
		string getStudentID() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmail() const;
		int getAge() const;
		vector<int> getDaysToComplete() const;
		string getDegreeProgramString() const;
		DegreeProgram getDegreeProgram() const;

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
		void print();

};