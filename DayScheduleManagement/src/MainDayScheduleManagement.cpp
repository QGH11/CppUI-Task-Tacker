/*	Project Name: One day Schedule Management
*	Author: QGH
*	Functionality:	1.	Allow users to add or delete schedules
					2.	Allow users to add or delete tasks
*/

#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/DaySchedule.h"
#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/Task.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// global schedule vector
vector<DaySchedule> scheduleList;

int mainMenu();
void createDay();
void deleteDay();
int getScheduleListIndex(string target);
void modifyDay();
void printScheduleList();

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

	DaySchedule day(scheduleName);
	scheduleList.push_back(day);

	printScheduleList();
}

// delete a day schedule
void deleteDay() {
	printScheduleList();
	string scheduleName;

	// find and delete day
	do {
		cout << "Schedule Name (delete): ";
		cin >> scheduleName;

		int index = getScheduleListIndex(scheduleName);
		if (index > -1) {
			scheduleList.erase(scheduleList.begin()+index);
			cout << "Your one day schedule (" + scheduleName + ") has been deleted!\n\n";
		}
		else {
			cout << "Error: scheduleList undefined, please try again!\n";
		}

	} while (getScheduleListIndex(scheduleName) != -1);

}

// return the target schedule #index
int getScheduleListIndex(string target) {
	vector<DaySchedule>::iterator it;
	for (it = scheduleList.begin(); it < scheduleList.end(); it++) {
		int ith = it - scheduleList.begin();
		if (scheduleList[ith].getName().compare(target) == 0 ){
			return ith;
		}
	}

	return -1;
}

// modify existing day
void modifyDay() {

	printScheduleList();

	// print the day first
	string scheduleName;

	do {
		cout << "Schedule Name (modify): ";
		cin >> scheduleName;

		int index = getScheduleListIndex(scheduleName);
		// print the schedule first 
		scheduleList[index].printSchedule();
		if (index > -1) {	

			bool stopAction = true;

			// provide options
			while (stopAction) {

				// ask for option
				int userOption;
				do {
					cout << "You can now start modify your schedule!\n";
					cout << "\t1. Add tasks\n";
					cout << "\t2. Delete tasks\n";
					cout << "\t3. Quit modifying\n";
					cout << "Your option: ";
					cin >> userOption;
					cout << "\n";

					while (cin.fail())
					{
						// user didn't input a number
						cin.clear(); // reset failbit
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); //skip bad input
						// next, request user reinput
						cout << "You can now start modify your schedule!\n";
						cout << "1. Add tasks\n";
						cout << "2. Delete Tasks\n";
						cout << "3. Quit modifying\n";
						cout << "Your option: ";
						// if user input is not right, warning and ask again
						cin >> userOption;
						cout << "\n";
					}

					if (userOption < 1 || userOption > 3) {
						cout << "Error: No such option, please try again!\n";
					}

				} while (userOption < 1 || userOption > 3);
				
				// add task
				if (userOption == 1) {
					scheduleList[index].addTask();
					scheduleList[index].printSchedule();
				}
				// delete task
				else if (userOption == 2) {
					scheduleList[index].printSchedule();
					scheduleList[index].deleteTask();
				}
				else {
					stopAction = false;
				}
			} 
		}
		else {
			cout << "Error: scheduleList undefined, please try again!\n";
		}

	} while (getScheduleListIndex(scheduleName) == -1);
}

// print the scheduleList
void printScheduleList() {
	cout << "---------------------------------\n";
	cout << "Schedule List: \n";
	for (int i = 0; i < scheduleList.size(); i++) {
		cout << "\t"+ scheduleList[i].getName() << "\n";
	}
	cout << "---------------------------------\n\n";
}

int main() {

	bool programStopper = true;
	do {
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
				modifyDay();
				break;

			// quit program
			case 4: 
				programStopper = false;
				break;
		}
	} while (programStopper);
}