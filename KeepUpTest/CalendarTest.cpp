#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeepUpTest
{
	TEST_CLASS(CalendarTest)
	{
	public:
		//@author A0121007A
		TEST_METHOD(EditTest) {
			/*
			string input;
			vector<string> hardCodedOutput(Task::ATTR::SIZE);
			vector<string> parsedString(Task::ATTR::SIZE);
			Calendar *cal = new Calendar();
			Task t;

			input = "speak with the durian in <Alaska> at 0:00pm on 25/04/2014";
			parsedString = CommandParser::getParsedUserInput(input);
			t = Task(parsedString);
			cal->taskAdd(t);

			cal->taskEdit(0);
			//SELECT CONSOLE OPTIONS IN UNIT TESTING?

			free(cal);
			*/
		}

		//@author A0121007A
		TEST_METHOD(SearchTest) {
			string input;
			vector<string> hardCodedOutput;
			vector<string> parsedString(Task::ATTR::SIZE);
			Calendar *cal = new Calendar();
			Task t;

			input = "dance with a kiwi at <the dance club> at 12:00pm on 01/01/2015";
			parsedString = CommandParser::getParsedUserInput(input);
			t = Task(parsedString);
			cal->taskAdd(t);

			input = "make romance with a kiwi at <Clarke Quay> at 20:30 on 01/01/2015";
			parsedString = CommandParser::getParsedUserInput(input);
			t = Task(parsedString);
			cal->taskAdd(t);

			input = "reject orange proposal on 02/01/2015";
			parsedString = CommandParser::getParsedUserInput(input);
			t = Task(parsedString);
			cal->taskAdd(t);

			hardCodedOutput.push_back("1. dance with a kiwi in the dance club at 12:00 on 1/1/2015");
			hardCodedOutput.push_back("2. make romance with a kiwi in Clarke Quay at 20:30 on 1/1/2015");

			input = "kiwi";
			cal->getSearchResults(input);
			cal->formatResultsForDisplay();

			TestUtility::checkVectorEquality(hardCodedOutput, cal->searchResultsForDisplay);
			TestUtility::clearVector(hardCodedOutput);

			free(cal);

		}

	};
}