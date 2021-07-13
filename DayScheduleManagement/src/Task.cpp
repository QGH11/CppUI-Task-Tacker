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

// print the task
void Task::printTask() {
	cout << taskName << " " << taskStartTime << " " << taskEndTime;
}