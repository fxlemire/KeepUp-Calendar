#include "CommandParser.h"

//replace commadnParser::not_exist by task::STRING_NOT_EXIST

const string CommandParser::commandIndicator = " ";
const string CommandParser::startDateIndicator = "on ";
const string CommandParser::dateIndicator = "on";
const string CommandParser::dayIndicator = "/";
const string CommandParser::startTimeIndicator = "at ";
const string CommandParser::locationIndicatorStart = " <";
const string CommandParser::locationIndicatorEnd = ">";
const string CommandParser::locationIndicator1 = "in";
const string CommandParser::locationIndicator2 = "at";
const string CommandParser::hourIndicator = ":.";
const string CommandParser::hourIndicator1 = ":";
const string CommandParser::hourIndicator2 = ".";
const string CommandParser::endDateIndicator = "by";
const string CommandParser::durationIndicator = "-";
const string CommandParser::durationIndicator1 = "from ";
const string CommandParser::afternoonIndicator = "pm";
const string CommandParser::morningIndicator = "am";
const string CommandParser::minuteNotExist = "00";

const string CommandParser::januaryIndicator1 = "january";
const string CommandParser::januaryIndicator2 = "jan";
const string CommandParser::febIndicator1 = "february";
const string CommandParser::febIndicator2 = "feb";
const string CommandParser::marchIndicator1 = "march";
const string CommandParser::marchIndicator2 = "mar";
const string CommandParser::aprilIndicator1 = "april";
const string CommandParser::aprilIndicator2 = "apr";
const string CommandParser::mayIndicator1 = "may";
const string CommandParser::juneIndicator1 = "june";
const string CommandParser::juneIndicator2 = "jun";
const string CommandParser::julyIndicator1 = "july";
const string CommandParser::julyIndicator2 = "jul";
const string CommandParser::augIndicator1 = "august";
const string CommandParser::augIndicator2 = "aug";
const string CommandParser::septIndicator1 = "september";
const string CommandParser::septIndicator2 = "sept";
const string CommandParser::septIndicator3 = "sep";
const string CommandParser::octIndicator1 = "october";
const string CommandParser::octIndicator2 = "oct";
const string CommandParser::novIndicator1 = "november";
const string CommandParser::novIndicator2 = "nov";
const string CommandParser::decIndicator1 = "december";
const string CommandParser::decIndicator2 = "dec";

const string CommandParser::textMonth1 = "1";
const string CommandParser::textMonth2 = "2";
const string CommandParser::textMonth3 = "3";
const string CommandParser::textMonth4 = "4";
const string CommandParser::textMonth5 = "5";
const string CommandParser::textMonth6 = "6";
const string CommandParser::textMonth7 = "7";
const string CommandParser::textMonth8 = "8";
const string CommandParser::textMonth9 = "9";
const string CommandParser::textMonth10 = "10";
const string CommandParser::textMonth11 = "11";
const string CommandParser::textMonth12 = "12";


const int CommandParser::startingPosition = 0;
const int CommandParser::positionModerator1 = 1;
const int CommandParser::positionModerator2 = 2;
const int CommandParser::positionModerator3 = 3;
const int CommandParser::positionModerator4 = 4;

const int CommandParser::hourModerator = 12;

const int CommandParser::standardYear = 1900;
const int CommandParser::standardWeek = 6;
const int CommandParser::lengthofAWeek = 7;

const string CommandParser::mondayIndicator1 = "monday";
const string CommandParser::mondayIndicator2 = "mon";
const string CommandParser::tuesdayIndicator1 = "tuesday";
const string CommandParser::tuesdayIndicator2 = "tue";
const string CommandParser::wednesdayIndicator1 = "wednesday";
const string CommandParser::wednesdayIndicator2 = "wed";
const string CommandParser::thursdayIndicator1 = "thursday";
const string CommandParser::thursdayIndicator2 = "thur";
const string CommandParser::thursdayIndicator3 = "thu";
const string CommandParser::fridayIndicator1 = "friday";
const string CommandParser::fridayIndicator2 = "fri";
const string CommandParser::saturdayIndicator1 = "saturday";
const string CommandParser::saturdayIndicator2 = "sat";
const string CommandParser::sundayIndicator1 = "sunday";
const string CommandParser::sundayIndicator2 = "sun";
const string CommandParser::nextIndicator = "next";
const string CommandParser::thisIndicator = "this";
const string CommandParser::todayIndicator1 = "today";
const string CommandParser::todayIndicator2 = "td";
const string CommandParser::tomorrowIndicator1 = "tomorrow";
const string CommandParser::tomorrowIndicator2 = "tmrw";
const string CommandParser::tomorrowIndicator3 = "tmr";

const int CommandParser::monday = 0;
const int CommandParser::tuesday = 1;
const int CommandParser::wednesday = 2;
const int CommandParser::thursday = 3;
const int CommandParser::friday = 4;
const int CommandParser::saturday = 5;
const int CommandParser::sunday = 6;
const int CommandParser::monthModerator1 = 30;
const int CommandParser::monthModerator2 = 31;
const int CommandParser::monthModerator3 = 29;
const int CommandParser::monthModerator4 = 28;
const int CommandParser::monthIndicator1 = 1;
const int CommandParser::monthIndicator2 = 2;
const int CommandParser::monthIndicator3 = 3;
const int CommandParser::monthIndicator4 = 4;
const int CommandParser::monthIndicator5 = 5;
const int CommandParser::monthIndicator6 = 6;
const int CommandParser::monthIndicator7 = 7;
const int CommandParser::monthIndicator8 = 8;
const int CommandParser::monthIndicator9 = 9;
const int CommandParser::monthIndicator10 = 10;
const int CommandParser::monthIndicator11 = 11;
const int CommandParser::monthIndicator12 = 12;
/* temporary variable assignment*/
string CommandParser::initial = "";
string CommandParser::userInput = initial;
string CommandParser::startDate = initial;
string CommandParser::startTime = initial;
string CommandParser::endDate = initial;
string CommandParser::endTime=initial;
string CommandParser::location = initial;
string CommandParser::name=initial;
string CommandParser::duration =initial;
string CommandParser::textDate = initial;
string CommandParser::textMonth =initial;
string CommandParser::currentDate = initial;
string CommandParser::taskDate = initial;
string CommandParser::currentYear = initial; 
string	CommandParser::weekNo = initial;
string CommandParser::specialDay = initial;
string CommandParser::part = initial;
string CommandParser::localMonth = initial;

int CommandParser::weekDay = 0;
int CommandParser::currentDay = 0;
int CommandParser::currentMonth = 0;
int CommandParser::currentWeekDay = 0;
int CommandParser::localYear = 0;
int CommandParser::taskYear=0;
int CommandParser::taskMonth=0;
int CommandParser::taskDay=0;
int CommandParser::lengthFront=0;
int CommandParser::lengthBack=0;
vector<string> CommandParser::parsedInput;
Calendar::COMMAND_TYPE CommandParser::_command = Calendar::COMMAND_TYPE::TASKINVALID;

//@author a0100789b
//this function is to check whether string small can be foudn in string big
bool CommandParser::isFound(string big, string small) {
	if (big.find(small)==string::npos) {
		return false;
	}
	return true;
}
//@author a0100644w
bool CommandParser::isFoundBack(string big, string small){
	if(big.rfind(small)==string::npos){
		return false;
	}
	return true;
}

//@author a0100789b
//this function is to check whether one string exist. for example, if startdate = string_not_exist,
//it means  startdate is absent from user input
bool CommandParser::isNotExist(string s) {
	if (s == Task::STRING_NOT_EXIST) {
		return true;
	}
	return false;
}


//this function is to check whether a string can be converted to integers
bool CommandParser::isNumber(string s) {
	try {	
		int temp = stoi(s);
		return true;
	} catch (exception &) {
		return false;
	}
}

//@author a0100644w
//get the local timezone
string CommandParser::getCurrentDate(){
	char buffer[100] = {0};
	time_t localTime;
	struct tm timenow;
	localTime = time(NULL);
	localtime_s(&timenow,&localTime);
	strftime(buffer, 100, "%d/%m/%Y",&timenow);
	currentWeekDay = (timenow.tm_wday+standardWeek)%lengthofAWeek;
	localYear = timenow.tm_year + standardYear;
	currentMonth = timenow.tm_mon+positionModerator1;
	currentDay = timenow.tm_mday;
	stringstream ss1,ss2,ss3;
	ss1 << localYear;
	ss1 >> currentYear;
	ss2 << currentMonth;
	ss2 >> localMonth;
	ss3 << buffer;
	ss3 >> currentDate;
	return currentDate;
}

//@author A0121007A
//this function is to check what is the command from the user (add/edit/view etc.)
string CommandParser::getCommand(string input){
	string cmd = input.substr(startingPosition, input.find(commandIndicator)); //first word in the user inpurt line
	Calendar::COMMAND_TYPE command = Utility::stringToCOMMAND_TYPE(cmd);
	CommandParser::_command = command;

	if (Utility::isValidCommand(command)) { //if the command is a valid command type, return it. else return "add"
		return cmd;
	}
	return Calendar::COMMAND_ADD; //if command was invalid, it means user wants to add
}

//@author a0100789b
//this function is to retrieve the date information by reading the string after "on"
string CommandParser::getStartDate(string input) {
	try {
		string uInput = input;
		while (isFound(uInput,startDateIndicator)) {		
			startDate = nextWord(uInput,startDateIndicator.substr(0,2));
			string temp = startDate.substr(0,1);
			if (!isNumber(temp)) {
				unsigned int start = uInput.find(startDateIndicator);
				start += startDateIndicator.size();
				uInput = uInput.substr(start, uInput.size()-start);
			}
			else {
				return startDate;
			}
		}
		if (startDate==initial){
			return Task::STRING_NOT_EXIST;
		}

		return Task::STRING_NOT_EXIST;
	} catch (exception &) {
		return Task::STRING_NOT_EXIST;
	}
}

//this function is to retrieve the time information by reading the information after "at"
string CommandParser::getStartTime(string input) {
	try {
		string uInput = input;
		while (isFound(uInput,startTimeIndicator)) {		
			startTime = nextWord(uInput,startTimeIndicator.substr(0,2));
			string temp = startTime.substr(0,1);
			if (!isNumber(temp)) {
				unsigned int start = uInput.find(startTimeIndicator);
				start += startTimeIndicator.size();
				uInput = uInput.substr(start, uInput.size()-start);
			}
			else {
				return startTime;
			}
		}
		if (startTime==initial) {
			return Task::STRING_NOT_EXIST;
		}
		return Task::STRING_NOT_EXIST;
	} catch (exception &) {
		startTime = Task::STRING_NOT_EXIST;
		return startTime;
	}
}


//if the task lasts for a few hours or a few days, the duration can be detected by using "-"
//connecting the starting and ending dates/time
string CommandParser::getDuration(string s) {
	try {
		unsigned int position = s.find(durationIndicator);
		unsigned int start, end;
		if (position == positionModerator1) {
			start = startingPosition;
			position += positionModerator2;
			end = s.find_first_of(commandIndicator,position);
			duration = s.substr(start, end-start);
			return duration;
		}
		position -= positionModerator2;
		start = s.find_last_of(commandIndicator,position);
		start += positionModerator1;
		position = s.find(durationIndicator);
		position += positionModerator2;
		if (position == s.size()) {
			end = s.size()-1;
			duration = s.substr(start, end-start);
			return duration;
		}
		end = s.find_first_of(commandIndicator,position);
		if (end == string::npos) {
			end = s.size();
		}
		duration = s.substr(start, end-start);
		return duration;
	} catch (exception &) {
		duration = Task::STRING_NOT_EXIST;
		return duration;
	}
}

//users can indicate location of a certain task by typing "at/in <location>
//if location is not specified, it will appear in the task name
string CommandParser::getLocation(string input) {
	location = Task::STRING_NOT_EXIST;

	try {
		unsigned int start = input.find(locationIndicatorStart);

		if (!isFound(input, locationIndicatorStart)||!isFound(input, locationIndicatorEnd)) {
			return location;
		}
		else {
			unsigned int end = input.find(locationIndicatorEnd);
			start += positionModerator2;
			unsigned int length = end - start;
			location = input.substr(start, length);
			return location;
		}
	} catch (exception &) {
		return location;
	}

}


//@author a0100644w
//This end date can be a deadline (by "date") or the end of a duration ("start date - end date")
string CommandParser::getEndDate(string input){
	try {
		if (!isFound(input,endDateIndicator)) {
			return Task::STRING_NOT_EXIST;
		}else if (isFound(nextWord(input, endDateIndicator),dayIndicator)){
		    endDate = nextWord(input, endDateIndicator);
			return endDate;
		}else if(isFound(nextWord(input, endDateIndicator), hourIndicator1) && isFound(nextWord(input, nextWord(input, endDateIndicator)), dayIndicator) ||
		    isFound(nextWord(input, endDateIndicator), hourIndicator2) && isFound(nextWord(input, nextWord(input, endDateIndicator)), dayIndicator) ||
			isFound(nextWord(input, endDateIndicator), afternoonIndicator) && isFound(nextWord(input, nextWord(input, endDateIndicator)), dayIndicator) ||
			isFound(nextWord(input, endDateIndicator),morningIndicator)&&isFound(nextWord(input, nextWord(input, endDateIndicator)), dayIndicator)||
			isNumber(nextWord(input, endDateIndicator)) && isFound(nextWord(input, nextWord(input, endDateIndicator)), dayIndicator)){
				endDate = nextWord(input, nextWord(input, endDateIndicator));
				return endDate;
		}else{
	        return Task::STRING_NOT_EXIST;
	    }
	}catch (exception &) {
	    return Task::STRING_NOT_EXIST;
	}
}

//similar to end date
string CommandParser::getEndTime(string input){
	try {
		if (!isFound(input,endDateIndicator)) {
			return Task::STRING_NOT_EXIST;
		}else if(isFound(nextWord(input, endDateIndicator), hourIndicator1) || isFound(nextWord(input, endDateIndicator), hourIndicator2)||
				isFound(nextWord(input, endDateIndicator), afternoonIndicator) || isFound(nextWord(input, endDateIndicator),morningIndicator)||
				isNumber(nextWord(input,endDateIndicator)) && !isFound(nextWord(input, endDateIndicator), dayIndicator)){
					endTime = nextWord(input, endDateIndicator);
					return endTime;
		}else if(isFound(nextWord(input, endDateIndicator), dayIndicator) && isFound(nextWord(input, nextWord(input, endDateIndicator)), hourIndicator1)||
			isFound(nextWord(input, endDateIndicator), dayIndicator) && isFound(nextWord(input, nextWord(input, endDateIndicator)), hourIndicator2)||
			isFound(nextWord(input, endDateIndicator), dayIndicator) && isFound(nextWord(input, nextWord(input, endDateIndicator)), afternoonIndicator)||
			isFound(nextWord(input, endDateIndicator), dayIndicator) && isFound(nextWord(input, nextWord(input, endDateIndicator)),morningIndicator)||
			isFound(nextWord(input, endDateIndicator), dayIndicator) && isNumber(nextWord(input, nextWord(input, endDateIndicator))) &&
			!isFound(nextWord(input,nextWord(input,endDateIndicator)),dayIndicator)){
				endTime = nextWord(input, nextWord(input, endDateIndicator));
				return endTime;
		}else{
			return Task::STRING_NOT_EXIST;
		}
	}catch (exception &) {
		return Task::STRING_NOT_EXIST;
	}
}

//@author a0100789b
//this is to extract the start date/time from the duration
string CommandParser::getDurationStart() {
	try {
		unsigned int end = duration.find_first_of(durationIndicator);
		string durationStart = duration.substr(startingPosition,end);
		if (isFound(durationStart, commandIndicator)) {
			return duration.substr(startingPosition,end-positionModerator1);
		}
		return durationStart;

	} catch (exception &) {
		return Task::STRING_NOT_EXIST;
	}
}

//this is to extract the end date/time from the duration
string CommandParser::getDurationEnd() {
	try {
		unsigned int start = duration.find(durationIndicator);
		start += positionModerator1;
		string durationEnd = duration.substr(start,duration.size()-start);
		if (isFound(durationEnd,commandIndicator)) {
			return durationEnd.substr(positionModerator1,durationEnd.size()-positionModerator1);
		}
		return durationEnd;
	} catch (exception &) {
		return Task::STRING_NOT_EXIST;
	}
}

/*this is to extract year from date information by using indicator "/", 
similar for the following month and day function for both start and end date*/
string CommandParser::getStartYear() {
	if (isNotExist(startDate)) {
		return Task::STRING_NOT_EXIST;
	} else {

		if (startDate.find_first_of(dayIndicator) == startDate.find_last_of(dayIndicator)){ // there is only one slash in date format
			getCurrentDate();
			return currentYear;
		}
		string year = startDate.substr(startDate.find_last_of(dayIndicator)+positionModerator1,
			startDate.size() - startDate.find_last_of(dayIndicator));
		startDate = startDate.substr(startingPosition,startDate.find_last_of(dayIndicator));
		return year;
	}
}

string CommandParser::getStartMonth() {

	if (isNotExist(startDate)) {
		return Task::STRING_NOT_EXIST;
	}
	string month ;
	if (!isFound(startDate,dayIndicator)){
		getCurrentDate();
		return localMonth;
	}
	month= startDate.substr(startDate.find_first_of(dayIndicator)+positionModerator1,
		startDate.find_last_of(dayIndicator) - startDate.find_first_of(dayIndicator)-positionModerator1);
	startDate = startDate.substr(startingPosition,startDate.find_first_of(dayIndicator));
	return month;
}

string CommandParser::getStartDay(){

	return startDate;
}

//the following two functions is to extact hour and minute from a time string
//by using the indicator ":" and "."
//similar for end hour and end minute
string CommandParser::getStartHour(){

	try {
		if (isNotExist(startTime)) {
			return Task::STRING_NOT_EXIST;
		}
		string startHour;
		if (startTime.find_first_of(hourIndicator)==string::npos) { //if only hour is indicated
			if (isFound(startTime,afternoonIndicator)) { //if "pm" is detected
				startHour = startTime.substr(startingPosition,startTime.find(afternoonIndicator));
				unsigned int temp = stoi(startHour); //convert string hour to an integer hour
				if (temp>0 && temp <12) { //if not noon or midnight, add 12 to convert to 24-hour timing
					temp += hourModerator;
				}	
				startHour = to_string(temp);//convert back to string
				return startHour;
			}
			if (isFound(startTime,morningIndicator)) {
				startHour = startTime.substr(startingPosition,startTime.find(morningIndicator));
				return startHour;
			}
			return startTime;
		}
		else {
			if (isFound(startTime,afternoonIndicator)) {
				startTime = startTime.substr(startingPosition,startTime.find(afternoonIndicator));
				string hour = startTime.substr(startingPosition,startTime.find_first_of(hourIndicator));
				unsigned int temp = stoi(hour);
				if (temp>0 && temp<12) {
					temp += hourModerator;
				}
				hour = to_string(temp);
				return hour;
			}
			if (isFound(startTime,morningIndicator)) {
				startTime = startTime.substr(startingPosition,startTime.find(morningIndicator));
			}

			return startTime.substr(startingPosition,startTime.find_first_of(hourIndicator));
		}
	} catch (exception &) {
		return Task::STRING_NOT_EXIST;
	}
}

string CommandParser::getStartMinute(){

	try {
		if (isNotExist(startTime)) {
			return Task::STRING_NOT_EXIST;
		}
		unsigned int start = startTime.find_first_of(hourIndicator);
		if (start == string::npos) {
			return minuteNotExist;
		}
		start += positionModerator1;
		return startTime.substr(start, startTime.size() - start);
	} catch (exception &) {
		return Task::STRING_NOT_EXIST;
	}
}


//@author a0100644w
string CommandParser::getEndYear(){
	if (isNotExist(endDate)) {
		return Task::STRING_NOT_EXIST;
	} else {

		if (endDate.find_first_of(dayIndicator) == endDate.find_last_of(dayIndicator)){ // there is only one slash in date format
			getCurrentDate();
			return currentYear;
		}
		string year = endDate.substr(endDate.find_last_of(dayIndicator) + positionModerator1,
			endDate.size() - endDate.find_last_of(dayIndicator));
		endDate = endDate.substr(startingPosition,endDate.find_last_of(dayIndicator));
		return year;
	}
}

string CommandParser::getEndMonth(){
	if (isNotExist(endDate)) {
		return Task::STRING_NOT_EXIST;
	}
	string month = endDate.substr(endDate.find_first_of(dayIndicator) + positionModerator1,
		endDate.find_last_of(dayIndicator) - endDate.find_first_of(dayIndicator) - positionModerator1);
	endDate = endDate.substr(startingPosition, endDate.find_first_of(dayIndicator));
	return month;
}

string CommandParser::getEndDay(){
	return endDate;
}

string CommandParser::getEndHour(){
	
	try {
		if (isNotExist(endTime)) {
			return Task::STRING_NOT_EXIST;
		}
		string endHour;
		if (endTime.find_first_of(hourIndicator)==string::npos) { //if only hour is indicated
			if (isFound(endTime,afternoonIndicator)) { //if "pm" is detected
				endHour = endTime.substr(startingPosition,endTime.find(afternoonIndicator));
				unsigned int temp = stoi(endHour); //convert string hour to an integer hour
				if (temp>startingPosition && temp <hourModerator) { //if not noon or midnight, add 12 to convert to 24-hour timing
					temp += hourModerator;
				}	
				endHour = to_string(temp);//convert back to string
				return endHour;
			}
			if (isFound(endTime,morningIndicator)) {
				endHour = endTime.substr(startingPosition,endTime.find(morningIndicator));
				return endHour;
			}
			return endTime;
		}
		else {
			if (isFound(endTime,afternoonIndicator)) {
				endTime = endTime.substr(startingPosition,endTime.find(afternoonIndicator));
				string hour = endTime.substr(startingPosition,endTime.find_first_of(hourIndicator));
				unsigned int temp = stoi(hour);
				if (temp>startingPosition && temp<hourModerator) {
					temp += hourModerator;
				}
				hour = to_string(temp);
				return hour;
			}
			if (isFound(endTime,morningIndicator)) {
				endTime = endTime.substr(startingPosition,endTime.find(morningIndicator));
			}

			return endTime.substr(startingPosition,endTime.find_first_of(hourIndicator));
		}
	} catch (exception &) {
		return Task::STRING_NOT_EXIST;
	}
}

string CommandParser::getEndMinute(){
	try {
		if (isNotExist(endTime)) {
			return Task::STRING_NOT_EXIST;
		}
		unsigned int start = endTime.find_first_of(hourIndicator);
		if (start == string::npos){
			return minuteNotExist;
		}
		start += positionModerator1;
		return endTime.substr(start, endTime.size() - start);
	} catch (exception &) {
		return Task::STRING_NOT_EXIST;
	}
}

string CommandParser::getPriority(string input) {
	return Task::STRING_NOT_EXIST;
}


//@author a0100789b
//extract task name from user input 
string CommandParser::getName(string input){

	name = input;

	try {
		//duration
		string temp = durationIndicator1 + duration;
		if (isFound(name, temp)) {
			name = reSequence(name, temp);
		}
		temp = startTimeIndicator+duration;
		if (isFound(name, temp)) {
			name = reSequence(name, temp);
		}
		temp = startDateIndicator +duration;
		if (isFound(name,temp)) {
			name = reSequence(name, temp);
		}
		if (isFound(name, duration)) {
			name = reSequence(name, duration);
		}
		//start date
		temp = startDateIndicator+startDate;
		if (isFound(name,temp)) {
			name = reSequence(name, temp);
		}
		//end date
		temp = endDateIndicator+commandIndicator+endDate;
		if (isFound(name, temp)) {
			name = reSequence(name, temp);
		}
		if (isFound(name, endDate)) {
			name = reSequence(name,endDate);
		}

		//location
		temp = locationIndicator1 + locationIndicatorStart + location + locationIndicatorEnd;
		if (isFound(name,temp)) {
			name = reSequence(name, temp);
		}
		temp = locationIndicator2 + locationIndicatorStart + location + locationIndicatorEnd;
		if (isFound(name, temp)) {
			name = reSequence(name,temp);
		}
		temp = locationIndicatorStart + location + locationIndicatorEnd;
		if (isFound(name, temp)) {
			name = reSequence(name,temp);
		}

		//start time
		temp = startTimeIndicator + startTime;
		if (isFound(name, temp)) {
			name = reSequence(name, temp);
		}
		//end time
		temp = endDateIndicator + commandIndicator + endTime;
		if (isFound(name, temp)) {
			name = reSequence(name, temp);
		}
		if (isFound(name, endTime)) {
			name = reSequence(name, endTime);
		}
		int i = positionModerator1;
		while (name.substr(startingPosition,positionModerator1)==commandIndicator||
			   name.substr(startingPosition,positionModerator1)==durationIndicator) {
			name = name.substr(i,name.size()-positionModerator1);
		}
		int j = positionModerator1;
		while (name.substr(name.size()-positionModerator1,positionModerator1)==commandIndicator||
			   name.substr(name.size()-positionModerator1,positionModerator1)==durationIndicator) {
			name = name.substr(startingPosition,name.size()-positionModerator1);
		}
		if (name == initial) {
			name = Task::STRING_NOT_EXIST;
		}
		return name;


	} catch (exception &) {
		return name;
	}

}

//this fucntion is to exclude string small from string big
string CommandParser::reSequence(string big, string small) {
	string front = big.substr(startingPosition,big.find(small));
	unsigned int start = big.find(small)+small.size();
	string back = big.substr(start, big.size()-start);
	big = front + back;
	return big;
}

string CommandParser::getKeywords(string input) {

	try {
		unsigned int start = input.find_first_of(commandIndicator);
		start += positionModerator1;
		return input.substr(start, input.size()-start);
	} catch (exception &) {
		return Task::STRING_NOT_EXIST;
	}

}

string CommandParser::getDescription(string input) {
	return Task::STRING_NOT_EXIST;
}

//this is to modify start date/time and end date/time information if a duration is detected
void CommandParser::dateTimeModifier() {
	if (!isFound(duration,dayIndicator)) {
		startTime = getDurationStart();
		if (isFound(duration,afternoonIndicator) &&
			duration.find(afternoonIndicator)==duration.rfind(afternoonIndicator)) {
				unsigned int temp = stoi(startTime);
				temp += hourModerator;
				startTime = to_string(temp);
		}
		endTime = getDurationEnd(); 
	} else {
		startDate = getDurationStart();
		endDate = getDurationEnd();
	}	
}



vector<string> CommandParser::getParsedUserInput(string input){

	vector<string> parsedInput(Task::ATTR::SIZE);
	parsedInput[Task::ATTR::COMMAND] = getCommand(input);

	Calendar::COMMAND_TYPE cmd = Utility::stringToCOMMAND_TYPE(getCommand(input));
	transform(input.begin(), input.end(), input.begin(), tolower);
	switch (cmd) {
	case Calendar::COMMAND_TYPE::TASKADD:
		while (hasTextMonth(input)) { // this is to check whether the user used "january" "feb" etc.
			string front = input.substr(startingPosition,input.find(textDate));
			unsigned int start = input.find(textDate)+textDate.size();
			string back = input.substr(start, input.size()-start);
			string numberDate = convertTextToNumber(textDate);
			input = front + numberDate + back;
			textDate = initial;
		}

		while(hasWeekDay(input)){
			if(weekNo == nextIndicator || weekNo == thisIndicator){
				lengthFront = lengthFront - positionModerator1 - weekNo.size();
			}else if(weekNo == dateIndicator || weekNo == endDateIndicator || weekNo == endTime){
				lengthFront = lengthFront;
			}
			string front = input.substr(startingPosition, lengthFront);
			string back = input.substr(lengthBack, input.size() - lengthBack);
			input = front + getDateFromWeek() + back;
		}

		while(hasSpecialDay(input)){
			string front = input.substr(startingPosition,lengthFront);
			string back = input.substr(lengthBack,input.size()-lengthBack);
			input = front + getDateFromWeek() + back;
		}

		//normal starting date/time and end date/time by indicator "on" and "at"
		startDate = getStartDate(input);
		startTime = getStartTime(input);
		endDate = getEndDate(input);
		endTime = getEndTime(input);

		//detect duration and modify start date/time and end date/time
		duration = Task::STRING_NOT_EXIST;
		part = input;
		while (isFound(part, durationIndicator)) {
			int position = part.find(durationIndicator);
			position += positionModerator1;
			string temp = part.substr(part.find_first_not_of(commandIndicator,position),1);
			if (isNumber(temp)) {
				duration = getDuration(part);
				dateTimeModifier();
			}
			part = part.substr(position, part.size()-position);
		}

        //default start date as the date of today, if there is start time or deadline but no start date
		if(isNotExist(startDate) && !isNotExist(startTime) || !isNotExist(endTime) && isNotExist(startDate)){
			getCurrentDate();
			if(endDate != currentDate){
			    startDate = currentDate;
			}else{
				startDate = Task::STRING_NOT_EXIST;
			}
		}

		//default end date as the date of today, if there is end time and the start date is today
		if(isNotExist(endDate) && !isNotExist(endTime) && isNotExist(startTime)){
			getCurrentDate();
			if(startDate == currentDate){
			    endDate = currentDate;
			}else{
				endDate =  Task::STRING_NOT_EXIST;
			}
		}

		location = getLocation(input);
		name = getName(input);
		parsedInput[Task::ATTR::STARTYEAR] = getStartYear();
		parsedInput[Task::ATTR::STARTMONTH] = getStartMonth();
		parsedInput[Task::ATTR::STARTDAY] = getStartDay();
		parsedInput[Task::ATTR::STARTHOUR] = getStartHour();
		parsedInput[Task::ATTR::STARTMINUTE] = getStartMinute();
		parsedInput[Task::ATTR::ENDYEAR] = getEndYear();
		parsedInput[Task::ATTR::ENDMONTH] = getEndMonth();
		parsedInput[Task::ATTR::ENDDAY] = getEndDay();
		parsedInput[Task::ATTR::ENDHOUR] = getEndHour();
		parsedInput[Task::ATTR::ENDMINUTE] = getEndMinute();
		parsedInput[Task::ATTR::PRIORITY] = getPriority(input);
		parsedInput[Task::ATTR::NAME] = name;
		parsedInput[Task::ATTR::DESCRIPTION] = getDescription(input);
		parsedInput[Task::ATTR::LOCATION] = getLocation(input);
		parsedInput[Task::ATTR::ISDONE] = "false";
		if (startDate == Task::STRING_NOT_EXIST && endDate == Task::STRING_NOT_EXIST) {
			parsedInput[Task::ATTR::HASDATE] = "false";
			parsedInput[Task::ATTR::HASEXPIRED] = "false";
		}
		else{
			parsedInput[Task::ATTR::HASDATE] = "true";
			parsedInput[Task::ATTR::HASEXPIRED] = "false";
		}
		break;
	case Calendar::COMMAND_TYPE::TASKEDIT:
		parsedInput.resize(EDIT::EDIT::LASTPOSITION);
		parsedInput[EDIT::EDIT::SEARCH_KEYWORDS] = getKeywords(input);
		break;
	case Calendar::COMMAND_TYPE::TASKREMIND:
		parsedInput[REMIND::REMIND::SEARCH_KEYWORDS] = getKeywords(input);
		break;
	case Calendar::COMMAND_TYPE::TASKREPEAT:
		parsedInput[REPEAT::REPEAT::SEARCH_KEYWORDS] = getKeywords(input);
		break;
	default:
		parsedInput[Task::ATTR::NAME] = getKeywords(input);
		break;
	}

	return parsedInput;
}


//@author a0100644w
/* gets date and time from user input from edit request */
vector<string> CommandParser::getDateAndTime(string input) {
	vector<string> dateAndTime(DATE_ENUM::DATE_ENUM::LASTPOSITION);

	while (hasTextMonth(input)) {
		string front = input.substr(startingPosition,input.find(textDate));
		unsigned int start = input.find(textDate)+textDate.size();
		string back = input.substr(start, input.size()-start);
		string numberDate = convertTextToNumber(textDate);			
		input = front + numberDate + back;
	}
		
	while(hasWeekDay(input)){
		if(weekNo == nextIndicator || weekNo == thisIndicator){
				lengthFront = lengthFront - positionModerator1 - weekNo.size();
		}else if(weekNo == dateIndicator || weekNo == endDateIndicator || weekNo == endTime){
				lengthFront = lengthFront;
		}
	    string front = input.substr(startingPosition, lengthFront);
	    string back = input.substr(lengthBack,input.size() - lengthBack);
		input = front + getDateFromWeek() + back;
	}

	while(hasSpecialDay(input)){
		string front = input.substr(startingPosition,lengthFront);
		string back = input.substr(lengthBack,input.size()-lengthBack);
		input = front + getDateFromWeek() + back;
	}
	startDate = getStartDate(input);
	startTime = getStartTime(input);
	endDate = getEndDate(input);
	endTime = getEndTime(input);
	duration = Task::STRING_NOT_EXIST;
		part = input;
		while (isFound(part, durationIndicator)) {
			int position = part.find(durationIndicator);
			position += positionModerator1;
			string temp = part.substr(part.find_first_not_of(commandIndicator,position),1);
			if (isNumber(temp)) {
				duration = getDuration(part);
				dateTimeModifier();
			}
			part = part.substr(position, part.size()-position);
		}

	if(isNotExist(startDate) && !isNotExist(startTime) ||!isNotExist(endTime) && isNotExist(startDate)){
			getCurrentDate();
			if(endDate != currentDate){
			    startDate = currentDate;
			}else{
				startDate = Task::STRING_NOT_EXIST;
			}
		}

	if(isNotExist(endDate)&&!isNotExist(endTime)&&isNotExist(startTime)){
		getCurrentDate();
		if(startDate == currentDate){
		    endDate = currentDate;
		}else{
			endDate =  Task::STRING_NOT_EXIST;
		}
	}

	dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTYEAR) = getStartYear();
	dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTMONTH) = getStartMonth();
	dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTDAY) = getStartDay();
	dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTHOUR) = getStartHour();
	dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTMINUTE) = getStartMinute();
	dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDYEAR) = getEndYear();
	dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDMONTH) = getEndMonth();
	dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDDAY) = getEndDay();
	dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDHOUR) = getEndHour();
	dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDMINUTE) = getEndMinute();

	dateAndTime.at(DATE_ENUM::DATE_ENUM::ISDONE) = "false";
	if (startDate == Task::STRING_NOT_EXIST && endDate == Task::STRING_NOT_EXIST) {
		dateAndTime.at(DATE_ENUM::DATE_ENUM::HASDATE) = "false";
		dateAndTime.at(DATE_ENUM::DATE_ENUM::HASEXPIRED) = "false";
	}
	else{
		dateAndTime.at(DATE_ENUM::DATE_ENUM::HASDATE) = "true";
		dateAndTime.at(DATE_ENUM::DATE_ENUM::HASEXPIRED) = "false";
	}

	return dateAndTime;
}

//@author a0100789b
// this function is to return the previous word (if any) of string small in string big
string CommandParser::previousWord(string big, string small) {
	unsigned int end = big.find(small);
	end -= positionModerator1;
	unsigned int start = end-positionModerator1;
	start = big.rfind(commandIndicator,start);
	start += positionModerator1;
	return big.substr(start, end-start);
}

// thiz is to return the next word (if any) of string small in string big
string CommandParser::nextWord(string big, string small) {
	try {
		unsigned int start = big.find(small);
		start += small.size();
		start += positionModerator1;
		unsigned int end = big.find(commandIndicator,start);
		return big.substr(start, end-start);
	} catch (exception &) {
		return small;
	}
}

//this function is to convert things like "january 1st" to "1/1"
string CommandParser::convertTextToNumber(string s) {
	string word1;
	string word2;
	string word3;
	string day;
	if (s.find(commandIndicator) == s.rfind(commandIndicator)) {
		word1 = s.substr(startingPosition,s.find(commandIndicator));
		unsigned int start = s.find(commandIndicator)+positionModerator1;
		word2= s.substr(start, s.size()-start);
		string temp = word1.substr(startingPosition,1);
		if (isNumber(temp)) {
			day = temp.substr(startingPosition,1);
			temp = word1.substr(1,1);
			if (isNumber(temp)) {
				day = word1.substr(startingPosition,2);
			}
		}
		else {
			string temp = word2.substr(1,1);
			if (isNumber(temp)) {
				day = word2.substr(startingPosition,2);
			}
			else {
				day = word2.substr(startingPosition,1);
			}
		}
		return day + dayIndicator + textMonth;
	}
	else {
		word1 = s.substr(startingPosition,s.find(commandIndicator));
		unsigned int start = s.find(commandIndicator)+positionModerator1;
		word2 = s.substr(start,s.rfind(commandIndicator)-start);
		start = s.rfind(commandIndicator)+positionModerator1;
		word3 = s.substr(start,s.size()-start);
		if (isNumber(word1) && word1.size() == 4) {
			return convertTextToNumber(word2 + commandIndicator + word3) + dayIndicator + word1;
		}
		if (isNumber(word2) && word2.size() == 4) {
			return convertTextToNumber(word1 + commandIndicator + word3) + dayIndicator + word2;
		}
		if (isNumber(word3) && word3.size() == 4) {
			return convertTextToNumber(word1 + commandIndicator + word2) + dayIndicator + word3;
		}
	}

}

//this is to detect and extract text month like january 1st from the user input
void CommandParser::getTextMonth(string input, string indicator) {
	unsigned int start = input.find(indicator);
	unsigned int end = input.find(indicator)+indicator.size();
	string temp;

	if (start != 0) {

		string previous = previousWord(input, indicator);
		temp = previous.substr(startingPosition,1);
		if (isNumber(temp)) {
			start = input.rfind(previous,start);
		}
	}
	if (end != input.size()){
		string next = nextWord(input, indicator);
		temp = next.substr(startingPosition,1);
		if (isNumber(temp)) {
			end = input.find(next,start)+next.size();
			if (end!=input.size()){
				next = nextWord(input,commandIndicator + next);
				temp = next.substr(startingPosition,1);
				if (isNumber(temp)) {
					end = input.find(next,start)+next.size();
				}
			}
		}
	}
	if (start == input.find(indicator) &&
		end == input.find(indicator)+indicator.size()) {
			textMonth == Task::STRING_NOT_EXIST;
	}
	else {
		textDate = input.substr(start, end-start);
	}
}

//check if the string found from the start is a single word separated by spaces
bool CommandParser::isIndependent(string input, string s) {
	try {
	if (input.find(s) == 0&&input.substr(input.find(s)+s.size(),1) != commandIndicator) {
			return false;
	}else if(input.find(s)+s.size()-1 == input.size()&&input.substr(input.find(s)-1,1) != commandIndicator){
	    return false;
	}else if ((input.substr(input.find(s)+s.size(),1)) != commandIndicator||
		(input.substr(input.find(s)-1,1) != commandIndicator)){
	    return false;
	}else{
	return true;
	}
	} catch (exception &) {
		return false;
	}
}
//@author a0100644w
//@author a0100644w
//check if the string found from back is a single word separated by spaces
bool CommandParser::isIndependentBack(string input, string s) {
	if (input.rfind(s) == startingPosition && input.substr(input.rfind(s)+s.size(), positionModerator1) != commandIndicator) {
			return false;
	}else if(input.rfind(s)+s.size() - positionModerator1 == input.size() &&
		input.substr(input.rfind(s) - positionModerator1, positionModerator1) != commandIndicator){
			return false;
	}else if ((input.substr(input.rfind(s)+s.size(),positionModerator1)) != commandIndicator&&
		(input.substr(input.rfind(s) - positionModerator1, positionModerator1) != commandIndicator)){
			return false;
	}else{
		return true;
	}
}
//@author a0100789b
//@author a0100789b
//this function is to check whther a text month is included in user input
bool CommandParser::hasTextMonth(string input){
	try {
	string substring;
	if (isFound(input, januaryIndicator1)) {
		textMonth = textMonth1;
		substring = input;
		while (isFound(substring,januaryIndicator1)) {
				getTextMonth(substring,januaryIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(januaryIndicator1)+januaryIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, januaryIndicator2)) {
		textMonth = textMonth1;
		substring = input;
		while (isFound(substring,januaryIndicator2)) {
				getTextMonth(substring,januaryIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(januaryIndicator2)+januaryIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, febIndicator1)) {
		textMonth = textMonth2;
		substring = input;
		while (isFound(substring,febIndicator1)) {
				getTextMonth(substring,febIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(febIndicator1)+febIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	
	if (isFound(input, febIndicator2)) {
		textMonth = textMonth2;
		substring = input;
		while (isFound(substring,febIndicator2)) {
				getTextMonth(substring,febIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(febIndicator2)+febIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	
	if (isFound(input, marchIndicator1)) {
		textMonth = textMonth3;
		substring = input;
		while (isFound(substring,marchIndicator1)) {
				getTextMonth(substring,marchIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(marchIndicator1)+marchIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, marchIndicator2)) {
		textMonth = textMonth3;
		substring = input;
		while (isFound(substring,marchIndicator2)) {
				getTextMonth(substring,marchIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(marchIndicator2)+marchIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, aprilIndicator1)) {
		textMonth = textMonth4;
		substring = input;
		while (isFound(substring,aprilIndicator1)) {
				getTextMonth(substring,aprilIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(aprilIndicator1)+aprilIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, aprilIndicator2)) {
		textMonth = textMonth4;
		substring = input;
		while (isFound(substring,aprilIndicator2)) {
				getTextMonth(substring,aprilIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(aprilIndicator2)+aprilIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, mayIndicator1)) {
		textMonth = textMonth5;
		substring = input;
		while (isFound(substring,mayIndicator1)) {
				getTextMonth(substring,mayIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(mayIndicator1)+mayIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	
	if (isFound(input, juneIndicator1)) {
		textMonth = textMonth6;
		substring = input;
		while (isFound(substring,juneIndicator1)) {
				getTextMonth(substring,juneIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(juneIndicator1)+juneIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, juneIndicator2)) {
		textMonth = textMonth6;
		substring = input;
		while (isFound(substring,juneIndicator2)) {
				getTextMonth(substring,juneIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(juneIndicator2)+juneIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	
	if (isFound(input, julyIndicator1)) {
		textMonth = textMonth7;
		substring = input;
		while (isFound(substring,julyIndicator1)) {
				getTextMonth(substring,julyIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(julyIndicator1)+julyIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	
	if (isFound(input, julyIndicator2)) {
		textMonth = textMonth7;
		substring = input;
		while (isFound(substring,julyIndicator2)) {
				getTextMonth(substring,julyIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(julyIndicator2)+julyIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, augIndicator1)) {
		textMonth = textMonth8;
		substring = input;
		while (isFound(substring,augIndicator1)) {
				getTextMonth(substring,augIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(augIndicator1)+augIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, augIndicator2)) {
		textMonth = textMonth8;
		substring = input;
		while (isFound(substring,augIndicator2)) {
				getTextMonth(substring,augIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(augIndicator2)+augIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, septIndicator1)) {
		textMonth = textMonth9;
		substring = input;
		while (isFound(substring,septIndicator1)) {
				getTextMonth(substring,septIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(septIndicator1)+septIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, septIndicator2)) {
		textMonth = textMonth9;
		substring = input;
		while (isFound(substring,septIndicator2)) {
				getTextMonth(substring,septIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(septIndicator2)+septIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, septIndicator3)) {
		textMonth = textMonth9;
		substring = input;
		while (isFound(substring,septIndicator3)) {
				getTextMonth(substring,septIndicator3);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(septIndicator3)+septIndicator3.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, octIndicator1)) {
		textMonth = textMonth10;
		substring = input;
		while (isFound(substring,octIndicator1)) {
			getTextMonth(substring,octIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(octIndicator1)+octIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, octIndicator2)) {
		textMonth = textMonth10;
		substring = input;
		while (isFound(substring,octIndicator2)) {
				getTextMonth(substring,octIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(octIndicator2)+octIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	
	if (isFound(input, novIndicator1)) {
		textMonth = textMonth11;
		substring = input;
		while (isFound(substring,novIndicator1)) {
				getTextMonth(substring,novIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(novIndicator1)+novIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, novIndicator2)) {
		textMonth = textMonth11;
		substring = input;
		while (isFound(substring,novIndicator2)) {
				getTextMonth(substring,novIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(novIndicator2)+novIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, decIndicator1)) {
		textMonth = textMonth12;
		substring = input;
		while (isFound(substring,decIndicator1)) {
				getTextMonth(substring,decIndicator1);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(decIndicator1)+decIndicator1.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (isFound(input, decIndicator2)) {
		textMonth = textMonth12;
		substring = input;
		while (isFound(substring,decIndicator2)) {
				getTextMonth(substring,decIndicator2);
			if (isFound(textDate,commandIndicator)) {
				return true;
			}
			unsigned int start = substring.find(decIndicator2)+decIndicator2.size();
			substring = substring.substr(start,substring.size()-start);
		}
	}
	if (textMonth == initial || !isFound(textMonth,commandIndicator)) {
		return false;
	}
	} catch (exception &) {
		return false;
		}
}


//@author a0100644w
//check the previous word before the weekday(mon - sun)
string CommandParser::weekNumber(string big, string small) {
	unsigned int end = big.rfind(small);
	unsigned int start = end - positionModerator1;
	big = big.substr(startingPosition, start);
	start = big.rfind(commandIndicator,start);
	start += positionModerator1;
	end -=positionModerator1;
	return big.substr(start, end-start);
}

//check if the user type weekDay (mon- sun) to represent the date
bool CommandParser::hasWeekDay(string input){
	endTime = getEndTime(input);
	if(isFound(input, mondayIndicator1)&&isIndependent(input, mondayIndicator1)&&
		(weekNumber(input, mondayIndicator1) == thisIndicator || weekNumber(input, mondayIndicator1) == nextIndicator||
		weekNumber(input, mondayIndicator1) == dateIndicator || weekNumber(input, mondayIndicator1) == endDateIndicator||
		weekNumber(input, mondayIndicator1) == endTime)){
		lengthFront = input.find(mondayIndicator1);
		lengthBack = lengthFront + mondayIndicator1.size();
		weekDay = monday;
		weekNo = weekNumber(input, mondayIndicator1);
		return true;
	}else if(isFoundBack(input, mondayIndicator1) && isIndependentBack(input, mondayIndicator1)&&
		(weekNumber(input, mondayIndicator1) == thisIndicator || weekNumber(input, mondayIndicator1) == nextIndicator||
		weekNumber(input, mondayIndicator1) == dateIndicator || weekNumber(input, mondayIndicator1) == endDateIndicator||
		weekNumber(input, mondayIndicator1) == endTime)){
		lengthFront = input.rfind(mondayIndicator1);
		lengthBack = lengthFront + mondayIndicator1.size();
		weekDay = monday;
		weekNo = weekNumber(input, mondayIndicator1);
		return true;
	}else if(isFound(input, mondayIndicator2) && isIndependent(input, mondayIndicator2)&&
		(weekNumber(input, mondayIndicator2) == thisIndicator || weekNumber(input, mondayIndicator2) == nextIndicator||
		weekNumber(input, mondayIndicator2) == dateIndicator||weekNumber(input, mondayIndicator2) == endDateIndicator||
		weekNumber(input, mondayIndicator2) == endTime)){
		lengthFront = input.find(mondayIndicator2);
		lengthBack = lengthFront + mondayIndicator2.size();
		weekDay = monday;
		weekNo = weekNumber(input, mondayIndicator2);
		return true;
	}else if(isFoundBack(input, mondayIndicator2) && isIndependentBack(input, mondayIndicator2)&&
		(weekNumber(input, mondayIndicator2) == thisIndicator || weekNumber(input, mondayIndicator2) == nextIndicator||
		weekNumber(input, mondayIndicator2) == dateIndicator || weekNumber(input, mondayIndicator2) == endDateIndicator||
		weekNumber(input, mondayIndicator2) == endTime)){
		lengthFront = input.rfind(mondayIndicator2);
		lengthBack = lengthFront + mondayIndicator2.size();
		weekDay = monday;
		weekNo = weekNumber(input, mondayIndicator2);
		return true;
	}else if(isFound(input, tuesdayIndicator1) && isIndependent(input, tuesdayIndicator1)&&
		(weekNumber(input, tuesdayIndicator1) == thisIndicator || weekNumber(input, tuesdayIndicator1) == nextIndicator||
		weekNumber(input, tuesdayIndicator1) == dateIndicator || weekNumber(input, tuesdayIndicator1) == endDateIndicator||
		weekNumber(input, tuesdayIndicator1) == endTime)){
		lengthFront = input.find(tuesdayIndicator1);
		lengthBack = lengthFront + tuesdayIndicator1.size();
		weekDay = tuesday;
		weekNo = weekNumber(input, tuesdayIndicator1);
		return true;
	}else if(isFoundBack(input, tuesdayIndicator1) && isIndependentBack(input, tuesdayIndicator1)&&
		(weekNumber(input, tuesdayIndicator1) == thisIndicator || weekNumber(input, tuesdayIndicator1) == nextIndicator||
		weekNumber(input, tuesdayIndicator1) == dateIndicator || weekNumber(input, tuesdayIndicator1) == endDateIndicator||
		weekNumber(input, tuesdayIndicator1) == endTime)){
		lengthFront = input.rfind(tuesdayIndicator1);
		lengthBack = lengthFront + tuesdayIndicator1.size();
		weekDay = tuesday;
		weekNo = weekNumber(input, tuesdayIndicator1);
		return true;
	}else if(isFound(input, tuesdayIndicator2) && isIndependent(input, tuesdayIndicator2)&&
		(weekNumber(input, tuesdayIndicator2) == thisIndicator || weekNumber(input, tuesdayIndicator2) == nextIndicator||
		weekNumber(input, tuesdayIndicator2) == dateIndicator || weekNumber(input, tuesdayIndicator2) == endDateIndicator||
		weekNumber(input, tuesdayIndicator2) == endTime)){
		lengthFront = input.find(tuesdayIndicator2);
		lengthBack = lengthFront + tuesdayIndicator2.size();
		weekDay = tuesday;
		weekNo = weekNumber(input, tuesdayIndicator2);
		return true;
	}else if(isFoundBack(input, tuesdayIndicator2) && isIndependentBack(input, tuesdayIndicator2)&&
		(weekNumber(input, tuesdayIndicator2) == thisIndicator || weekNumber(input, tuesdayIndicator2) == nextIndicator||
		weekNumber(input, tuesdayIndicator2) == dateIndicator || weekNumber(input, tuesdayIndicator2) == endDateIndicator||
		weekNumber(input, tuesdayIndicator2) == endTime)){
		lengthFront = input.rfind(tuesdayIndicator2);
		lengthBack = lengthFront + tuesdayIndicator2.size();
		weekDay = tuesday;
		weekNo = weekNumber(input, tuesdayIndicator2);
		return true;
	}else if(isFound(input, wednesdayIndicator1) && isIndependent(input, wednesdayIndicator1)&&
		(weekNumber(input, wednesdayIndicator1) == thisIndicator || weekNumber(input, wednesdayIndicator1) == nextIndicator||
		weekNumber(input, wednesdayIndicator1) == dateIndicator || weekNumber(input, wednesdayIndicator1) == endDateIndicator||
		weekNumber(input, wednesdayIndicator1) == endTime)){
		lengthFront = input.find(wednesdayIndicator1);
		lengthBack = lengthFront + wednesdayIndicator1.size();
		weekDay = wednesday;
		weekNo = weekNumber(input, wednesdayIndicator1);
		return true;
	}else if(isFoundBack(input, wednesdayIndicator1) && isIndependentBack(input, wednesdayIndicator1)&&
		(weekNumber(input, wednesdayIndicator1) == thisIndicator || weekNumber(input, wednesdayIndicator1) == nextIndicator||
		weekNumber(input, wednesdayIndicator1) == dateIndicator || weekNumber(input, wednesdayIndicator1) == endDateIndicator||
		weekNumber(input, wednesdayIndicator1) == endTime)){
		lengthFront = input.rfind(wednesdayIndicator1);
		lengthBack = lengthFront+wednesdayIndicator1.size();
		weekDay = wednesday;
		weekNo = weekNumber(input, wednesdayIndicator1);
		return true;
	}else if(isFound(input, wednesdayIndicator2) && isIndependent(input, wednesdayIndicator2)&&
		(weekNumber(input, wednesdayIndicator2) == thisIndicator || weekNumber(input, wednesdayIndicator2) == nextIndicator||
		weekNumber(input, wednesdayIndicator2) == dateIndicator || weekNumber(input, wednesdayIndicator2) == endDateIndicator||
		weekNumber(input, wednesdayIndicator2) == endTime)){
		lengthFront = input.find(wednesdayIndicator2);
		lengthBack = lengthFront+wednesdayIndicator2.size();
		weekDay = wednesday;
		weekNo = weekNumber(input,wednesdayIndicator2);
		return true;
	}else if(isFoundBack(input, wednesdayIndicator2) && isIndependentBack(input, wednesdayIndicator2)&&
		(weekNumber(input, wednesdayIndicator2) == thisIndicator || weekNumber(input, wednesdayIndicator2) == nextIndicator)){
		lengthFront = input.rfind(wednesdayIndicator2);
		lengthBack = lengthFront + wednesdayIndicator2.size();
		weekDay = wednesday;
		weekNo = weekNumber(input, wednesdayIndicator2);
		return true;
	}else if(isFound(input, thursdayIndicator1) && isIndependent(input, thursdayIndicator1)&&
		(weekNumber(input, thursdayIndicator1) == thisIndicator || weekNumber(input, thursdayIndicator1) == nextIndicator||
		weekNumber(input, thursdayIndicator1) == dateIndicator || weekNumber(input, thursdayIndicator1) == endDateIndicator||
		weekNumber(input, thursdayIndicator1) == endTime)){
		lengthFront = input.find(thursdayIndicator1);
		lengthBack = lengthFront + thursdayIndicator1.size();
		weekDay = thursday;
		weekNo = weekNumber(input, thursdayIndicator1);
		return true;
	}else if(isFoundBack(input, thursdayIndicator1) && isIndependentBack(input, thursdayIndicator1)&&
		(weekNumber(input, thursdayIndicator1)==thisIndicator || weekNumber(input, thursdayIndicator1) == nextIndicator||
		weekNumber(input, thursdayIndicator1) == dateIndicator || weekNumber(input, thursdayIndicator1) == endDateIndicator||
		weekNumber(input, thursdayIndicator1) == endTime)){
		lengthFront = input.rfind(thursdayIndicator1);
		lengthBack = lengthFront+thursdayIndicator1.size();
		weekDay = thursday;
		weekNo = weekNumber(input, thursdayIndicator1);
		return true;
	}else if(isFound(input, thursdayIndicator2) && isIndependent(input, thursdayIndicator2)&&
		(weekNumber(input, thursdayIndicator2 )== thisIndicator || weekNumber(input, thursdayIndicator2) == nextIndicator||
		weekNumber(input, thursdayIndicator2) == dateIndicator || weekNumber(input, thursdayIndicator2) == endDateIndicator||
		weekNumber(input, thursdayIndicator2) == endTime)){
		lengthFront = input.find(thursdayIndicator2);
		lengthBack = lengthFront + thursdayIndicator2.size();
		weekDay = thursday;
		weekNo = weekNumber(input, thursdayIndicator2);
		return true;
	}else if(isFoundBack(input, thursdayIndicator2) && isIndependentBack(input, thursdayIndicator2)&&
		(weekNumber(input, thursdayIndicator2) == thisIndicator || weekNumber(input, thursdayIndicator2) == nextIndicator||
		weekNumber(input, thursdayIndicator2) == dateIndicator|| weekNumber(input, thursdayIndicator2) == endDateIndicator||
		weekNumber(input, thursdayIndicator2) == endTime)){
		lengthFront = input.rfind(thursdayIndicator2);
		lengthBack = lengthFront + thursdayIndicator2.size();
		weekDay = thursday;
		weekNo = weekNumber(input, thursdayIndicator2);
		return true;
	}else if(isFound(input, thursdayIndicator3) && isIndependent(input, thursdayIndicator3)&&
		(weekNumber(input, thursdayIndicator3) == thisIndicator || weekNumber(input, thursdayIndicator3) == nextIndicator||
		weekNumber(input, thursdayIndicator3) == dateIndicator||weekNumber(input, thursdayIndicator3) == endDateIndicator||
		weekNumber(input, thursdayIndicator3) == endTime)){
		lengthFront = input.find(thursdayIndicator3);
		lengthBack = lengthFront + thursdayIndicator3.size();
		weekDay = thursday;
		weekNo = weekNumber(input, thursdayIndicator3);
		return true;
	}else if(isFoundBack(input, thursdayIndicator3)&&isIndependentBack(input, thursdayIndicator3)&&
		(weekNumber(input, thursdayIndicator3) == thisIndicator || weekNumber(input, thursdayIndicator3) == nextIndicator||
		weekNumber(input, thursdayIndicator3) == dateIndicator || weekNumber(input, thursdayIndicator3) == endDateIndicator||
		weekNumber(input, thursdayIndicator3) == endTime)){
		lengthFront = input.rfind(thursdayIndicator3);
		lengthBack = lengthFront + thursdayIndicator3.size();
		weekDay = thursday;
		weekNo = weekNumber(input, thursdayIndicator3);
		return true;
	}else if(isFound(input, fridayIndicator1) && isIndependent(input, fridayIndicator1)&&
		(weekNumber(input, fridayIndicator1) == thisIndicator || weekNumber(input, fridayIndicator1) == nextIndicator||
		weekNumber(input, fridayIndicator1) == dateIndicator || weekNumber(input, fridayIndicator1) == endDateIndicator||
		weekNumber(input, fridayIndicator1) == endTime)){
		lengthFront = input.find(fridayIndicator1);
		lengthBack = lengthFront + fridayIndicator1.size();
		weekDay = friday;
		weekNo = weekNumber(input, fridayIndicator1);
		return true;
	}else if(isFoundBack(input, fridayIndicator1) && isIndependentBack(input, fridayIndicator1)&&
		(weekNumber(input, fridayIndicator1) == thisIndicator || weekNumber(input, fridayIndicator1) == nextIndicator||
		weekNumber(input, fridayIndicator1) == dateIndicator || weekNumber(input, fridayIndicator1) == endDateIndicator||
		weekNumber(input, fridayIndicator1) == endTime)){
		lengthFront = input.rfind(fridayIndicator1);
		lengthBack = lengthFront + fridayIndicator1.size();
		weekDay = friday;
		weekNo = weekNumber(input, fridayIndicator1);
		return true;
	}else if(isFound(input, fridayIndicator2) && isIndependent(input, fridayIndicator2)&&
		(weekNumber(input, fridayIndicator2) == thisIndicator || weekNumber(input, fridayIndicator2) == nextIndicator||
		weekNumber(input, fridayIndicator2) == dateIndicator || weekNumber(input, fridayIndicator2) == endDateIndicator||
		weekNumber(input, fridayIndicator2) == endTime)){
		lengthFront = input.find(fridayIndicator2);
		lengthBack = lengthFront + fridayIndicator2.size();
		weekDay = friday;
		weekNo = weekNumber(input, fridayIndicator2);
		return true;
	}else if(isFoundBack(input, fridayIndicator2) && isIndependentBack(input, fridayIndicator2)&&
		(weekNumber(input, fridayIndicator2) == thisIndicator || weekNumber(input, fridayIndicator2) == nextIndicator||
		weekNumber(input, fridayIndicator2) == dateIndicator || weekNumber(input, fridayIndicator2) == endDateIndicator||
		weekNumber(input, fridayIndicator2) == endTime)){
		lengthFront = input.rfind(fridayIndicator2);
		lengthBack = lengthFront + fridayIndicator2.size();
		weekDay = friday;
		weekNo = weekNumber(input, fridayIndicator2);
		return true;
	}else if(isFound(input, saturdayIndicator1) && isIndependent(input, saturdayIndicator1)&&
		(weekNumber(input, saturdayIndicator1) == thisIndicator||weekNumber(input, saturdayIndicator1) == nextIndicator||
		weekNumber(input, saturdayIndicator1) == dateIndicator||weekNumber(input, saturdayIndicator1) == endDateIndicator||
		weekNumber(input, saturdayIndicator1) == endTime)){
		lengthFront = input.find(saturdayIndicator1);
		lengthBack = lengthFront + saturdayIndicator1.size();
		weekDay = saturday;
		weekNo = weekNumber(input,saturdayIndicator1);
		return true;
	}else if(isFoundBack(input, saturdayIndicator1) && isIndependentBack(input, saturdayIndicator1)&&
		(weekNumber(input, saturdayIndicator1) == thisIndicator||weekNumber(input, saturdayIndicator1) == nextIndicator||
		weekNumber(input, saturdayIndicator1) == dateIndicator||weekNumber(input, saturdayIndicator1) == endDateIndicator||
		weekNumber(input, saturdayIndicator1) == endTime)){
		lengthFront = input.rfind(saturdayIndicator1);
		lengthBack = lengthFront + saturdayIndicator1.size();
		weekDay = saturday;
		weekNo = weekNumber(input, saturdayIndicator1);
		return true;
	}else if(isFound(input, saturdayIndicator2) && isIndependent(input, saturdayIndicator2)&&
		(weekNumber(input, saturdayIndicator2) == thisIndicator || weekNumber(input, saturdayIndicator2) == nextIndicator||
		weekNumber(input, saturdayIndicator2) == dateIndicator || weekNumber(input, saturdayIndicator2) == endDateIndicator||
		weekNumber(input, saturdayIndicator2) == endTime)){
		lengthFront = input.find(saturdayIndicator2);
		lengthBack = lengthFront + saturdayIndicator2.size();
		weekDay = saturday;
		weekNo = weekNumber(input, saturdayIndicator2);
		return true;
	}else if(isFoundBack(input, saturdayIndicator2) && isIndependentBack(input, saturdayIndicator2)&&
		(weekNumber(input, saturdayIndicator2) == thisIndicator || weekNumber(input, saturdayIndicator2) == nextIndicator||
		weekNumber(input, saturdayIndicator2) == dateIndicator || weekNumber(input, saturdayIndicator2) == endDateIndicator||
		weekNumber(input, saturdayIndicator2) == endTime)){
		lengthFront = input.rfind(saturdayIndicator2);
		lengthBack = lengthFront + saturdayIndicator2.size();
		weekDay = saturday;
		weekNo = weekNumber(input, saturdayIndicator2);
		return true;
	}else if(isFound(input, sundayIndicator1) && isIndependent(input, sundayIndicator1)&&
		(weekNumber(input, sundayIndicator1) == thisIndicator||weekNumber(input, sundayIndicator1) == nextIndicator||
		weekNumber(input, sundayIndicator1) == dateIndicator||weekNumber(input, sundayIndicator1) == endDateIndicator||
		weekNumber(input, sundayIndicator1) == endTime)){
		lengthFront = input.find(sundayIndicator1);
		lengthBack = lengthFront + sundayIndicator1.size();
		weekDay = sunday;
		weekNo = weekNumber(input, sundayIndicator1);
		return true;
	}else if(isFoundBack(input, sundayIndicator1) && isIndependentBack(input, sundayIndicator1)&&
		(weekNumber(input, sundayIndicator1) == thisIndicator || weekNumber(input, sundayIndicator1) == nextIndicator||
		weekNumber(input, sundayIndicator1) == dateIndicator || weekNumber(input, sundayIndicator1) == endDateIndicator||
		weekNumber(input, sundayIndicator1) == endTime)){
		lengthFront = input.rfind(sundayIndicator1);
		lengthBack = lengthFront+sundayIndicator1.size();
		weekDay = sunday;
		weekNo = weekNumber(input, sundayIndicator1);
		return true;
	}else if(isFound(input, sundayIndicator2) && isIndependent(input, sundayIndicator2)&&
		(weekNumber(input, sundayIndicator2) == thisIndicator || weekNumber(input, sundayIndicator2) == nextIndicator||
		weekNumber(input, sundayIndicator2) == dateIndicator || weekNumber(input, sundayIndicator2) == endDateIndicator||
		weekNumber(input, sundayIndicator2) == endTime)){
		lengthFront = input.find(sundayIndicator2);
		lengthBack = lengthFront + sundayIndicator2.size();
		weekDay = sunday;
		weekNo = weekNumber(input, sundayIndicator2);
		return true;
	}else if(isFoundBack(input, sundayIndicator2) && isIndependentBack(input, sundayIndicator2)&&
		(weekNumber(input, sundayIndicator2)==thisIndicator || weekNumber(input, sundayIndicator2) == nextIndicator||
		weekNumber(input, sundayIndicator2) == dateIndicator || weekNumber(input, sundayIndicator2)==endDateIndicator||
		weekNumber(input, sundayIndicator2) == endTime)){
		lengthFront = input.rfind(sundayIndicator2);
		lengthBack = lengthFront + sundayIndicator2.size();
		weekDay = sunday;
		weekNo = weekNumber(input, sundayIndicator2);
		return true;
	}
	else {
		return false;
	}
}

//check if the user type the special day (today or tomorrow) to represent the date
bool CommandParser::hasSpecialDay(string input){
	if(isFound(input,todayIndicator1)&&isIndependent(input,todayIndicator1)){
		lengthFront=input.find(todayIndicator1);
		lengthBack=lengthFront+todayIndicator1.size();
		specialDay = todayIndicator1;
		return true;
	}else if(isFoundBack(input,todayIndicator1)&&isIndependentBack(input,todayIndicator1)){
		lengthFront=input.rfind(todayIndicator1);
		lengthBack=lengthFront+todayIndicator1.size();
		specialDay = todayIndicator1;
		return true;
	}else if(isFound(input,todayIndicator2)&&isIndependent(input,todayIndicator2)){
		lengthFront=input.find(todayIndicator2);
		lengthBack=lengthFront+todayIndicator2.size();
		specialDay = todayIndicator2;
		return true;
	}else if(isFoundBack(input,todayIndicator2)&&isIndependentBack(input,todayIndicator2)){
		lengthFront=input.rfind(todayIndicator2);
		lengthBack=lengthFront+todayIndicator2.size();
		specialDay = todayIndicator2;
		return true;
	}else if(isFound(input,tomorrowIndicator1)&&isIndependent(input,tomorrowIndicator1)){
		lengthFront=input.find(tomorrowIndicator1);
		lengthBack=lengthFront+tomorrowIndicator1.size();
		specialDay = tomorrowIndicator1;
		return true;
	}else if(isFoundBack(input,tomorrowIndicator1)&&isIndependentBack(input,tomorrowIndicator1)){
		lengthFront=input.rfind(tomorrowIndicator1);
		lengthBack=lengthFront+tomorrowIndicator1.size();
		specialDay = tomorrowIndicator1;
		return true;
	}else if(isFound(input,tomorrowIndicator2)&&isIndependent(input,tomorrowIndicator2)){
		lengthFront=input.find(tomorrowIndicator2);
		lengthBack=lengthFront+tomorrowIndicator2.size();
		specialDay = tomorrowIndicator2;
		return true;
	}else if(isFoundBack(input,tomorrowIndicator2)&&isIndependentBack(input,tomorrowIndicator2)){
		lengthFront=input.rfind(tomorrowIndicator2);
		lengthBack=lengthFront+tomorrowIndicator2.size();
		specialDay = tomorrowIndicator2;
		return true;
	}else if(isFound(input,tomorrowIndicator3)&&isIndependent(input,tomorrowIndicator3)){
		lengthFront=input.find(tomorrowIndicator3);
		lengthBack=lengthFront+tomorrowIndicator3.size();
		specialDay = tomorrowIndicator3;
		return true;
	}else if(isFoundBack(input,tomorrowIndicator3)&&isIndependentBack(input,tomorrowIndicator3)){
		lengthFront=input.rfind(tomorrowIndicator3);
		lengthBack=lengthFront+tomorrowIndicator3.size();
		specialDay = tomorrowIndicator3;
		return true;
	}else{
		return false;
	}
}




string CommandParser::getDateFromWeek(){
	getCurrentDate();
	if(weekNo == thisIndicator||weekNo == dateIndicator||weekNo == endDateIndicator||weekNo == endTime){
		weekDay += startingPosition;
		taskDay = currentDay + weekDay- currentWeekDay;
	}else if(weekNo == nextIndicator){
		weekDay += lengthofAWeek; 
		taskDay = currentDay + weekDay- currentWeekDay;
			}else if(specialDay == todayIndicator1 || specialDay == todayIndicator2){ 
		taskDay = currentDay;
	}else if(specialDay == tomorrowIndicator1||specialDay == tomorrowIndicator2 || specialDay == tomorrowIndicator3){
			taskDay = currentDay + positionModerator1;
	}
	taskMonth = currentMonth;
	taskYear = localYear;
	if((currentMonth == monthIndicator1 || currentMonth==monthIndicator3 || currentMonth==monthIndicator5 ||
		currentMonth == monthIndicator7 || currentMonth==monthIndicator8 || currentMonth == monthIndicator10 ||
		currentMonth == monthIndicator12) && taskDay>monthModerator2){
			taskDay = taskDay - monthModerator2;
			taskMonth += positionModerator1;
	}else if((currentMonth == monthIndicator4 || currentMonth == monthIndicator6 || currentMonth == monthIndicator9 ||
		currentMonth == monthIndicator11) && taskDay > monthModerator1){
			taskDay = taskDay - monthModerator1;
			taskMonth += positionModerator1;
	}else if(currentMonth == monthIndicator2 && localYear%4 == 0 && taskDay>monthModerator3){
		taskDay = taskDay - monthModerator3;
		taskMonth += positionModerator1;
	}else if(currentMonth == monthIndicator2 && localYear%4!=0 && taskDay > monthModerator4){
		taskDay = taskDay - monthModerator4;
		taskMonth += positionModerator1;
	}if(taskMonth > monthIndicator12){
		taskMonth = taskMonth - monthIndicator12;
		taskYear += positionModerator1;
	}
	stringstream ss;
	ss << taskDay << dayIndicator << taskMonth << dayIndicator << taskYear;
	ss >> taskDate;
	return taskDate;
}




