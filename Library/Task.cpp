//@author A0121007A
#include "Task.h"
#include "Utility.h"

/* attributes */
const string Task::STARTYEAR_STR = "Start Year";
const string Task::STARTMONTH_STR = "Start Month";
const string Task::STARTDAY_STR = "Start Day";
const string Task::STARTHOUR_STR = "Start Hour";
const string Task::STARTMINUTE_STR = "Start Minute";
const string Task::ENDYEAR_STR = "End Year";
const string Task::ENDMONTH_STR = "End Month";
const string Task::ENDDAY_STR = "End Day";
const string Task::ENDHOUR_STR = "End Hour";
const string Task::ENDMINUTE_STR = "End Minute";
const string Task::PRIORITY_STR = "Priority";
const string Task::NAME_STR = "Name";
const string Task::DESCRIPTION_STR = "Description";
const string Task::LOCATION_STR = "Location";
const string Task::ISDONE_STR = "Task completed";
const string Task::ISDONE_ALERT = "DONE";
const string Task::ISDELETED_STR = "Task deleted";
const string Task::ISDELETED_ALERT = "DELETED";
const string Task::ISIMPT_STR = "Task marked as important";
const string Task::ISIMPT_ALERT = "MARKED";
const string Task::HASEXPIRED_STR = "Task expired";
const string Task::ATTR_SEPARATOR = ": ";
const string Task::VALUE_TRUE_FOR_DISPLAY = "Yes";
const string Task::VALUE_FALSE_FOR_DISPLAY = "No";

const bool Task::TRUE = true;
const bool Task::FALSE = false;

//@author A0121007A
/* config */
const int Task::INT_NOT_EXIST = -1;
const bool Task::BOOL_NOT_EXIST = false;
const string Task::DISPLAY_DATE_ATTR_NOT_SPECIFIED = "-";
const string Task::DISPLAY_DATE_NOT_SPECIFIED = "-/-/-";
const string Task::DISPLAY_HOUR_NOT_SPECIFIED = "(not specified)";
const string Task::DISPLAY_KEY_DATE = " on ";
const string Task::DISPLAY_KEY_DATE_RANGE = " from ";
const string Task::DISPLAY_KEY_LOC = " in ";
const string Task::DISPLAY_KEY_TIME = " at ";
const string Task::DISPLAY_KEY_TIME_RANGE = " from ";
const string Task::DISPLAY_MINUTES_NOT_SPECIFIED = "00";
const string Task::DISPLAY_NAME_NOT_SPECIFIED = "(not specified)";
const string Task::DISPLAY_SPACE = " ";
const string Task::DISPLAY_TIME_NOT_SPECIFIED = "(not specified)";
const string Task::STRING_NOT_EXIST = ",,,"; //random to make sure no one types that
const string Task::DATE_RANGE_SEPARATOR = " until ";
const string Task::TIME_RANGE_SEPARATOR = " to ";
const string Task::DATE_SEPARATOR_ENGLISH = "/";
const string Task::TIME_SEPARATOR_ENGLISH = ":";
const string Task::ZERO_MINUTES = "00";

//@author A0121007A
/* error messages */
const string Task::ERROR_DAY = "Invalid day: please enter a days' name or a date's number between 0 and 31";
const string Task::ERROR_DAY_31 = "Invalid day: this month has 30 days, not 31";
const string Task::ERROR_DAY_FEB = "Invalid day: this month has 28 days only or is not on a leap year";
const string Task::ERROR_MONTH = "Invalid month: please enter a month's name or a number between 0 and 12";
const string Task::ERROR_HOUR = "Invalid hour: please enter a number between 0 and 23";
const string Task::ERROR_MINUTE = "Invalid minute: please enter a number between 0 and 59";
const string Task::ERROR_ENDDATE = "Invalid ending date: ending date should come after or be the same as the starting date";

const string Task::ERROR_STARTHOUR = "Invalid input: start hour";
const string Task::ERROR_STARTMINUTE = "Invalid input: start minute";
const string Task::ERROR_STARTDAY = "Invalid input: start day";
const string Task::ERROR_STARTDAY_31 = "Invalid start day: this month has less days than the one entered";
const string Task::ERROR_STARTMONTH = "Invalid input: start month";
const string Task::ERROR_STARTYEAR = "Invalid start year: please enter a number";
const string Task::ERROR_ENDHOUR = "Invalid input: end hour";
const string Task::ERROR_ENDHOUR_BEFORE_START = "End hour has to be the same or after the starting time";
const string Task::ERROR_ENDMINUTE = "Invalid input: end minute";
const string Task::ERROR_ENDMINUTE_BEFORE_START = "End minute has to be the same or after the starting time";
const string Task::ERROR_ENDDAY = "Invalid input: end day";
const string Task::ERROR_ENDDAY_31 = "Invalid end day: this month has less days than the one entered";
const string Task::ERROR_ENDDAY_BEFORE_START = "End day has to be the same or after the starting day";
const string Task::ERROR_ENDMONTH = "Invalid input: end month";
const string Task::ERROR_ENDMONTH_BEFORE_START = "End month has to be the same or after the starting month";
const string Task::ERROR_ENDYEAR = "Invalid end year";
const string Task::ERROR_ENDYEAR_BEFORE_START = "End year has to be the same or after the starting year";
const string Task::ERROR_PRIORITY = "Invalid priority: please enter a number";

//@author A0121007A
/* constructors */
Task::Task() {
	startYear = Task::INT_NOT_EXIST;
	startMonth = Task::INT_NOT_EXIST;
	startDay = Task::INT_NOT_EXIST;
	startHour = Task::INT_NOT_EXIST;
	startMinute = Task::INT_NOT_EXIST;
	endYear = Task::INT_NOT_EXIST;
	endMonth = Task::INT_NOT_EXIST;
	endDay = Task::INT_NOT_EXIST;
	endHour = Task::INT_NOT_EXIST;
	endMinute = Task::INT_NOT_EXIST;
	priority = Task::INT_NOT_EXIST;
	name = Task::STRING_NOT_EXIST;
	location = Task::STRING_NOT_EXIST;
	isDone = Task::BOOL_NOT_EXIST;
	isDeleted = Task::BOOL_NOT_EXIST;
	isImpt = Task::BOOL_NOT_EXIST;
	hasDate = Task::BOOL_NOT_EXIST;
	hasExpired = Task::BOOL_NOT_EXIST;
}
Task::Task(vector<string> attributes) {
	name = attributes[ATTR::NAME];
	location = attributes[ATTR::LOCATION];
	setStartHour(attributes.at(ATTR::STARTHOUR));
	setStartMinute(attributes.at(ATTR::STARTMINUTE));
	setStartDay(attributes.at(ATTR::STARTDAY));
	setStartMonth(attributes.at(ATTR::STARTMONTH));
	setStartYear(attributes.at(ATTR::STARTYEAR));
	setEndHour(attributes.at(ATTR::ENDHOUR));
	setEndMinute(attributes.at(ATTR::ENDMINUTE));
	setEndDay(attributes.at(ATTR::ENDDAY));
	setEndMonth(attributes.at(ATTR::ENDMONTH));
	setEndYear(attributes.at(ATTR::ENDYEAR));
	description = attributes[ATTR::DESCRIPTION];
	setPriority(attributes.at(ATTR::PRIORITY));
	isDone = Utility::stringToBool(attributes[ATTR::ISDONE]);
	isDeleted = Utility::stringToBool(attributes[ATTR::ISDELETED]);
	isImpt = Utility::stringToBool(attributes[ATTR::ISDELETED]);
	hasDate = Utility::stringToBool(attributes[ATTR::HASDATE]);
	hasExpired = Utility::stringToBool(attributes[ATTR::HASEXPIRED]);
}
                                                                                

//@author A0121007A
/* getters */
string Task::getStartYear() {
	if (Utility::isEmpty(startYear)) {
		return Task::STRING_NOT_EXIST;
	}
	return to_string(startYear);
}
string Task::getStartMonth() {
	if (Utility::isEmpty(startMonth)) {
		return Task::STRING_NOT_EXIST;
	}
	return to_string(startMonth);
}
string Task::getStartDay() {
	if (Utility::isEmpty(startDay)) {
		return Task::STRING_NOT_EXIST;
	}
	return to_string(startDay);
}
string Task::getStartHour() {
	if (Utility::isEmpty(startHour)) {
		return Task::STRING_NOT_EXIST;
	}
	return to_string(startHour);
}
string Task::getStartMinute() {
	if (Utility::isEmpty(startMinute)) {
		return Task::STRING_NOT_EXIST;
	}
	if (Utility::isZero(startMinute)) {
		return Task::ZERO_MINUTES;
	}
	if (Utility::isLessThanTen(startMinute)) {
		string s = "0";
		s.append(to_string(startMinute));
		return s;
	}
	return to_string(startMinute);
}
string Task::getEndYear() {
	if (Utility::isEmpty(endYear)) {
		return Task::STRING_NOT_EXIST;
	}
	return to_string(endYear);
}
string Task::getEndMonth() {
	if (Utility::isEmpty(endMonth)) {
		return Task::STRING_NOT_EXIST;
	}
	return to_string(endMonth);
}
string Task::getEndDay() {
	if (Utility::isEmpty(endDay)) {
		return Task::STRING_NOT_EXIST;
	}
	return to_string(endDay);
}
string Task::getEndHour() {
	if (Utility::isEmpty(endHour)) {
		return Task::STRING_NOT_EXIST;
	}
	return to_string(endHour);
}
string Task::getEndMinute() {
	if (Utility::isEmpty(endMinute)) {
		return Task::STRING_NOT_EXIST;
	}
	if (Utility::isZero(endMinute)) {
		return Task::ZERO_MINUTES;
	}
	if (Utility::isLessThanTen(endMinute)) {
		string s = "0";
		s.append(to_string(endMinute));
		return s;
	}
	return to_string(endMinute);
}
string Task::getPriority() {
	if (Utility::isEmpty(priority)) {
		return Task::STRING_NOT_EXIST;
	}
	return to_string(priority);
}
string Task::getName() {
	return name;
}
string Task::getDescription() {
	return description;
}
string Task::getLocation() {
	return location;
}
string Task::getIsDone() {
	return Utility::boolToString(isDone);
}
string Task::getIsDoneForDisplay() {
	if (isDone) {
		return Task::VALUE_TRUE_FOR_DISPLAY;
	}
	return Task::VALUE_FALSE_FOR_DISPLAY;
}
string Task::getIsDeleted() {
	return Utility::boolToString(isDeleted);
}
string Task::getIsImpt() {
	return Utility::boolToString(isImpt);
}
string Task::getHasDate() {
	return Utility::boolToString(hasDate);
}
string Task::getHasExpired() {
	return Utility::boolToString(hasExpired);
}
string Task::getHasExpiredForDisplay() {
	if (hasExpired) {
		return Task::VALUE_TRUE_FOR_DISPLAY;
	}
	return Task::VALUE_FALSE_FOR_DISPLAY;
}

//@author A0121007A
vector<string> Task::getAttributes() {
	vector<string> attributes(ATTR::SIZE);

	attributes[ATTR::NAME] = getName();
	attributes[ATTR::LOCATION] = getLocation();
	attributes[ATTR::STARTHOUR] = getStartHour();
	attributes[ATTR::STARTMINUTE] = getStartMinute();
	attributes[ATTR::STARTDAY] = getStartDay();
	attributes[ATTR::STARTMONTH] = getStartMonth();
	attributes[ATTR::STARTYEAR] = getStartYear();
	attributes[ATTR::ENDHOUR] = getEndHour();
	attributes[ATTR::ENDMINUTE] = getEndMinute();
	attributes[ATTR::ENDDAY] = getEndDay();
	attributes[ATTR::ENDMONTH] = getEndMonth();
	attributes[ATTR::ENDYEAR] = getEndYear();
	attributes[ATTR::DESCRIPTION] = getDescription();
	attributes[ATTR::PRIORITY] = getPriority();
	attributes[ATTR::ISDONE] = getIsDone();
	attributes[ATTR::ISDELETED] = Utility::boolToString(isDeleted);
	attributes[ATTR::HASDATE] = getHasDate();
	attributes[ATTR::HASEXPIRED] = getHasExpired();

	return attributes;
}

//@author A0121007A
/* returns a vector filled with attributes of the task to be displayed, such as:
   Start Hour: 15
*/
vector<string> Task::getAttributesForDisplay() {
	vector<string> attributes(ATTR::SIZE);

	if (Utility::areEqual(getName(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::NAME] = Task::NAME_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::NAME] = Task::NAME_STR + Task::ATTR_SEPARATOR + getName();
	}
	if (Utility::areEqual(getLocation(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::LOCATION] = Task::LOCATION_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::LOCATION] = Task::LOCATION_STR + Task::ATTR_SEPARATOR + getLocation();
	}
	if (Utility::areEqual(getStartHour(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::STARTHOUR] = Task::STARTHOUR_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::STARTHOUR] = Task::STARTHOUR_STR + Task::ATTR_SEPARATOR + getStartHour();
	}
	if (Utility::areEqual(getStartMinute(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::STARTMINUTE] = Task::STARTMINUTE_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::STARTMINUTE] = Task::STARTMINUTE_STR + Task::ATTR_SEPARATOR + getStartMinute();
	}
	if (Utility::areEqual(getStartDay(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::STARTDAY] = Task::STARTDAY_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::STARTDAY] = Task::STARTDAY_STR + Task::ATTR_SEPARATOR + getStartDay();
	}
	if (Utility::areEqual(getStartMonth(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::STARTMONTH] = Task::STARTMONTH_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::STARTMONTH] = Task::STARTMONTH_STR + Task::ATTR_SEPARATOR + getStartMonth();
	}
	if (Utility::areEqual(getStartYear(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::STARTYEAR] = Task::STARTYEAR_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::STARTYEAR] = Task::STARTYEAR_STR + Task::ATTR_SEPARATOR + getStartYear();
	}
	if (Utility::areEqual(getEndHour(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::ENDHOUR] = Task::ENDHOUR_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::ENDHOUR] = Task::ENDHOUR_STR + Task::ATTR_SEPARATOR + getEndHour();
	}
	if (Utility::areEqual(getEndMinute(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::ENDMINUTE] = Task::ENDMINUTE_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::ENDMINUTE] = Task::ENDMINUTE_STR + Task::ATTR_SEPARATOR + getEndMinute();
	}
	if (Utility::areEqual(getEndDay(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::ENDDAY] = Task::ENDDAY_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::ENDDAY] = Task::ENDDAY_STR + Task::ATTR_SEPARATOR + getEndDay();
	}
	if (Utility::areEqual(getEndMonth(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::ENDMONTH] = Task::ENDMONTH_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::ENDMONTH] = Task::ENDMONTH_STR + Task::ATTR_SEPARATOR + getEndMonth();
	}
	if (Utility::areEqual(getEndYear(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::ENDYEAR] = Task::ENDYEAR_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::ENDYEAR] = Task::ENDYEAR_STR + Task::ATTR_SEPARATOR + getEndYear();
	}
	if (Utility::areEqual(getDescription(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::DESCRIPTION] = Task::DESCRIPTION_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::DESCRIPTION] = Task::DESCRIPTION_STR + Task::ATTR_SEPARATOR + getDescription();
	}
	if (Utility::areEqual(getPriority(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::PRIORITY] = Task::PRIORITY_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::PRIORITY] = Task::PRIORITY_STR + Task::ATTR_SEPARATOR + getPriority();
	}
	if (Utility::areEqual(getIsDone(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::ISDONE] = Task::ISDONE_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::ISDONE] = Task::ISDONE_STR + Task::ATTR_SEPARATOR + getIsDoneForDisplay();
	}
	if (Utility::areEqual(getIsDeleted(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::ISDELETED] = Task::STRING_NOT_EXIST;
	} else {
		attributes[ATTR::ISDELETED] = Task::STRING_NOT_EXIST;
	}
	if (Utility::areEqual(getHasDate(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::HASDATE] = Task::STRING_NOT_EXIST;
	} else {
		attributes[ATTR::HASDATE] = Task::STRING_NOT_EXIST;
	}
	if (Utility::areEqual(getHasExpired(), Task::STRING_NOT_EXIST)) {
		attributes[ATTR::HASEXPIRED] = Task::HASEXPIRED_STR + Task::ATTR_SEPARATOR;
	} else {
		attributes[ATTR::HASEXPIRED] = Task::HASEXPIRED_STR + Task::ATTR_SEPARATOR + getHasExpiredForDisplay();
	}

	return attributes;
}

//@author A0121007A
/* setters */
void Task::setStartYear(string sy) {
	if (Utility::isEmpty(sy)) {
		startYear = Task::INT_NOT_EXIST;
	}
	else {
		startYear = stoi(sy);
	}
}
void Task::setStartMonth(string sm){
	if (Utility::isEmpty(sm)) {
		startMonth = Task::INT_NOT_EXIST;
	}
	else {
		startMonth = stoi(sm);
	}
}
void Task::setStartDay(string sd) {
	if (Utility::isEmpty(sd)) {
		startDay = Task::INT_NOT_EXIST;
	}
	else {
		startDay = stoi(sd);
	}
}
void Task::setStartHour(string sh) {
	if (Utility::isEmpty(sh)) {
		startHour = Task::INT_NOT_EXIST;
	}
	else {
		startHour = stoi(sh);
	}
}
void Task::setStartMinute(string sm) {
	if (Utility::isEmpty(sm)) {
		startMinute = Task::INT_NOT_EXIST;
	}
	else {
		startMinute = stoi(sm);
	}
}
void Task::setEndYear(string ey) {
	if (Utility::isEmpty(ey)) {
		endYear = Task::INT_NOT_EXIST;
	}
	else {
		endYear = stoi(ey);
	}
}
void Task::setEndMonth(string em) {
	if (Utility::isEmpty(em)) {
		endMonth = Task::INT_NOT_EXIST;
	}
	else {
		endMonth = stoi(em);
	}
}
void Task::setEndDay(string ed) {
	if (Utility::isEmpty(ed)) {
		endDay = Task::INT_NOT_EXIST;
	}
	else {
		endDay = stoi(ed);
	}
}
void Task::setEndHour(string eh) {
	if (Utility::isEmpty(eh)) {
		endHour = Task::INT_NOT_EXIST;
	}
	else {
		endHour = stoi(eh);
	}
}
void Task::setEndMinute(string em) {
	if (Utility::isEmpty(em)) {
		endMinute = Task::INT_NOT_EXIST;
	}
	else {
		endMinute = stoi(em);
	}
}
void Task::setDateAndTime(vector<string> dateAndTime) {
	setStartYear(dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTYEAR));
	setStartMonth(dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTMONTH));
	setStartDay(dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTDAY));
	setStartHour(dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTHOUR));
	setStartMinute(dateAndTime.at(DATE_ENUM::DATE_ENUM::STARTMINUTE));
	setEndYear(dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDYEAR));
	setEndMonth(dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDMONTH));
	setEndDay(dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDDAY));
	setEndHour(dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDHOUR));
	setEndMinute(dateAndTime.at(DATE_ENUM::DATE_ENUM::ENDMINUTE));
	setIsDone(dateAndTime.at(DATE_ENUM::DATE_ENUM::ISDONE));
	setHasDate(dateAndTime.at(DATE_ENUM::DATE_ENUM::HASDATE));
	setHasExpired(dateAndTime.at(DATE_ENUM::DATE_ENUM::HASEXPIRED));
}
void Task::setPriority(string p) {
	if (Utility::isEmpty(p)) {
		priority = Task::INT_NOT_EXIST;
	}
	else {
		priority = stoi(p);
		if (priority <= 0) {
			priority = Task::INT_NOT_EXIST;
		}
	}
}
void Task::setName(string n) {
	name = n;
}
void Task::setDescription(string d) {
	description = d;
}
void Task::setLocation(string l) {
	location = l;
}
void Task::setIsDone() {
	isDone = true;
}
//@author A0121007A
void Task::setIsDone(string done) {
	isDone = Utility::stringToBool(done);
}
//@author A0081254L
void Task::setIsDeleted() {
	isDeleted = true;
}
void Task::setIsDeleted(string del) {
	isDeleted = Utility::stringToBool(del);
}
void Task::setIsImpt() {
	isImpt = true;
}
void Task::setIsImpt(string impt) {
	isImpt = Utility::stringToBool(impt);
}
//@author A0121007A
void Task::setHasDate(string d) {
	hasDate = Utility::stringToBool(d);
}
//@author A0121007A
void Task::setHasExpired(string expired) {
	hasExpired = Utility::stringToBool(expired);
}
//@author A0121007A
void Task::setAttributes(vector<string> attributes) {
	setStartYear(attributes[ATTR::STARTYEAR]);
	setStartMonth(attributes[ATTR::STARTMONTH]);
	setStartDay(attributes[ATTR::STARTDAY]);
	setStartHour(attributes[ATTR::STARTHOUR]);
	setStartMinute(attributes[ATTR::STARTMINUTE]);
	setEndYear(attributes[ATTR::ENDYEAR]);
	setEndMonth(attributes[ATTR::ENDMONTH]);
	setEndDay(attributes[ATTR::ENDDAY]);
	setEndHour(attributes[ATTR::ENDHOUR]);
	setEndMinute(attributes[ATTR::ENDMINUTE]);
	setPriority(attributes[ATTR::PRIORITY]);
	setName(attributes[ATTR::NAME]);
	setDescription(attributes[ATTR::DESCRIPTION]);
	setLocation(attributes[ATTR::LOCATION]);
	setIsDone(attributes[ATTR::ISDONE]);
	setIsDeleted(attributes[ATTR::ISDELETED]);
	setHasDate(attributes[ATTR::HASDATE]);
	setHasExpired(attributes[ATTR::HASEXPIRED]);
}

//@author A0121007A
string Task::getTime() {
	string start;
	string end;
	string time;

	start = getStartTime();
	end = getEndTime();
	time = formatStartEndTime(start, end);

	return time;
}

//@author A0121007A
string Task::getStartTime() {
	string sH;
	string sM;
	string startTime;

	if (Utility::isEmpty(getStartHour()) && Utility::isEmpty(getStartMinute())) {
		sH = Task::STRING_NOT_EXIST;
		sM = Task::STRING_NOT_EXIST;
	}
	else if (Utility::isEmpty(getStartHour())) {
		sH = Task::DISPLAY_HOUR_NOT_SPECIFIED;
		sM = getStartMinute();
	}
	else if (Utility::isEmpty(getStartMinute())) {
		sH = getStartHour();
		sM = Task::DISPLAY_MINUTES_NOT_SPECIFIED;
	}
	else {
		sH = getStartHour();
		sM = getStartMinute();
	}

	startTime = formatTime(sH, sM);

	return startTime;
}

//@author A0121007A
string Task::getEndTime() {
	string eH;
	string eM;
	string endTime;

	if (Utility::isEmpty(getEndHour()) && Utility::isEmpty(getEndMinute())) {
		eH = Task::STRING_NOT_EXIST;
		eM = Task::STRING_NOT_EXIST;
	}
	else if (Utility::isEmpty(getEndHour())) {
		eH = Task::DISPLAY_HOUR_NOT_SPECIFIED;
		eM = getEndMinute();
	}
	else if (Utility::isEmpty(getEndMinute())) {
		eH = getEndHour();
		eM = Task::DISPLAY_MINUTES_NOT_SPECIFIED;
	}
	else {
		eH = getEndHour();
		eM = getEndMinute();
	}

	endTime = formatTime(eH, eM);

	return endTime;
}

//@author A0121007A
string Task::formatTime(string h, string m) {
	string t;

	if (Utility::isEmpty(h) && Utility::isEmpty(m)) {
		t = Task::DISPLAY_TIME_NOT_SPECIFIED;
		return t;
	}
	else {
		t = h + Task::TIME_SEPARATOR_ENGLISH + m;
	}

	return t;
}

//@author A0121007A
string Task::formatStartEndTime(string s, string e) {
	if (Task::isNonSpecifiedTime(e)) {
		return s;
	}
	string t;
	t = s + Task::TIME_RANGE_SEPARATOR + e;
	return t;
}

//@author A0121007A
/* this method is the one creating the final string that displays the tasks with the 'view' command */
string Task::getDisplay() {
	string date;
	string loc;
	string name;
	string priority;
	string done;
	string time;
	string toDisplay;

	name = getDisplayName();

	loc = getDisplayLocation();

	time = getDisplayTime();

	date = getDisplayDate();

	priority = getDisplayPriority();

	done = getDisplayDone();

	toDisplay = Task::concatenateDisplayAttributes(name, loc, time, date, priority, done);

	return toDisplay;
}

//@author A0121007A
string Task::concatenateDisplayAttributes(string name, string loc, string time, string date, string priority, string done) {
	string toDisplay;

	toDisplay = name;

	if (!Utility::isEmpty(loc)) {
		string l = Task::DISPLAY_KEY_LOC + loc;
		toDisplay.append(l);
	}

	if (!Utility::isEmpty(time)) {
		string t;
		if (Utility::isContained(Task::TIME_RANGE_SEPARATOR, time)) {
			t = Task::DISPLAY_KEY_TIME_RANGE + time;
			toDisplay.append(t);
		} else {
			t = Task::DISPLAY_KEY_TIME + time;
			toDisplay.append(t);
		}
	}

	if (!Utility::isEmpty(date)) {
		string d;
		if (Utility::isContained(Task::DATE_RANGE_SEPARATOR, date)) {
			d = Task::DISPLAY_KEY_DATE_RANGE + date;
			toDisplay.append(d);
		} else {
			d = Task::DISPLAY_KEY_DATE + date;
			toDisplay.append(d);
		}
	}

	if (!Utility::isEmpty(priority)) {
		toDisplay.append(priority);
	}

	if (!Utility::isEmpty(done)) {
		toDisplay.append(done);
	}

	return toDisplay;
}

//@author A0121007A
string Task::getDisplayDone() {
	string done;

	if (isDone) {
		done = " [" + Task::ISDONE_ALERT + "]";
	} else {
		done = Task::STRING_NOT_EXIST;
	}

	return done;
}

//@author A0121007A
string Task::getDisplayName() {
	string name;

	if (Utility::isEmpty(getName())) {
		name = Task::DISPLAY_NAME_NOT_SPECIFIED;
	}
	else {
		name = getName();
	}

	return name;
}

//@author A0121007A
string Task::getDisplayPriority() {
	string priority;

	if (Utility::isEmpty(getPriority())) {
		priority = Task::STRING_NOT_EXIST;
	} else {
		priority = " [" + getPriority() + "]";
	}
	return priority;
}

//@author A0121007A
string Task::getDisplayLocation() {
	string loc;

	if (Utility::isEmpty(getLocation())) {
		loc = Task::STRING_NOT_EXIST;
	} else {
		loc = getLocation();
	}

	return loc;
}

//@author A0121007A
string Task::getDisplayTime() {
	string time;

	if (Task::isNonSpecifiedTime(getTime())) {
		time = Task::STRING_NOT_EXIST;
	}
	else {
		time = getTime();
	}

	return time;
}

//@author A0121007A
string Task::getDisplayDate() {
	string date;

	if (Task::isNonSpecifiedDate(getDate())) {
		date = Task::STRING_NOT_EXIST;
	}
	else {
		date = getDate();
	}

	return date;
}

//@author A0121007A
string Task::getDate() {
	string startDate;
	string endDate;
	string date;

	startDate = getStartDate();
	endDate = getEndDate();
	date = formatStartEndDate(startDate, endDate);

	return date;
}

//@author A0121007A
string Task::getStartDate() {
	string d;
	string m;
	string y;
	string startDate;

	if (Utility::isEmpty(getStartDay())) {
		d = Task::DISPLAY_DATE_ATTR_NOT_SPECIFIED;
	} else {
		d = getStartDay();
	}
	if (Utility::isEmpty(getStartMonth())) {
		m = Task::DISPLAY_DATE_ATTR_NOT_SPECIFIED;
	} else {
		m = getStartMonth();
	}
	if (Utility::isEmpty(getStartYear())) {
		y = Task::DISPLAY_DATE_ATTR_NOT_SPECIFIED;
	} else {
		y = getStartYear();
	}
	
	startDate = formatDate(d, m, y);

	return startDate;
}

//@author A0121007A
string Task::getEndDate() {
	string d;
	string m;
	string y;
	string endDate;

	if (Utility::isEmpty(getEndDay())) {
		d = Task::DISPLAY_DATE_ATTR_NOT_SPECIFIED;
	}
	else {
		d = getEndDay();
	}
	if (Utility::isEmpty(getEndMonth())) {
		m = Task::DISPLAY_DATE_ATTR_NOT_SPECIFIED;
	}
	else {
		m = getEndMonth();
	}
	if (Utility::isEmpty(getEndYear())) {
		y = Task::DISPLAY_DATE_ATTR_NOT_SPECIFIED;
	}
	else {
		y = getEndYear();
	}

	endDate = formatDate(d, m, y);

	return endDate;
}

//@author A0121007A
string Task::formatDate(string d, string m, string y) {
	string formattedDate;

	formattedDate = d + Task::DATE_SEPARATOR_ENGLISH + m + Task::DATE_SEPARATOR_ENGLISH + y;

	return formattedDate;
}

//@author A0121007A
string Task::formatStartEndDate(string s, string e) {
	string date;

	if (Task::isNonSpecifiedDate(s) && Task::isNonSpecifiedDate(e)) {
		date = Task::DISPLAY_DATE_NOT_SPECIFIED;
	} else if (Task::isNonSpecifiedDate(e)) {
		date = s;
	} else {
		date = s + Task::DATE_RANGE_SEPARATOR + e;
	}

	return date;
}

//@author A0121007A
bool Task::isNonSpecifiedHour(string t) {
	if (t.compare(Task::DISPLAY_HOUR_NOT_SPECIFIED) == 0) {
		return true;
	}
	return false;
}

//@author A0121007A
bool Task::isNonSpecifiedTime(string t) {
	if (t.compare(Task::DISPLAY_TIME_NOT_SPECIFIED) == 0) {
		return true;
	}
	return false;
}

//@author A0121007A
bool Task::isNonSpecifiedDate(string d) {
	if (d.compare(Task::DISPLAY_DATE_NOT_SPECIFIED) == 0) {
		return true;
	}
	return false;
}

//@author A0121007A
bool Task::isValidTime(vector<string> userInputParsed) {
	bool sH = isValidStartHour(userInputParsed);
	bool sM = isValidStartMinute(userInputParsed);
	bool eH = isValidEndHour(userInputParsed);
	bool eM = isValidEndMinute(userInputParsed);
	if (sH && sM && eH && eM) {
		return true;
	}
	return false;
}

//@author A0121007A
bool Task::isValidStartHour(vector<string> userInputParsed) {
	string sH = userInputParsed.at(Task::ATTR::STARTHOUR);

	if (Utility::isEmpty(sH)) {
		return true;
	}

	int hour;
	try {
		hour = stoi(sH);
	} catch (exception &) {
		Utility::showToUser(Task::ERROR_STARTHOUR);
		return false;
	}

	if (!isValidHour(hour)) {
		Utility::showToUser(Task::ERROR_STARTHOUR);
		return false;
	}

	return true;
}

//@author A0121007A
bool Task::isValidStartMinute(vector<string> userInputParsed) {
	string sM = userInputParsed.at(Task::ATTR::STARTMINUTE);

	if (Utility::isEmpty(sM)) {
		return true;
	}

	int minute;
	try {
		minute = stoi(sM);
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_STARTMINUTE);
		return false;
	}

	if (!isValidMinute(minute)) {
		Utility::showToUser(Task::ERROR_STARTMINUTE);
		return false;
	}

	return true;
}

//@author A0121007A
bool Task::isValidEndHour(vector<string> userInputParsed) {
	string eH = userInputParsed.at(Task::ATTR::ENDHOUR);

	if (Utility::isEmpty(eH)) {
		return true;
	}

	int hour;
	try {
		hour = stoi(eH);
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_ENDHOUR);
		return false;
	}

	if (!isValidHour(hour)) {
		Utility::showToUser(Task::ERROR_ENDHOUR);
		return false;
	}

	//check if dates are the same to compare time on a same day
	if (Task::isSameStartEndDate(userInputParsed)) {
		//assert? not supposed to be used before checking starthour validity
		int sH;
		try {
			sH = stoi(userInputParsed.at(Task::ATTR::STARTHOUR));
		}
		catch (exception &) {
			return true;
		}
		if (sH <= hour) {
			return true;
		}
	} else if (Task::isGreaterEndDate(userInputParsed)) {
		return true;
	}
	Utility::showToUser(Task::ERROR_ENDDATE);
	return false;
}

//@author A0121007A
bool Task::isValidEndMinute(vector<string> userInputParsed) {
	string eM = userInputParsed.at(Task::ATTR::ENDMINUTE);

	if (Utility::isEmpty(eM)) {
		return true;
	}

	int minute;
	try {
		minute = stoi(eM);
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_ENDMINUTE);
		return false;
	}

	if (!isValidMinute(minute)) {
		Utility::showToUser(Task::ERROR_ENDMINUTE);
		return false;
	}

	//check if dates are the same to compare time on a same day
	if (isSameStartEndDate(userInputParsed)) {
		//assert? not supposed to be used before checking starthour validity
		//dont check for hour since it should be checked earlier
		int sM;
		try {
			sM = stoi(userInputParsed.at(Task::ATTR::STARTMINUTE));
		}
		catch (exception &) {
			return true;
		}
		if (sM <= minute) {
			return true;
		}
	} else if (Task::isGreaterEndDate(userInputParsed)) {
		return true;
	}
	Utility::showToUser(Task::ERROR_ENDDATE);
	return true;
}

//@author A0121007A
bool Task::isSameStartEndDate(vector<string> userInputParsed) {
	if (!Task::isValidDate(userInputParsed)) {
		return false;
	}
	int sY = stoi(userInputParsed.at(Task::ATTR::STARTYEAR));
	int sM = stoi(userInputParsed.at(Task::ATTR::STARTMONTH));
	int sD = stoi(userInputParsed.at(Task::ATTR::STARTDAY));
	try {
		int eY = stoi(userInputParsed.at(Task::ATTR::ENDYEAR));
		int eM = stoi(userInputParsed.at(Task::ATTR::ENDMONTH));
		int eD = stoi(userInputParsed.at(Task::ATTR::ENDDAY));

		if (sY == eY && sM == eM && sD == eD) {
			return true;
		}
	} catch (exception &) {
		if (Utility::isEmpty(userInputParsed.at(Task::ATTR::ENDYEAR)) &&
			Utility::isEmpty(userInputParsed.at(Task::ATTR::ENDMONTH)) &&
			Utility::isEmpty(userInputParsed.at(Task::ATTR::ENDDAY))) {
			return true;
		}
	}

	return false;
}

//code duplication with method above (same start end date), could be more efficient
//@author A0121007A
bool Task::isGreaterEndDate(vector<string> userInputParsed) {
	if (!Task::isValidDate(userInputParsed)) {
		return false;
	}
	int sY = stoi(userInputParsed.at(Task::ATTR::STARTYEAR));
	int sM = stoi(userInputParsed.at(Task::ATTR::STARTMONTH));
	int sD = stoi(userInputParsed.at(Task::ATTR::STARTDAY));
	try {
		int eY = stoi(userInputParsed.at(Task::ATTR::ENDYEAR));
		int eM = stoi(userInputParsed.at(Task::ATTR::ENDMONTH));
		int eD = stoi(userInputParsed.at(Task::ATTR::ENDDAY));

		if (sY < eY) {
			return true;
		}
		else if (sY == eY) {
			if (sM < eM) {
				return true;
			}
			else if (sM == eM) {
				if (sD < eD) {
					return true;
				}
			}
		}
	}
	catch (exception &) {
		if (Utility::isEmpty(userInputParsed.at(Task::ATTR::ENDYEAR)) &&
			Utility::isEmpty(userInputParsed.at(Task::ATTR::ENDMONTH)) &&
			Utility::isEmpty(userInputParsed.at(Task::ATTR::ENDDAY))) {
			return true;
		}
	}

	return false;
}

//@author A0121007A
bool Task::isValidDate(vector<string> userInputParsed) {
	//check start year validity
	bool sY = isValidStartYear(userInputParsed.at(Task::ATTR::STARTYEAR));
	if (!sY) {
		return false;
	}

	//check end year validity
	bool eY = isValidEndYear(userInputParsed.at(Task::ATTR::ENDYEAR),
		userInputParsed.at(Task::ATTR::STARTYEAR));
	if (!eY) {
		return false;
	}

	//check start month validity
	bool sM = isValidStartMonth(userInputParsed.at(Task::ATTR::STARTMONTH),
		userInputParsed.at(Task::ATTR::STARTYEAR));
	if (!sM) {
		return false;
	}

	//check end month validity
	bool eM = isValidEndMonth(userInputParsed.at(Task::ATTR::ENDMONTH),
		userInputParsed.at(Task::ATTR::ENDYEAR),
		userInputParsed.at(Task::ATTR::STARTMONTH),
		userInputParsed.at(Task::ATTR::STARTYEAR));
	if (!eM) {
		return false;
	}

	//check start day validity
	bool sD = isValidStartDay(userInputParsed.at(Task::ATTR::STARTDAY),
		userInputParsed.at(Task::ATTR::STARTMONTH),
		userInputParsed.at(Task::ATTR::STARTYEAR));
	if (!sD) {
		return false;
	}

	//check end day validity
	bool eD = isValidEndDay(userInputParsed.at(Task::ATTR::ENDDAY),
		userInputParsed.at(Task::ATTR::ENDMONTH),
		userInputParsed.at(Task::ATTR::ENDYEAR),
		userInputParsed.at(Task::ATTR::STARTDAY),
		userInputParsed.at(Task::ATTR::STARTMONTH),
		userInputParsed.at(Task::ATTR::STARTYEAR));
	if (!eD) {
		return false;
	}
	
	return true;
}

//@author A0121007A
bool Task::isValidStartDay(string sD, string sM, string sY) {
	if (Utility::isEmpty(sD)) {
		return true;
	}

	int day;
	int month;
	int year;
	try {
		day = stoi(sD);
		month = stoi(sM);
		year = stoi(sY);
		if (isValidDay(day, month, year)) {
			return true;
		}
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_STARTDAY);
		return false;
	}

	return false;
}

//@author A0121007A
bool Task::isValidStartMonth(string sM, string sY) {
	if (Utility::isEmpty(sM)) {
		return true;
	}

	int month;
	try {
		month = stoi(sM);
		if (isValidMonth(month)) {
			return true;
		}
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_STARTMONTH);
		return false;
	}
	Utility::showToUser(Task::ERROR_STARTMONTH);
	return false;
}

//@author A0121007A
bool Task::isValidStartYear(string sY) {
	if (Utility::isEmpty(sY)) {
		return true;
	}

	int year;
	try {
		year = stoi(sY);
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_STARTYEAR);
		return false;
	}
	return true;
}

//@author A0121007A
bool Task::isValidEndDay(string eD, string eM, string eY, string sD, string sM, string sY) {
	if (Utility::isEmpty(eD)) {
		return true;
	}

	int day;
	int month;
	int year;
	try {
		day = stoi(eD);
		month = stoi(eM);
		year = stoi(eY);
	} catch (exception &) {
		Utility::showToUser(Task::ERROR_ENDDAY);
		return false;
	}

	int sDay;
	int sMonth;
	int sYear;
	//for "by date do something" format
	try {
		sDay = stoi(sD);
		sMonth = stoi(sM);
		sYear = stoi(sY);
	}
	catch (exception &) {
		if (isValidDay(day, month, year)) {
			return true;
		}
	}

	try {
		day = stoi(eD);
		month = stoi(eM);
		year = stoi(eY);
		if (isValidDay(day, month, year)) {
			if (sYear >= year && sMonth >= month && sDay > day) {
				Utility::showToUser(Task::ERROR_ENDDAY);
				return false;
			}
			return true;
		}
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_ENDDAY);
		return false;
	}
	Utility::showToUser(Task::ERROR_ENDDAY);
	return false;
}

//@author A0121007A
bool Task::isValidEndMonth(string eM, string eY, string sM, string sY) {
	if (Utility::isEmpty(eM)) {
		return true;
	}

	int month;
	int year;
	try {
		month = stoi(eM);
		year = stoi(eY);
	} catch (exception &) {
		if (isValidMonth(month)) {
			return true;
		}
	}

	int sMonth;
	int sYear;
	try {
		sMonth = stoi(sM);
		sYear = stoi(sY);
	}
	catch (exception &) {
		if (isValidMonth(month)) {
			return true;
		}
		return false;
	}

	try {
		if (isValidMonth(month)) {
			if (sYear >= year && sMonth > month) {
				Utility::showToUser(Task::ERROR_ENDMONTH);
				return false;
			}
			return true;
		}
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_ENDMONTH);
		return false;
	}
	Utility::showToUser(Task::ERROR_ENDMONTH);
	return false;
}

//@author A0121007A
bool Task::isValidEndYear(string eY, string sY) {
	if (Utility::isEmpty(eY)) {
		return true;
	}
	int startYear;
	try {
		startYear = stoi(sY);
	} catch (exception &) {
		return true;
	}

	int year;
	try {
		year = stoi(eY);
		if (startYear <= year) {
			return true;
		}
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_ENDYEAR);
		return false;
	}
	Utility::showToUser(Task::ERROR_ENDYEAR);
	return false;
}

//@author A0121007A
bool Task::isValidHour(int h) {
	if (h >= 0 && h <= 23) {
		return true;
	}
	Utility::showToUser(Task::ERROR_HOUR);
	return false;
}

//@author A0121007A
bool Task::isValidMinute(int m) {
	if (m >= 0 && m <= 59) {
		return true;
	}
	Utility::showToUser(Task::ERROR_MINUTE);
	return false;
}

//@author A0121007A
bool Task::isValidDay(int d, int m, int y) {
	if (d >= 1 && d <= 31) {

		//months of less than 31 days
		if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11)) {
			Utility::showToUser(Task::ERROR_DAY_31);
			return false;
		}

		//february
		if (m == 2) {
			if (d == 29 && (y % 4 == 0)) { //leap year
				return true;
			} else if (d > 28) {
				Utility::showToUser(Task::ERROR_DAY_FEB);
				return false;
			}
		}

		return true;
	}

	Utility::showToUser(Task::ERROR_DAY);
	return false;
}

//@author A0121007A
bool Task::isValidMonth(int m) {
	if (m >= 1 && m <= 12) {
		return true;
	}
	Utility::showToUser(Task::ERROR_MONTH);
	return false;
}

//@author A0121007A
bool Task::isValidPriority(string priority) {
	if (Utility::isEmpty(priority)) {
		return true;
	}

	int p;
	try {
		p = stoi(priority);
	}
	catch (exception &) {
		Utility::showToUser(Task::ERROR_PRIORITY);
		return false;
	}
	return true;
}