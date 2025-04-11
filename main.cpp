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

	cout << "Programming Language Used: C++\n";
	cout << "Student ID: 012293932\n";
	cout << "Student Name: Vincent Shipley\n";
	cout << endl;

	// Print the initial class roster
	cout << "Initial Class Roster:\n";
	classRoster.printAll();

	bool running = true;
	string command;


	while (running) {
		cout << "What would you like to do?\n";
		cout << "Options:\n";
		cout << "1. Add a student\n";
		cout << "2. Remove a student\n";
		cout << "3. Print Single Student\n";
		cout << "4. Print all students\n";
		cout << "5. Exit\n";
		cout << "6. Print average days in course for a student\n";
		cout << "7. Print all invalid emails in the roster list\n";
		cout << "8. Print by degree program\n";
		cout << "Enter your command: ";

		getline(cin, command);


		if (command == "1") {
			string studentInfo;
			cout << "Enter student information: ";
			getline(cin, studentInfo);
			classRoster.add(studentInfo);
		}
		else if (command == "2") {
			string studentID;
			cout << "Enter student ID to remove: ";
			getline(cin, studentID);
			classRoster.remove(studentID);
		}
		else if (command == "3") {
			string studentID;
			cout << "Enter student ID to print: ";
			getline(cin, studentID);
			classRoster.printStudent(studentID);
		}
		else if (command == "4") {
			classRoster.printAll();
		}
		else if (command == "5") {
			running = false;
			cout << "Exiting program.\n";
		}
		else if (command == "6") {
			string studentID;
			cout << "Enter student ID to print average days in course: ";
			getline(cin, studentID);
			int averageDays = classRoster.printAverageDays(studentID);
			if (averageDays != -1) {
				cout << "Average days in course for student " << studentID << ": " << averageDays << endl;
			}
		}
		else if (command == "7") {
			classRoster.printInvalidEmails();
		}
		else if (command == "8") {
			string input;
			cout << "Enter degree program (SECURITY, NETWORK, SOFTWARE): ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, input);

			if (input == "SECURITY") {
				classRoster.printByDegreeProgram("SECURITY");
			}
			else if (input == "NETWORK") {
				classRoster.printByDegreeProgram("NETWORK");
			}
			else if (input == "SOFTWARE") {
				classRoster.printByDegreeProgram("SOFTWARE");
			}
			else {
				cout << "Invalid degree program.\n";
			}
		}

		else {
			cout << "Invalid command.\n";
		}
	}

	return 0;

};