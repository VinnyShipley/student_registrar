#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;


int main() {


	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY" };

	Roster classRoster(studentData, 4);

	// Print the initial class roster
	cout << "Initial Class Roster:\n";
	classRoster.printAll();

	bool running = true;
	string command;


	while (running) {
		cout << "What would you like to do?\n";
		cout << "Options:\n";
		cout << "1. Add a student: Add\n";
		cout << "2. Remove a student: Remove \n";
		cout << "3. Print Single Student: Print \n";
		cout << "3. Print all students: Print All\n";
		cout << "4. Exit: Exit\n";

		getline(cin, command);


		if (command == "Add") {
			string studentInfo;
			cout << "Enter student information: ";
			getline(cin, studentInfo);
			classRoster.add(studentInfo);
		}
		else if (command == "Remove") {
			string studentID;
			cout << "Enter student ID to remove: ";
			getline(cin, studentID);
			classRoster.remove(studentID);
		}
		else if (command == "Print") {
			string studentID;
			cout << "Enter student ID to print: ";
			getline(cin, studentID);
			classRoster.printStudent(studentID);
		}
		else if (command == "Print All") {
			classRoster.printAll();
		}
		else if (command == "Exit") {
			running = false;
			cout << "Exiting program.\n";
		}
		else {
			cout << "Invalid command.\n";
		}
	}

	return 0;

};