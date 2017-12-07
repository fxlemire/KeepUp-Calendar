#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

#include "Task.h"
#include "Calendar.h"
#include "Utility.h"

#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <algorithm>
using namespace std;
//@author a0100789b
//This class serves to parse the user input into start date/time, end date/time, location 
//and task title if any. When the user want to edit, delete or view, it will parse the keywords
//from the user for searching purpose as well/

//This class can parse the following date format. (with an "on" or "by" in front)
//	day/month/year  e.g.  20/4/2014 
//	day/month       e.g.  20/4  the year will be set to current year by default
//  day             e.g   20    the year and month will be set to current month and year by default
//  dates in text form  e.g  1st Jan 2014, December 25th, the day can be either in front or after
//                           the month. The month can be in full spelling or abbreviation form. If
//                           year is absent, it will be set to current year.
//  dates in week days form. e.g Friday, next Monday, this wed, today, tmrw.


//This class can parse the following time format. (with an "at" or "by" in front)
// 8.30am
// 8
// 8pm
// 5:30pm
// 21.20

//This class can parse a duration specified by the user with a "-" between the start date/time and end date/time
// 2-3pm
// 2.30 - 11.10pm
// 6/9/2014 - 4/10/2015
// april 1st - 2 may

class CommandParser {
public:
	static string getCommand(string input);
	static string getStartYear();
	static string getStartMonth();
	static string getStartDay();
	static string getStartHour();
	static string getStartMinute();
	static string getEndYear();
	static string getEndMonth();
	static string getEndDay();
	static string getEndHour();
	static string getEndMinute();
	static string getPriority(string input);
	static string getName(string input);
	static string getDescription(string input);
	static string getLocation(string input);
	static string getKeywords(string input);
	static vector<string> getParsedUserInput(string uInput);

	static vector<string> getDateAndTime(string input);
	static string getStartDate(string input);
	static string getStartTime(string input);
	static string getEndDate(string input);
	static string getDuration(string input);
	static string getDurationStart();
	static string getDurationEnd();
	static string getEndTime(string input);

	static string previousWord(string,string);
	static string nextWord(string, string);
	static string convertTextToNumber(string);

	static string getCurrentDate();
	static bool hasWeekDay(string input);
	static string getDateFromWeek();
	static string weekNumber(string, string);
	static bool hasSpecialDay(string input);

	static bool isFound(string, string);
	static bool isFoundBack(string, string);
	static bool isNotExist(string);
	static bool isNumber(string);
	static bool hasTextMonth(string);
	static void getTextMonth(string,string);
	static bool isIndependent(string, string);
	static bool isIndependentBack(string, string);
	static void dateTimeModifier();
	static string reSequence(string, string);


	void setUserInput(string ui);
	void setDate(string d);
	void setParsedInput(vector<string> pi);

private:
	static string userInput;
	static string startDate;
	static string endDate;
	static string startTime;
	static string endTime;
	static string location;
	static string name;
	static string duration;
	static string part;
	static string localMonth;

	static string textDate;
	static string textMonth;
	static string currentDate;
	static string taskDate;
	static string currentYear;
	static string weekNo;
	static string specialDay;
	static int currentWeekDay;
	static int localYear;
	static int currentMonth;
	static int currentDay;
	static int weekDay;
	static int taskDay;
	static int taskMonth;
	static int taskYear;
	static int lengthFront;
	static int lengthBack;

	static string initial;

	const static string commandIndicator;
	const static string startDateIndicator;
	const static string dateIndicator;
	const static string dayIndicator;
	const static string startTimeIndicator;
	const static string locationIndicatorStart;
	const static string locationIndicatorEnd;
	const static string locationIndicator1;
	const static string locationIndicator2;
	const static string spaceIndicator;
	const static string hourIndicator;
	const static string hourIndicator1;
	const static string hourIndicator2;
	const static string endDateIndicator;
	const static string durationIndicator;
	const static string durationIndicator1;
	const static string afternoonIndicator;
	const static string morningIndicator;
	const static string minuteNotExist;

	const static string januaryIndicator1;
	const static string januaryIndicator2;
	const static string febIndicator1;
	const static string febIndicator2;
	const static string marchIndicator1;
	const static string marchIndicator2;
	const static string aprilIndicator1;
	const static string aprilIndicator2;
	const static string mayIndicator1;
	const static string juneIndicator1;
	const static string juneIndicator2;
	const static string julyIndicator1;
	const static string julyIndicator2;
	const static string augIndicator1;
	const static string augIndicator2;
	const static string septIndicator1;
	const static string septIndicator2;
	const static string septIndicator3;
	const static string octIndicator1;
	const static string octIndicator2;
	const static string novIndicator1;
	const static string novIndicator2;
	const static string decIndicator1;
	const static string decIndicator2;

	const static string textMonth1;
	const static string textMonth2;
	const static string textMonth3;
	const static string textMonth4;
	const static string textMonth5;
	const static string textMonth6;
	const static string textMonth7;
	const static string textMonth8;
	const static string textMonth9;
	const static string textMonth10;
	const static string textMonth11;
	const static string textMonth12;
	

	const static int startingPosition;
	const static int positionModerator1;
	const static int positionModerator2;
	const static int positionModerator3;
	const static int positionModerator4;

	const static int hourModerator;

	const static int standardYear;
	const static int standardWeek;
	const static int lengthofAWeek;

	const static string mondayIndicator1;
	const static string mondayIndicator2;
	const static string mondayIndicator3;
	const static string mondayIndicator4;
	const static string tuesdayIndicator1;
	const static string tuesdayIndicator2;
	const static string tuesdayIndicator3;
	const static string tuesdayIndicator4;
	const static string wednesdayIndicator1;
	const static string wednesdayIndicator2 ;
	const static string wednesdayIndicator3;
	const static string wednesdayIndicator4;
	const static string thursdayIndicator1;
	const static string thursdayIndicator2;
	const static string thursdayIndicator3;
	const static string thursdayIndicator4;
	const static string thursdayIndicator5;
	const static string thursdayIndicator6;
	const static string fridayIndicator1;
	const static string fridayIndicator2;
	const static string fridayIndicator3;
	const static string fridayIndicator4;
	const static string saturdayIndicator1;
	const static string saturdayIndicator2;
	const static string saturdayIndicator3;
	const static string saturdayIndicator4;
	const static string sundayIndicator1;
	const static string sundayIndicator2;
	const static string sundayIndicator3;
	const static string sundayIndicator4;
	const static string nextIndicator;
	const static string thisIndicator;
	const static string todayIndicator1;
	const static string todayIndicator2;
	const static string tomorrowIndicator1;
	const static string tomorrowIndicator2;
	const static string tomorrowIndicator3;

	const static int monday;
	const static int tuesday;
	const static int wednesday;
	const static int thursday;
	const static int friday;
	const static int saturday;
	const static int sunday;

	const static int monthIndicator1;
	const static int monthIndicator2;
	const static int monthIndicator3;
	const static int monthIndicator4;
	const static int monthIndicator5;
	const static int monthIndicator6;
	const static int monthIndicator7;
	const static int monthIndicator8;
	const static int monthIndicator9;
	const static int monthIndicator10;
	const static int monthIndicator11;
	const static int monthIndicator12;
	const static int monthModerator1;
	const static int monthModerator2;
	const static int monthModerator3;
	const static int monthModerator4;

	static vector<string> parsedInput;
	static Calendar::COMMAND_TYPE _command;
};

#endif