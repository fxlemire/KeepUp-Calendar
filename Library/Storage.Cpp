//@author A0121007A
#include "Storage.h"

//@author A0121007A
const string Storage::USER_LOCATION = "C:\\Users\\";
const string Storage::FOLDER_LOCATION = "\\Documents\\KeepUp\\";
const string Storage::FILE_EXTENSION = ".KeepUp";

const string Storage::FILE_OPEN_ERROR = "Could not open file.";
const string Storage::FILE_TASK_SEPARATOR = "";
const string Storage::MESSAGE_CORRUPTED = "Error! File seems corrupted. Halting operation.";
const string Storage::MESSAGE_LOADING = "Now Loading ";
const string Storage::MESSAGE_LOADED = "Loading complete!";
const string Storage::MESSAGE_SAVING = "Now saving to ";
const string Storage::MESSAGE_SAVED = "Saving complete!";
const string Storage::MESSAGE_WAITING_SYMBOL = "...";

//@author A0121007A
/* returns true if the calendar tasks are successfully saved into the file calName */
bool Storage::save(string calName, vector<Task> tasks) {
	string saveLocation = getCalendarLocation(calName);
	createDirectory();
	ofstream myCalendar(saveLocation, ios::in | ios::trunc);

	if (myCalendar.is_open()) {
		Utility::showToUser(Storage::MESSAGE_SAVING + calName + Storage::FILE_EXTENSION + Storage::MESSAGE_WAITING_SYMBOL);

		/* this for-loop saves all task attributes into the file myCalendar*/
		for (int i = 0; i < tasks.size(); i++) {
			vector<string> task = tasks.at(i).Task::getAttributes();
			for (int j = 0; j < task.size(); j++) {
				myCalendar << task.at(j) << endl;
			}
		}

		Utility::showToUser(Storage::MESSAGE_SAVED);
		myCalendar.close();
	} else {
		Utility::showToUser(Storage::FILE_OPEN_ERROR);
		return false;
	}

	return true;
}

//@author A0121007A
/* returns true if the calendar calName is successfully loaded into the Calendar object cal */
bool Storage::load(string calName, Calendar *cal) {
	string calendarLocation = getCalendarLocation(calName);
	ifstream calendar(calendarLocation);

	if (calendar.is_open()) {
		Utility::showToUser(Storage::MESSAGE_LOADING + calName + Storage::FILE_EXTENSION + Storage::MESSAGE_WAITING_SYMBOL);

		Task t;
		vector<string> taskParam(Task::ATTR::SIZE);
		int i = Task::COMMAND;
		bool isFirstTask = true;

		/* try to load all file attributes into respective tasks */
		try {
			for (string line; getline(calendar, line);) {

				if (Utility::areEqual(line, Storage::FILE_TASK_SEPARATOR)) {
					i = Task::COMMAND;
					if (isFirstTask) {
						isFirstTask = false;
					}
					else {
						t = Task(taskParam);
						cal->taskAdd(t);
					}
				}
				else {
					taskParam.at(i) = line;
				}
				i++;

			}

			t = Task(taskParam);
		}
		catch (exception &) {
			Utility::showToUser(Storage::MESSAGE_CORRUPTED);
			calendar.close();
			return false;
		}

		cal->taskAdd(t);

		Utility::showToUser(Storage::MESSAGE_LOADED);
		calendar.close();
	} else {
		Utility::showToUser(Storage::FILE_OPEN_ERROR);
		return false;
	}

	return true;
}

//@author A0121007A
/* returns a string representing the path of the calendar with the specified name */
string Storage::getCalendarLocation(string calName) {
	string userName = Utility::getUserName();
	string calendarLocation = Storage::USER_LOCATION + userName +
		Storage::FOLDER_LOCATION + calName + Storage::FILE_EXTENSION;
	return calendarLocation;
}

//@author A0121007A
/* create a directory with the name as specified in the constant strings of Storage */
void Storage::createDirectory() {
	string directory = Storage::USER_LOCATION + Utility::getUserName() + Storage::FOLDER_LOCATION;
	if (isExistingDirectory(directory)) {
		//do nothing
	} else {
		string cmd = "mkdir \"" + directory + "\"";
		system(cmd.c_str());
	}
}

//@author A0121007A
/* returns true if the directory exists, false otherwise */
bool Storage::isExistingDirectory(string dir) {
	DWORD attribs = ::GetFileAttributesA(dir.c_str());
	if (attribs == INVALID_FILE_ATTRIBUTES) {
		return false;
	}
	return true; //(attribs & FILE_ATTRIBUTE_DIRECTORY);
}


//@author A0090968M
//Original version of storage

//#include "Storage.h"


//void func(void);

//void func(){
//	fstream file("D://calendar.txt");
//	string contents;
//	if (file.fail())
//	{
//		cout << "error open!" << endl;
//	}
//	storage Task[10];
//	int task_size = 0;;
//	while (!file.eof())
//	{
//		file >> Task[task_size].startYear >> Task[task_size].startMonth >> Task[task_size].startDate >> Task[task_size].startHour >> Task[task_size].startMinute;
//		task_size++;
//	}
//	for (int i = 0; i < task_size; i++)
//	{
//		Task[i].print();
//	}

//}