//@author A0121007A
/*
A core class of KeepUp. It initializes enumerations for consistancy throughout the whole classes.
It constructs tasks.
Everything is converted to proper type for virtual storage and back to string
for the programmer's ease. It is responsible of display format for user's ease of reading
and contains a lot of error messages and validity methods to make sure tasks are
constructed properly for good interaction later on.
*/
#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

using namespace std;

class Task {
public:
	//@author A0121007A
	/* some attributes to be displayed to the user */
	static const string STARTYEAR_STR;
	static const string STARTMONTH_STR;
	static const string STARTDAY_STR;
	static const string STARTHOUR_STR;
	static const string STARTMINUTE_STR;
	static const string ENDYEAR_STR;
	static const string ENDMONTH_STR;
	static const string ENDDAY_STR;
	static const string ENDHOUR_STR;
	static const string ENDMINUTE_STR;
	static const string PRIORITY_STR;
	static const string NAME_STR;
	static const string DESCRIPTION_STR;
	static const string LOCATION_STR;
	static const string ISDONE_STR;
	static const string ISDONE_ALERT;
	static const string ISDELETED_STR;
	static const string ISDELETED_ALERT;
	static const string ISIMPT_STR;
	static const string ISIMPT_ALERT;
	static const string HASEXPIRED_STR;
	static const string ATTR_SEPARATOR;
	static const string VALUE_TRUE_FOR_DISPLAY;
	static const string VALUE_FALSE_FOR_DISPLAY;

	static const bool Task::TRUE;
	static const bool Task::FALSE;

	/* config */
	static const int INT_NOT_EXIST; //-1
	static const bool BOOL_NOT_EXIST; //false
	/*many keywords and characters for validity, display and input checking*/
	static const string DISPLAY_DATE_ATTR_NOT_SPECIFIED;
	static const string DISPLAY_DATE_NOT_SPECIFIED;
	static const string DISPLAY_HOUR_NOT_SPECIFIED;
	static const string DISPLAY_KEY_DATE;
	static const string DISPLAY_KEY_DATE_RANGE;
	static const string DISPLAY_KEY_LOC;
	static const string DISPLAY_KEY_TIME;
	static const string DISPLAY_KEY_TIME_RANGE;
	static const string DISPLAY_MINUTES_NOT_SPECIFIED;
	static const string DISPLAY_NAME_NOT_SPECIFIED;
	static const string DISPLAY_SPACE;
	static const string DISPLAY_TIME_NOT_SPECIFIED;
	static const string STRING_NOT_EXIST; //used to represent an ignored input by the user
	static const string DATE_RANGE_SEPARATOR;
	static const string TIME_RANGE_SEPARATOR;
	static const string DATE_SEPARATOR_ENGLISH;
	static const string TIME_SEPARATOR_ENGLISH;
	static const string ZERO_MINUTES;

	/* error messages */
	static const string ERROR_DAY;
	static const string ERROR_DAY_31;
	static const string ERROR_DAY_FEB;
	static const string ERROR_MONTH;
	static const string ERROR_HOUR;
	static const string ERROR_MINUTE;
	static const string ERROR_ENDDATE;
	/* more error messages */
	static const string ERROR_STARTHOUR;
	static const string ERROR_STARTMINUTE;
	static const string ERROR_STARTDAY;
	static const string ERROR_STARTDAY_31;
	static const string ERROR_STARTMONTH;
	static const string ERROR_STARTYEAR;
	static const string ERROR_ENDHOUR;
	static const string ERROR_ENDHOUR_BEFORE_START;
	static const string ERROR_ENDMINUTE;
	static const string ERROR_ENDMINUTE_BEFORE_START;
	static const string ERROR_ENDDAY;
	static const string ERROR_ENDDAY_31;
	static const string ERROR_ENDDAY_BEFORE_START;
	static const string ERROR_ENDMONTH;
	static const string ERROR_ENDMONTH_BEFORE_START;
	static const string ERROR_ENDYEAR;
	static const string ERROR_ENDYEAR_BEFORE_START;
	static const string ERROR_PRIORITY;

	/* enum for the vector needed for task constructor */
	enum ATTR {
		COMMAND, NAME, LOCATION, STARTHOUR, STARTMINUTE, STARTDAY, STARTMONTH,
		STARTYEAR, ENDHOUR, ENDMINUTE, ENDDAY, ENDMONTH, ENDYEAR, DESCRIPTION,
		PRIORITY, ISDONE, ISDELETED, HASDATE, HASEXPIRED, SIZE, ISIMPT
	};

	/* constructors */
	Task();
	Task(vector<string> attributes);

	/* no destructor */

	/* getters */
	string getStartYear();
	string getStartMonth();
	string getStartDay();
	string getStartHour();
	string getStartMinute();
	string getEndYear();
	string getEndMonth();
	string getEndDay();
	string getEndHour();
	string getEndMinute();
	string getPriority();
	string getName();
	string getDescription();
	string getLocation();
	string getIsDone();
	string getIsDoneForDisplay();
	string getIsDeleted();
	string getIsImpt();
	string getHasDate();
	string getHasExpired();
	string getHasExpiredForDisplay();

	/* more getters */
	string getDisplay();
	string getEndDate();
	string getEndTime();
	string getStartDate();
	string getStartTime();
	string getDate();
	string getTime();

	/* advanced getters */
	vector<string> getAttributes();
	vector<string> getAttributesForDisplay();

	/* setters */
	void setStartYear(string sy);
	void setStartMonth(string sm);
	void setStartDay(string sd);
	void setStartHour(string sh);
	void setStartMinute(string sm);
	void setEndYear(string ey);
	void setEndMonth(string em);
	void setEndDay(string ed);
	void setEndHour(string eh);
	void setEndMinute(string em);
	void setDateAndTime(vector<string> dateAndTime);
	void setPriority(string p);
	void setName(string n);
	void setDescription(string d);
	void setLocation(string l);
	void setIsDone();
	void setIsDone(string done);
	void setIsDeleted();
	void setIsDeleted(string del);
	void setIsImpt();
	void setIsImpt(string impt);
	void setHasDate(string d);
	void setHasExpired(string expired);

	/* advanced setter */
	void setAttributes(vector<string> attributes);

	/* validity checkers */
	static bool isValidTime(vector<string> userInputParsed);
	static bool isValidStartHour(vector<string> userInputParsed);
	static bool isValidStartMinute(vector<string> userInputParsed);
	static bool isValidEndHour(vector<string> userInputParsed);
	static bool isValidEndMinute(vector<string> userInputParsed);
	static bool isValidDate(vector<string> userInputParsed);
	static bool isValidStartDay(string sD, string sM, string sY);
	static bool isValidStartMonth(string sM, string sY);
	static bool isValidStartYear(string sY);
	static bool isValidEndDay(string eD, string eM, string eY, string sD, string sM, string sY);
	static bool isValidEndMonth(string eM, string eY, string sM, string sY);
	static bool isValidEndYear(string eY, string sY);
	static bool isValidPriority(string priority);
	static bool isSameStartEndDate(vector<string> userInputParsed);
	static bool isGreaterEndDate(vector<string> userInputParsed);

	/* more validity checkers */
	static bool isValidHour(int h);
	static bool isValidMinute(int m);
	static bool isValidDay(int d, int m, int y);
	static bool isValidMonth(int m);
	static bool isValidYear(int y);

private:
	//@author A0121007A
	/* task attributes */
	int startYear;
	int startMonth;
	int startDay;
	int startHour;
	int startMinute;
	int endYear;
	int endMonth;
	int endDay;
	int endHour;
	int endMinute;
	int priority;
	string name;
	string description;
	string location;
	bool isDone;
	bool isDeleted;
	bool isImpt;
	bool hasDate;
	bool hasExpired;

	/* task private helper methods*/
	string concatenateDisplayAttributes(string name, string loc, string time, string date, string priority, string done);
	string formatStartEndDate(string s, string e);
	string formatDate(string d, string m, string y);
	string formatTime(string h, string m);
	string formatStartEndTime(string s, string e);
	string getDisplayDate();
	string getDisplayDone();
	string getDisplayLocation();
	string getDisplayName();
	string getDisplayPriority();
	string getDisplayTime();
	static bool isNonSpecifiedHour(string t);
	static bool isNonSpecifiedTime(string t);
	static bool isNonSpecifiedDate(string d);
};
#endif