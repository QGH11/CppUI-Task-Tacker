#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/DaySchedule.h" 
#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/Task.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// one day schedule constructor 
DaySchedule::DaySchedule(string name) {
	scheduleName = name;
	cout << "Your one day schedule (" + scheduleName + ") is ready!\n\n";
}


// add task to schedule
void DaySchedule::addTask() {
	string name, startTime, endTime;
	cout << "Please set up your task by steps: \n";
		cout << "Task Name: ";
		cin >> name;

		cout << "Task Start Time (ex. 13:20, 9:30): ";
		cin >> startTime;

		cout << "Task End Time:  ";
		cin >> endTime;

	Task tempTask(name, startTime, endTime);
	
	day.push_back(tempTask);
}

// delete a task
void DaySchedule::deleteTask() {
	string name;

	// find and delete day
	do {
		cout << "Task Name (delete): ";
		cin >> name;

		int index = getScheduleListIndex(name);
		if (index > -1) {
			day.erase(day.begin() + index);
			cout << "Task (" + name + ") has been removed!\n ";
		}
		else {
			cout << "Error: scheduleList undefined, please try again!\n\n";
		}

	} while (getScheduleListIndex(name) != -1);

}

void DaySchedule::printSchedule() {
	cout << "---------------------------------\n";
	cout << "Schedule Name: " + scheduleName << "";
	for (int i = 0; i < day.size(); i++) {
		cout << "\n";
		day[i].printTask();
	}
	cout << "---------------------------------\n\n";
}

string DaySchedule::getName() {
	return scheduleName;
}

int DaySchedule::getScheduleListIndex(string target) {
	vector<Task>::iterator it;
	for (it = day.begin(); it < day.end(); it++) {
		int ith = it - day.begin();
		if (day[ith].getName().compare(target) == 0) {
			return ith;
		}
	}

	return -1;
}