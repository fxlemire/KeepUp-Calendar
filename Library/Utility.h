//@author A0121007A
/*
This classes is the toolbox of KeepUp: all the methods not directly related to one class
and that can be useful to more than one class
*/
#ifndef UTILITY_H
#define UTILITY_H

#include "Calendar.h"
#include "CommandParser.h"
#include <lmcons.h>
#include <string>

using namespace std;

class Utility {
public:
	//@author A0121007A
	/* utility messages */
	static const string NUMBER_SEPARATOR;
	static const string ERROR_ENTER_NUMBER;
	static const string ERROR_YES_NO_ENTRY;
	static const string YES;
	static const string NO;

	/* bool methods */
	static bool areEqual(string a, string b);
	static bool getYesNoConfirmation();
	static bool isAdd(Calendar::COMMAND_TYPE cmd);
	static bool isContained(string key, string sentence);
	static bool isEmpty(int i);
	static bool isEmpty(string s);
	static bool isEmpty(vector<int> v);
	static bool isValidCommand(Calendar::COMMAND_TYPE cmd);
	static bool isZero(int i);
	static bool isLessThanTen(int i);
	static bool stringToBool(string s);

	/* convert */
	static Calendar::COMMAND_TYPE stringToCOMMAND_TYPE(string command);
	static EDIT_TYPE::EDIT_TYPE intToEDIT_TYPE(int editType);
	static string boolToString(bool b);
	static string COMMAND_TYPEToString(Calendar::COMMAND_TYPE cmd);
	static vector<string> convert_DATE_ENUM_to_TASK_ATTR(vector<string> date_enum_vector);
	static vector<string> convert_TASK_ATTR_to_DATE_ENUM(vector<string> task_attr_vector);

	/* interaction with user */
	static int getIntFromUser();
	static string getHelp(int i);
	static void getHelpForCommand(string cmd);
	static string getStringFromUser();
	static void showToUser(string);
	static void showToUser(vector<string> strings);

	/* system/format methods */
	static string getUserName();
	static string numberize(int i, string s);
	static void clearVector(vector<int> &v);
	static void clearVector(vector<string> &v);
	static void clearVector(vector<Task> &v);
	static void addEscapeChar(string &s);
	static void removeEscapeChar(string &s);

private:
	//@author A0121007A
	/* confirm method */
	static bool isExit(string command);
	static bool isAdd(string command);
	static bool isBlock(string command);
	static bool isDecorate(string command);
	static bool isDelete(string command);
	static bool isDone(string command);
	static bool isEdit(string command);
	static bool isHelp(string command);
	static bool isSave(string command);
	static bool isLoad(string command);
	static bool isPrint(string command);
	static bool isRemind(string command);
	static bool isRepeat(string command);
	static bool isView(string command);
	static bool isWeather(string command);
	static bool isUndo(string command);
	static bool isRedo(string command);

	/* stores 0 for readability */
	static const int SAME;
};

#endif