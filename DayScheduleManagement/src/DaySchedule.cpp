#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/DaySchedule.h" 
#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/Task.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// one day schedule constructor 
DaySchedule::DaySchedule(string name) {
	scheduleName = name;
	cout << "Your one day schedule (" + scheduleName + ") is ready!";
}

DaySchedule::~DaySchedule() {
	cout << "Your one day schedule (" + scheduleName + ") has been deleted!";
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

void DaySchedule::printSchedule() {
	for (int i = 0; i < day.size(); i++) {
		day[i].printTask();
	}
}