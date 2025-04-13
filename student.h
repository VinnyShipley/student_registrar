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


		//Setters
		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmail(string email);
		void setAge(int age);
		void setDaysToComplete(const vector<int>& daysToComplete);
		void setDegreeProgram(DegreeProgram degreeProgram);


		// Getters
		string getStudentID() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmail() const;
		int getAge() const;
		vector<int> getDaysToComplete() const;
		string getDegreeProgramString() const;
		DegreeProgram getDegreeProgram() const;

		

		// Print individual student profile
		void print();

};