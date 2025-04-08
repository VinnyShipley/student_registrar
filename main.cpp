#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;


int main() {


	const string studentData[] = { 
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
	};

	Roster classRoster(studentData, 4);

	cout << "Initial Class Roster:\n";
	classRoster.printAll();

	return 0;

};