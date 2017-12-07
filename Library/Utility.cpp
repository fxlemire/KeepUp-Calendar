//@author A0121007A
#include "Utility.h"
#include <Windows.h>

const int Utility::SAME = 0;
const string Utility::NUMBER_SEPARATOR = ". ";
const string Utility::ERROR_ENTER_NUMBER = "Wrong input. Please enter a number.";
const string Utility::ERROR_YES_NO_ENTRY = "Please enter \"Y\" to confirm, \"n\" to infirm.";
const string Utility::YES = "Y";
const string Utility::NO = "n";

//@author A0121007A
/* converts the string s to boolean true or false */
bool Utility::stringToBool(string s) {
	if (s.compare("true") == 0 || s.compare("True") == 0) {
		return true;
	}
	return false;
}

//@author A0121007A
/* converts a boolean to its string equivalent */
string Utility::boolToString(bool b) {
	return b ? "true" : "false";
}

//@author A0121007A
/* checks if the command is valid and exists by returning true or false */
bool Utility::isValidCommand(Calendar::COMMAND_TYPE cmd) {
	return (cmd >= Calendar::COMMAND_TYPE::EXIT && cmd <= Calendar::COMMAND_TYPE::TASKWEATHER);
}

//@author A0121007A
Calendar::COMMAND_TYPE Utility::stringToCOMMAND_TYPE(string command) {
	if (isExit(command)) {
		return Calendar::COMMAND_TYPE::EXIT;
	}
	if (isAdd(command)) {
		return Calendar::COMMAND_TYPE::TASKADD;
	}
	if (isBlock(command)) {
		return Calendar::COMMAND_TYPE::TASKBLOCK;
	}
	if (isDecorate(command)) {
		return Calendar::COMMAND_TYPE::TASKDECORATE;
	}
	if (isDelete(command)) {
		return Calendar::COMMAND_TYPE::TASKDELETE;
	}
	if (isDone(command)) {
		return Calendar::COMMAND_TYPE::TASKDONE;
	}
	if (isEdit(command)) {
		return Calendar::COMMAND_TYPE::TASKEDIT;
	}
	if (isHelp(command)) {
		return Calendar::COMMAND_TYPE::HELP;
	}
	if (isSave(command)) {
		return Calendar::COMMAND_TYPE::SAVE;
	}
	if (isLoad(command)) {
		return Calendar::COMMAND_TYPE::LOAD;
	}
	if (isPrint(command)) {
		return Calendar::COMMAND_TYPE::TASKPRINT;
	}
	if (isRemind(command)) {
		return Calendar::COMMAND_TYPE::TASKREMIND;
	}
	if (isRepeat(command)) {
		return Calendar::COMMAND_TYPE::TASKREPEAT;
	}
	if (isView(command)) {
		return Calendar::COMMAND_TYPE::TASKVIEW;
	}
	if (isWeather(command)) {
		return Calendar::COMMAND_TYPE::TASKWEATHER;
	}
	if (isUndo(command)) {
		return Calendar::COMMAND_TYPE::TASKUNDO;
	}
	if (isRedo(command)) {
		return Calendar::COMMAND_TYPE::TASKREDO;
	}
	return Calendar::COMMAND_TYPE::TASKINVALID;
}

//@author A0121007A
string COMMAND_TYPEToString(Calendar::COMMAND_TYPE cmd) {
	switch (cmd) {
	case Calendar::COMMAND_TYPE::EXIT:
		return Calendar::COMMAND_EXIT;
	case Calendar::COMMAND_TYPE::TASKADD:
		return Calendar::COMMAND_ADD;
	case Calendar::COMMAND_TYPE::TASKBLOCK:
		return Calendar::COMMAND_BLOCK;
	case Calendar::COMMAND_TYPE::TASKDECORATE:
		return Calendar::COMMAND_DECORATE;
	case Calendar::COMMAND_TYPE::TASKDELETE:
		return Calendar::COMMAND_DELETE;
	case Calendar::COMMAND_TYPE::TASKDONE:
		return Calendar::COMMAND_DONE;
	case Calendar::COMMAND_TYPE::TASKEDIT:
		return Calendar::COMMAND_EDIT;
	case Calendar::COMMAND_TYPE::HELP:
		return Calendar::COMMAND_HELP;
	case Calendar::COMMAND_TYPE::SAVE:
		return Calendar::COMMAND_SAVE;
	case Calendar::COMMAND_TYPE::LOAD:
		return Calendar::COMMAND_LOAD;
	case Calendar::COMMAND_TYPE::TASKPRINT:
		return Calendar::COMMAND_PRINT;
	case Calendar::COMMAND_TYPE::TASKREMIND:
		return Calendar::COMMAND_REMIND;
	case Calendar::COMMAND_TYPE::TASKREPEAT:
		return Calendar::COMMAND_REPEAT;
	case Calendar::COMMAND_TYPE::TASKVIEW:
		return Calendar::COMMAND_VIEW;
	case Calendar::COMMAND_TYPE::TASKWEATHER:
		return Calendar::COMMAND_WEATHER;
	case Calendar::COMMAND_TYPE::TASKUNDO:
		return Calendar::COMMAND_UNDO;
	case Calendar::COMMAND_TYPE::TASKREDO:
		return Calendar::COMMAND_REDO;
	default:
		return Calendar::COMMAND_INVALID;
	}
}

//@author A0121007A
bool Utility::isExit(string command) {
	return (command.compare(Calendar::COMMAND_EXIT) == SAME);
}
bool Utility::isAdd(string command) {
	return (command.compare(Calendar::COMMAND_ADD) == SAME);
}
bool Utility::isBlock(string command) {
	return (command.compare(Calendar::COMMAND_BLOCK) == SAME);
}
bool Utility::isDecorate(string command) {
	return (command.compare(Calendar::COMMAND_DECORATE) == SAME);
}
bool Utility::isDelete(string command) {
	return (command.compare(Calendar::COMMAND_DELETE) == SAME);
}
bool Utility::isDone(string command) {
	return (command.compare(Calendar::COMMAND_DONE) == SAME);
}
bool Utility::isEdit(string command) {
	return (command.compare(Calendar::COMMAND_EDIT) == SAME);
}
bool Utility::isHelp(string command) {
	return (command.compare(Calendar::COMMAND_HELP) == SAME);
}
bool Utility::isSave(string command) {
	return (command.compare(Calendar::COMMAND_SAVE) == SAME);
}
bool Utility::isLoad(string command) {
	return (command.compare(Calendar::COMMAND_LOAD) == SAME);
}
bool Utility::isPrint(string command) {
	return (command.compare(Calendar::COMMAND_PRINT) == SAME);
}
bool Utility::isRemind(string command) {
	return (command.compare(Calendar::COMMAND_REMIND) == SAME);
}
bool Utility::isRepeat(string command) {
	return (command.compare(Calendar::COMMAND_REPEAT) == SAME);
}
bool Utility::isView(string command) {
	return (command.compare(Calendar::COMMAND_VIEW) == SAME);
}
bool Utility::isWeather(string command) {
	return (command.compare(Calendar::COMMAND_WEATHER) == SAME);
}
bool Utility::isUndo(string command) {
	return (command.compare(Calendar::COMMAND_UNDO) == SAME);
}
bool Utility::isRedo(string command) {
	return (command.compare(Calendar::COMMAND_REDO) == SAME);
}
//@author A0121007A
bool Utility::isAdd(Calendar::COMMAND_TYPE cmd) {
	if (cmd == Calendar::COMMAND_TYPE::TASKADD) {
		return true;
	}
	return false;
}
//@author A0121007A
/* returns true if 'key' is found in 'sentence' */
bool Utility::isContained(string key, string sentence) {
	size_t found = sentence.find(key);
	if (found != std::string::npos) {
		return true;
	}
	return false;
}
//@author A0121007A
/* returns true if 's' is equal to the STRING_NOT_EXIST Task constant string */
bool Utility::isEmpty(string s) {
	if (s.compare(Task::STRING_NOT_EXIST) == 0) {
		return true;
	}
	return false;
}
//@author A0121007A
bool Utility::isEmpty(vector<int> v) {
	if (v.size() == 0) {
		return true;
	}
	return false;
}
//@author A0121007A
/* returns true if 'i' is equal to the INT_NOT_EXIST Task constant int */
bool Utility::isEmpty(int i) {
	if (i == Task::INT_NOT_EXIST) {
		return true;
	}
	return false;
}
//@author A0121007A
bool Utility::areEqual(string a, string b) {
	if (a.compare(b) == SAME) {
		return true;
	}
	return false;
}
//@author A0121007A
/* returns true if 'i' is equal to zero */
bool Utility::isZero(int i) {
	if (i == 0) {
		return true;
	}
	return false;
}
//@author A0121007A
/* returns true if 'i' is less and not equal to 10 */
bool Utility::isLessThanTen(int i) {
	if (i < 10) {
		return true;
	}
	return false;
}
//@author A0121007A
/* converts an integer to the EDIT_TYPE enum */
EDIT_TYPE::EDIT_TYPE intToEDIT_TYPE(int editType) { 
	switch (editType) {
	case EDIT_TYPE::EDIT_TYPE::TITLE:
		return EDIT_TYPE::EDIT_TYPE::TITLE;
	case EDIT_TYPE::EDIT_TYPE::DATETIME:
		return EDIT_TYPE::EDIT_TYPE::DATETIME;
	case EDIT_TYPE::EDIT_TYPE::LOCATION:
		return EDIT_TYPE::EDIT_TYPE::LOCATION;
	case EDIT_TYPE::EDIT_TYPE::REMINDER:
		return EDIT_TYPE::EDIT_TYPE::REMINDER;
	case EDIT_TYPE::EDIT_TYPE::DESCRIPTION:
		return EDIT_TYPE::EDIT_TYPE::DESCRIPTION;
	case EDIT_TYPE::EDIT_TYPE::ATTACHFILE:
		return EDIT_TYPE::EDIT_TYPE::ATTACHFILE;
	case EDIT_TYPE::EDIT_TYPE::EVERYTHING:
		return EDIT_TYPE::EDIT_TYPE::EVERYTHING;
	default:
		break;
	}
}
//@author A0121007A
/* prints to the terminal everything inside the vector if the content
   is not equal to STRING_NOT_EXIST
*/
void Utility::showToUser(vector<string> strings) {
	for (int i = 0; i < strings.size(); i++) {
		if (!Utility::areEqual(strings.at(i), Task::STRING_NOT_EXIST)) {
			cout << strings.at(i) << endl;
		}
	}
}
//@author A0121007A
void Utility::showToUser(string s) {
	cout << s << endl;
}
//@author A0121007A
/* get the user to type an integer, and loop until input is valid */
int Utility::getIntFromUser() {
	string s;
	int userChoice;
	bool notFine = true;
	do {
		try {
			getline(cin, s);
			userChoice = stoi(s);
			notFine = false;
		}
		catch (exception &) {
			Utility::showToUser(Utility::ERROR_ENTER_NUMBER);
		}
	} while (notFine);
	return userChoice;
}
//@author A0121007A
/* return the command string corresponding to the Help menu choice */
string Utility::getHelp(int i) {
	switch (i) {
	case HELP::HELP::ADD:
		return Calendar::COMMAND_ADD;
		break;
	case HELP::HELP::BLOCK:
		return Calendar::COMMAND_BLOCK;
		break;
	case HELP::HELP::DECORATE:
		return Calendar::COMMAND_DECORATE;
		break;
	case HELP::HELP::DEL:
		return Calendar::COMMAND_DELETE;
		break;
	case HELP::HELP::DONE:
		return Calendar::COMMAND_DONE;
		break;
	case HELP::HELP::EDIT:
		return Calendar::COMMAND_EDIT;
		break;
	case HELP::HELP::EXIT:
		return Calendar::COMMAND_EXIT;
		break;
	case HELP::HELP::LOAD:
		return Calendar::COMMAND_LOAD;
		break;
	case HELP::HELP::PRINT:
		return Calendar::COMMAND_PRINT;
		break;
	case HELP::HELP::REDO:
		return Calendar::COMMAND_REDO;
		break;
	case HELP::HELP::REMIND:
		return Calendar::COMMAND_REMIND;
		break;
	case HELP::HELP::REPEAT:
		return Calendar::COMMAND_REPEAT;
		break;
	case HELP::HELP::SAVE:
		return Calendar::COMMAND_SAVE;
		break;
	case HELP::HELP::UNDO:
		return Calendar::COMMAND_UNDO;
		break;
	case HELP::HELP::VIEW:
		return Calendar::COMMAND_VIEW;
		break;
	case HELP::HELP::WEATHER:
		return Calendar::COMMAND_WEATHER;
		break;
	default:
		Utility::showToUser(Calendar::COMMAND_INVALID);
		break;
	}
}
//@author A0121007A
/* print all command details for help */
void Utility::getHelpForCommand(string cmd) {
	if (isAdd(cmd)) {
		Utility::showToUser(Calendar::HELP_ADD_1);
		Utility::showToUser(Calendar::HELP_ADD_2);
		Utility::showToUser(Calendar::HELP_ADD_3);
		Utility::showToUser(Calendar::HELP_ADD_4);
		Utility::showToUser(Calendar::HELP_ADD_5);
		Utility::showToUser(Calendar::HELP_ADD_6);
		Utility::showToUser(Calendar::HELP_ADD_7);
		Utility::showToUser(Calendar::HELP_ADD_8);
		Utility::showToUser(Calendar::HELP_ADD_9);
		Utility::showToUser(Calendar::HELP_ADD_10);
		Utility::showToUser(Calendar::HELP_ADD_11);
	} else if (isBlock(cmd)) {
		Utility::showToUser(Calendar::HELP_BLOCK);
	} else if (isDecorate(cmd)) {
		Utility::showToUser(Calendar::HELP_DECORATE);
	} else if (isDelete(cmd)) {
		Utility::showToUser(Calendar::HELP_DELETE_1);
		Utility::showToUser(Calendar::HELP_DELETE_2);
	} else if (isDone(cmd)) {
		Utility::showToUser(Calendar::HELP_DONE_1);
		Utility::showToUser(Calendar::HELP_DONE_2);
	} else if (isEdit(cmd)) {
		Utility::showToUser(Calendar::HELP_EDIT_1);
		Utility::showToUser(Calendar::HELP_EDIT_2);
		Utility::showToUser(Calendar::HELP_EDIT_3);
	} else if (isExit(cmd)) {
		Utility::showToUser(Calendar::HELP_EXIT);
	} else if (isLoad(cmd)) {
		Utility::showToUser(Calendar::HELP_LOAD);
	} else if (isPrint(cmd)) {
		Utility::showToUser(Calendar::HELP_PRINT);
	} else if (isRedo(cmd)) {
		Utility::showToUser(Calendar::HELP_REDO);
	} else if (isRemind(cmd)) {
		Utility::showToUser(Calendar::HELP_REMIND);
	} else if (isRepeat(cmd)) {
		Utility::showToUser(Calendar::HELP_REPEAT);
	} else if (isSave(cmd)) {
		Utility::showToUser(Calendar::HELP_SAVE_1);
		Utility::showToUser(Calendar::HELP_SAVE_2);
	} else if (isUndo(cmd)) {
		Utility::showToUser(Calendar::HELP_UNDO);
	} else if (isView(cmd)) {
		Utility::showToUser(Calendar::HELP_VIEW_1);
		Utility::showToUser(Calendar::HELP_VIEW_2);
		Utility::showToUser(Calendar::HELP_VIEW_3);
		Utility::showToUser(Calendar::HELP_VIEW_4);
	} else if (isWeather(cmd)) {
		Utility::showToUser(Calendar::HELP_WEATHER);
	} else {
		Utility::showToUser(Calendar::MESSAGE_NOT_YET_IMPLEMENTED);
	}
}
//@author A0121007A
/* get user to type Y or n, such as for exiting */
bool Utility::getYesNoConfirmation() {
	string choice;
	do {
		getline(cin, choice);
		if (areEqual(choice, Utility::YES)) {
			return true;
		} else if (areEqual(choice, Utility::NO)) {
			return false;
		} else {
			Utility::showToUser(Utility::ERROR_YES_NO_ENTRY);
		}
	} while (/*user choices will allow to leave this loop*/true);
}
//@author A0121007A
string Utility::getStringFromUser() {
	string s;
	getline(cin, s);
	return s;
}
//@author A0121007A
/* fetch the username of the computer */
string Utility::getUserName() {
	TCHAR name[UNLEN + 1];
	DWORD size = UNLEN + 1;
	GetUserName((TCHAR*)name, &size); //TODO: could maybe generate an error so handle properly
	string userName = name;
	return userName;
}
//@author A0121007A
/* insert at the beginning of the string a numerotation */
string Utility::numberize(int i, string s) {
	string toDisplay = to_string(i) + Utility::NUMBER_SEPARATOR + s;
	return toDisplay;
}

//@author A0121007A
/* rebase a vector TASK_ATTR under the base of DATE_ENUM */
vector<string> Utility::convert_DATE_ENUM_to_TASK_ATTR(vector<string> date_enum_vector) {
	vector<string> task_attr_vector(Task::ATTR::SIZE);

	task_attr_vector.at(Task::ATTR::STARTYEAR) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTYEAR);
	task_attr_vector.at(Task::ATTR::STARTMONTH) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTMONTH);
	task_attr_vector.at(Task::ATTR::STARTDAY) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTDAY);
	task_attr_vector.at(Task::ATTR::STARTHOUR) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTHOUR);
	task_attr_vector.at(Task::ATTR::STARTMINUTE) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTMINUTE);
	task_attr_vector.at(Task::ATTR::ENDYEAR) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDYEAR);
	task_attr_vector.at(Task::ATTR::ENDMONTH) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDMONTH);
	task_attr_vector.at(Task::ATTR::ENDDAY) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDDAY);
	task_attr_vector.at(Task::ATTR::ENDHOUR) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDHOUR);
	task_attr_vector.at(Task::ATTR::ENDMINUTE) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDMINUTE);
	task_attr_vector.at(Task::ATTR::ISDONE) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::ISDONE);
	task_attr_vector.at(Task::ATTR::HASDATE) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::HASDATE);
	task_attr_vector.at(Task::ATTR::HASEXPIRED) = date_enum_vector.at(DATE_ENUM::DATE_ENUM::HASEXPIRED);

	return task_attr_vector;
}
//@author A0121007A
/* rebase a vector DATE_ENUM under the base of TASK_ATTR */
vector<string> Utility::convert_TASK_ATTR_to_DATE_ENUM(vector<string> task_attr_vector) {
	vector<string> date_enum_vector(DATE_ENUM::DATE_ENUM::LASTPOSITION);

	date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTYEAR) = task_attr_vector.at(Task::ATTR::STARTYEAR);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTMONTH) = task_attr_vector.at(Task::ATTR::STARTMONTH);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTDAY) = task_attr_vector.at(Task::ATTR::STARTDAY);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTHOUR) = task_attr_vector.at(Task::ATTR::STARTHOUR);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::STARTMINUTE) = task_attr_vector.at(Task::ATTR::STARTMINUTE);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDYEAR) = task_attr_vector.at(Task::ATTR::ENDYEAR);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDMONTH) = task_attr_vector.at(Task::ATTR::ENDMONTH);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDDAY) = task_attr_vector.at(Task::ATTR::ENDDAY);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDHOUR) = task_attr_vector.at(Task::ATTR::ENDHOUR);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::ENDMINUTE) = task_attr_vector.at(Task::ATTR::ENDMINUTE);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::ISDONE) = task_attr_vector.at(Task::ATTR::ISDONE);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::HASDATE) = task_attr_vector.at(Task::ATTR::HASDATE);
	date_enum_vector.at(DATE_ENUM::DATE_ENUM::HASEXPIRED) = task_attr_vector.at(Task::ATTR::HASEXPIRED);

	return date_enum_vector;
}
//@author A0121007A
void Utility::clearVector(vector<string> &v) {
	v.clear();
	vector<string>().swap(v);
}
//@author A0121007A
void Utility::clearVector(vector<int> &v) {
	v.clear();
	vector<int>().swap(v);
}
//@author A0121007A
void Utility::clearVector(vector<Task> &v) {
	v.clear();
	vector<Task>().swap(v);
}
//@author A0121007A
/* add the ESCAPE_CHAR at the beginning of the string */
void Utility::addEscapeChar(string &s) {
	if (Utility::areEqual(s.substr(0, Calendar::ESCAPE_CHAR.size()), Calendar::ESCAPE_CHAR)) {
		//do nothing
	} else {
		s.insert(0, Calendar::ESCAPE_CHAR);
	}
}
//@author A0121007A
/* remove the ESCAPE_CHAR at the beginning of the string */
void Utility::removeEscapeChar(string &s) {
	if (Utility::areEqual(s.substr(0, Calendar::ESCAPE_CHAR.size()), Calendar::ESCAPE_CHAR)) {
		s.erase(0, Calendar::ESCAPE_CHAR.size());
	}
}