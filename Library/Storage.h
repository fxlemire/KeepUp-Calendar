//@author A0121007A
/*
This class manages all storing operations on the hard drive, i.e. save and load.
*/
#ifndef STORAGE_H
#define STORAGE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Task.h"
#include "Utility.h"
#include <Windows.h>

using namespace std;

class Storage {
public:
	//@author A0121007A
	/* file path */
	static const string USER_LOCATION;
	static const string FOLDER_LOCATION;
	static const string FILE_EXTENSION;

	//@author A0121007A
	/* storage messages */
	static const string FILE_OPEN_ERROR;
	static const string FILE_TASK_SEPARATOR;
	static const string MESSAGE_CORRUPTED;
	static const string MESSAGE_LOADING;
	static const string MESSAGE_LOADED;
	static const string MESSAGE_SAVING;
	static const string MESSAGE_SAVED;
	static const string MESSAGE_WAITING_SYMBOL;

	//@author A0121007A
	/* main storage methods */
	/* save takes the calendarName as a fileName and a vector of the tasks to be saved */
	static bool save(string calName, vector<Task> tasks);
	/* load takes calendar string as fileName and a calendar pointer to store loaded tasks into */
	static bool load(string calendar, Calendar *cal);

	//@author A0121007A
	/* storage specific helper methods */
	static bool isExistingDirectory(string dir);
	static string getCalendarLocation(string calName);
	static void createDirectory();
};
#endif


//@author A0090968M
//Original version of storage

//#ifndef STORAGE_H
//#define STORAGE_H

//#include <fstream>
//#include <iostream>
//#include <atlpath.h>
//#include <string>
//using namespace std;

//class storage
//{
//public:
//	string Calendar;
//	int startYear;
//	int startMonth;
//	int startDate;
//	int startHour;
//	int startMinute;
//	int endYear;
//	int endMonth;
//	int endDate;
//	int endHour;
//	int endMinute;
//	int Task;

//	void print()
//	{
//		cout << startYear << " " << startMonth << " " << startDate << " " << startHour << " " << startMinute << " " << Task << endl;
//	}
//};
//#endif