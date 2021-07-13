#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task {
	public: 
		Task(string taskName, string taskStartTime, string taskEndTime);
		void printTask();

	private: 
		string taskName;
		string taskStartTime;
		string taskEndTime;

};

#endif
