/*	Project Name: One day Schedule Management
*	Author: QGH
*	Functionality:	1. Allow user to add or delete events, sort tasks in chronological order
*					2. when event overlap, suggest the next possible time
*/

#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/DaySchedule.h"
#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/Task.h"
#include <iostream>
#include <string>

using namespace std;

bool ifContinue();

bool ifContinue() {
	string decision;

	cout << "\nTo continue type \"yes\".\nTo stop type \"no\"\n";
	cin >> decision;
	cout << "\n";

	// convert string into uppercase
	for (int i = 0; i < decision.length(); i++) {
		decision[i] = toupper(decision[i]);
	}

	// check for valid input
	while (!(decision.compare("YES") == 0 || decision.compare("NO") == 0)) {
		cout << "Invalid input!\n";

		cout << "\nTo continue type \"yes\".\nTo stop type \"no\"\n";
		cin >> decision;
		cout << "\n";

		// convert string into uppercase
		for (int i = 0; i < decision.length(); i++) {
			decision[i] = toupper(decision[i]);
		}
	}

	if (decision.compare("YES")) {
		return true;
	}
	else if (decision.compare("NO")) {
		return false;
	}

}

// ask user to choose an option
int mainMenu() {
	int userOption;
	do {
		cout << "Please choose one option: \n";
		cout << "\t1. Create a new schedule.\n";
		cout << "\t2. Delete an existing schedule.\n";
		cout << "\t3. Check or modify an existing schedule.\n";
		cout << "\t4. Quit the program.\n";
		cout << "Your option (input integer 1-4): ";
		cin >> userOption;
		cout << "\n";

		while (cin.fail())
		{
			// user didn't input a number
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
			// next, request user reinput
			cout << "Please choose one option: \n";
			cout << "\t1. Create a new schedule.\n";
			cout << "\t2. Delete an existing schedule.\n";
			cout << "\t3. Check or modify an existing schedule.\n";
			cout << "\t4. Quit the program.\n";
			cout << "Your option: ";
			// if user input is not right, warning and ask again
			cin >> userOption;
			cout << "\n";
		}

		if (userOption < 1 || userOption > 4) {
			cout << "Error: No such option, please try again!\n";
		}

	} while (userOption < 1 || userOption > 4);

	return userOption;
}

// create a day schedule
void createDay() {
	string scheduleName;
	cout << "Schedule Name (create): ";
	cin >> scheduleName;
}

// delete a day schedule
void deleteDay() {
	string scheduleName;
	cout << "Schedule Name (delete): ";
	cin >> scheduleName;

	delete ;
}

int main() {
	do  {
		switch (mainMenu()) {
			// create a schedule
			case 1: 
				createDay();
				break;

			// delete a scheduel
			case 2:
				deleteDay();
				break;

			// Check or modify an existing schedule
			case 3: 
				break;

			// quit program
			case 4: 
				break;
		}
	} while (!ifContinue());
}