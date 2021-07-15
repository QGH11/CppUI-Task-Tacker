#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>


using namespace std;

class Task {
	public: 
		Task(string name, string startTime, string endTime);
		void printTask();
		string getName();

	private: 
		string taskName;
		string taskStartTime;
		string taskEndTime;

};

#endif
