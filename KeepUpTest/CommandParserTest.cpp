#include "stdafx.h"
#include "CppUnitTest.h"

// ATTENTION!!!
// this test function contains some terms like "this sunday" "next friday". these are related to local
// time on the computer. So testing on another date might cause the actual date not equal to supposed 
// date. 
// this test passed on 4/14/2014.

//@author A0090968M
//CommandParser Test


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeepUpTest {

	TEST_CLASS(CommandParserTest) {

public:

	TEST_METHOD(AddTest) {

		string input;
		vector<string> parsedString(Task::ATTR::SIZE);
		vector<string> hardCodedParsedString(Task::ATTR::SIZE);
		time_t localTime;
		struct tm timenow;
		string localDay;
		localTime = time(NULL);
		localtime_s(&timenow,&localTime);
		unsigned int dayNow = timenow.tm_mday;
		stringstream ss;
	    ss << dayNow;
	    ss >> localDay;

		input = "buy apple";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "buy apple";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "false";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);


		input = "so funny at 14.00";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = localDay;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "14";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "so funny";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		input = "eat banana at 8:30pm on 2/9";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "2";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "20";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "30";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "eat banana";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);


		input = "buy some chikoo at <school canteen> at 5.30am on 11/4/2014";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "11";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "5";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "30";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "buy some chikoo";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "school canteen";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);


		input = "finish eating dragonfruit by 20/4";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
			hardCodedParsedString[Task::ATTR::STARTYEAR] = Task::STRING_NOT_EXIST;
			hardCodedParsedString[Task::ATTR::STARTMONTH] = Task::STRING_NOT_EXIST;
			hardCodedParsedString[Task::ATTR::STARTDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "20";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "finish eating dragonfruit";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//kiwi
		input = "put one kiwi by 22/4 12pm";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = localDay;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "22";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "12";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "put one kiwi";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//grapes
		input = "exam grapes by 10.30 18/4";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = localDay;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "18";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "10";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "30";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "exam grapes";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//starfruit
		input = "talk to starfruit at <pays-bas>";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "talk to starfruit";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "pays-bas";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "false";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);
		//watermelon
		input = "have meetings with durians at <pays-bas> 5/9/2014 - 10/9/2014";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "5";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "9";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "10";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "have meetings with durians";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "pays-bas";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);
		//durian
		input = "have meetings with durians at <pays-bas> 5/9/2014-10/9/2014";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "5";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "9";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "10";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "have meetings with durians";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "pays-bas";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//rambutan
		input = "finish report with rambutan at <pays-bas> on 14/4-19/4";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "14";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "19";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "finish report with rambutan";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "pays-bas";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);


		//mangosteen
		input = "sleep with mangosteen at <bedroom> 3 - 4.20pm";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = localDay;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "15";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "16";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "20";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "sleep with mangosteen";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "bedroom";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);


		//pear
		input = "dance with pear at <dance hall> 3pm-4pm on 16/4";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "16";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "15";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "16";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "dance with pear";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "dance hall";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//pineapple
		input = "meet with pineapples at 8 - 10.20pm on 17/4";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "17";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "20";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "22";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "20";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "meet with pineapples";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//coconut
		input = "break coconuts in <my courtyard> at 14 from 10/04-11/12";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "10";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "14";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "12";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "11";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "break coconuts";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "my courtyard";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);


		

		//peach
		input = "put peach in <fridge> at 13:00 on 05/06";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "06";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "05";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "13";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "put peach";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "fridge";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//orange
		input = "discuss with jane about orange trees on jan 3rd";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "1";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "3";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "discuss with jane about orange trees";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//mango
		input = "test mango feb 2nd - dec 25th";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "2";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "2";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "12";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "25";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "test mango";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//lychee
		input = "peel lychee 9 Mar 2015 - June 2nd 2015";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "3";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "9";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "6";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "2";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "peel lychee";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//play
		input = "play soccer on 3rd June 2015";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "6";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "3";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST ;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST ;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST ;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "play soccer";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//spaceship
		input = "driving spaceship 17 sep 2015 - jan 1st 2016";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "17";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2016";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "1";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "1";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "driving spaceship";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//greentea
		input = "keep greentea in <fridge> by Apr 15 2015";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "15";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "keep greentea";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "fridge";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//milk
		input = "drink milk 2nd mar - jun 10";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "3";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "2";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "6";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "10";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "drink milk";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//milktea
		input = "buy milktea 3rd july - 3rd august";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "7";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "3";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "8";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "3";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "buy milktea";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//tea
			input = "brew tea september 9 - 20 october";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "9";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "10";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "20";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "brew tea";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
			TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//bread
		input = "make bread at <kitchen> November 18 - December 31st";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "11";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "18";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "12";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "31";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "make bread";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "kitchen";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//cake
		input = "design cake at <home> on 27 November";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "11";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "27";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "design cake";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "home";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//dinner
		input = "have dinner on this sunday";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "20";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "have dinner";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//shopping
		input = "shopping by next sat 3pm at <bugis>";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = localDay;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "26";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "15";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "shopping";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "bugis";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//study
		input = "study this Sun - next Friday";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] ="2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "20";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "25";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "study";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		input = "by 2 sleep";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "12";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] ="2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "04";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "12";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "2";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "sleep";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		input = "on 2/9 eat banana at 8:30pm";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "2";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "20";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "30";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "eat banana";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		input = "at <school canteen> buy some chikoo at 5.30am on 11/4/2014";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "11";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "5";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "30";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "buy some chikoo";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "school canteen";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		input = "by 20/4 finish eating dragonfruit ";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "20";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "finish eating dragonfruit";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//kiwi
		input = "by 22/4 12pm put one kiwi in <glass>";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = localDay;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "22";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "12";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "put one kiwi";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "glass";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//grapes
		input = "by 10.30 18/4 exam grapes";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = localDay;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "18";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "10";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "30";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "exam grapes";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//starfruit
		input = "at <pays-bas> talk to starfruit ";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "talk to starfruit";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "pays-bas";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "false";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);
		//watermelon
		input = "5/9/2014 - 10/9/2014 have meetings with durians at <pays-bas>";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "5";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "9";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "10";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "have meetings with durians";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "pays-bas";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);
		//durian
		input = "at <pays-bas> have meetings with durians 5/9/2014-10/9/2014";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "5";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "9";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "10";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "have meetings with durians";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "pays-bas";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//rambutan
		input = "on 14/4-19/4 finish report with rambutan at <pays-bas>";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "14";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "19";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "finish report with rambutan";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "pays-bas";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);


		//mangosteen
		input = "sleep with mangosteen 3 - 4.20pm at <bedroom>";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = localDay;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "15";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "16";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "20";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "sleep with mangosteen";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "bedroom";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);


		//pear
		input = "3pm-4pm at <dance hall> dance with pear on 16/4";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "16";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "15";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "16";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "dance with pear";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "dance hall";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//pineapple
		input = "meet with pineapples on 17/4 at 8 - 10.20pm ";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "17";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "20";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "22";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "20";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "meet with pineapples";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//coconut
		input = "from 10/04-11/12 in <my courtyard> break coconuts  at 14 ";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "10";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "14";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "12";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "11";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "break coconuts";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "my courtyard";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);


			//watermelon
		input = "destroy watermelons in <cave> at 3pm-4pm from 1/1-1/2";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "1";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "1";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "15";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "2";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "1";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "16";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "destroy watermelons";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "cave";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);
			

		//peach
		input = "on 05/06 put peach at 13:00 in <fridge> ";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "06";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "05";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = "13";
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "put peach";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "fridge";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//orange
		input = "on jan 3rd discuss with jane about orange trees ";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "1";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "3";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "discuss with jane about orange trees";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//mango
		input = "feb 2nd - dec 25th test mango in <hall>";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "2";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "2";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "12";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "25";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "test mango";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "hall";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//lychee
		input = "9 Mar 2015 - June 2nd 2015 at <room> peel lychee";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "3";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "9";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "6";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "2";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "peel lychee";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "room";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//play
		input = "on 3rd June 2015 play soccer";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "6";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "3";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST ;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST ;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST ;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "play soccer";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//spaceship
		input = "17 sep 2015 - jan 1st 2016 driving spaceship";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "17";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2016";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "1";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "1";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "driving spaceship";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//greentea
		input = "in <fridge> keep greentea  by Apr 15 2015";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2015";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "15";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "keep greentea";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "fridge";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//milk
		input = "2nd mar - jun 10 drink milk";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "3";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "2";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "6";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "10";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "drink milk";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//milktea
		input = "3rd july - 3rd august buy milktea";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "7";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "3";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "8";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "3";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "buy milktea";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//tea
		input = "september 9 - 20 october brew tea";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "9";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "9";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "10";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "20";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "brew tea";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//bread
		input = "at <kitchen> November 18 - December 31st make bread";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "11";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "18";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "12";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "31";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "make bread";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "kitchen";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//cake
		input = "on 27 November at <home> design cake";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "11";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "27";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "design cake";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "home";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//dinner
		input = "on this sunday have dinner";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "20";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMONTH] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDDAY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "have dinner";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//shopping
		input = "by next sat 3pm shopping at <bugis>";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "04";
		hardCodedParsedString[Task::ATTR::STARTDAY] = localDay;
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "26";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = "15";
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = "00";
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "shopping";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = "bugis";
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);

		//study
		input = "this Sun - next Friday study";
		hardCodedParsedString[Task::ATTR::COMMAND] = "add";
		hardCodedParsedString[Task::ATTR::STARTYEAR] ="2014";
		hardCodedParsedString[Task::ATTR::STARTMONTH] = "4";
		hardCodedParsedString[Task::ATTR::STARTDAY] = "20";
		hardCodedParsedString[Task::ATTR::STARTHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::STARTMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDYEAR] = "2014";
		hardCodedParsedString[Task::ATTR::ENDMONTH] = "4";
		hardCodedParsedString[Task::ATTR::ENDDAY] = "25";
		hardCodedParsedString[Task::ATTR::ENDHOUR] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ENDMINUTE] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::PRIORITY] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::NAME] = "study";
		hardCodedParsedString[Task::ATTR::DESCRIPTION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::LOCATION] = Task::STRING_NOT_EXIST;
		hardCodedParsedString[Task::ATTR::ISDONE] = "false";
		hardCodedParsedString[Task::ATTR::HASDATE] = "true";
		hardCodedParsedString[Task::ATTR::HASEXPIRED] = "false";

		parsedString = CommandParser::getParsedUserInput(input);
		TestUtility::checkVectorEquality(hardCodedParsedString, parsedString);
		TestUtility::clearVectors(hardCodedParsedString, parsedString);
	}

	};

}