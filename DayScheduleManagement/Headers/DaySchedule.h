#ifndef DAYSCHEDULE_H
#define DAYSCHEDULE_H

#include "/C&C++/CppUI/DayScheduleManagement/DayScheduleManagement/Headers/Task.h"

#include <string>
#include <vector>

using namespace std;

class DaySchedule {
	public:
		DaySchedule(string name);
		void addTask();
		void deleteTask();
		void printSchedule();
		string getName();


	private:
		vector<Task> day;
		string scheduleName;
		int getScheduleListIndex(string target);

};

#endif

