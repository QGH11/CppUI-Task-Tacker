#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/Task.h" 
#include <iostream>
#include <string>

using namespace std;

// task constructor 
Task::Task(string name, string startTime, string endTime) {
	taskName = name;
	taskStartTime = startTime;
	taskEndTime = endTime;
}


string Task::getName() {
	return taskName;
}

// print the task
void Task::printTask() {
	cout << "\tTask Name: " + taskName << " \n";
	cout << "\tTask StartTime: " + taskStartTime << " \n";
	cout << "\tTask EndTime: " + taskEndTime << "\n";
}