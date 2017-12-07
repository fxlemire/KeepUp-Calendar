#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeepUpTest
{
	TEST_CLASS(StorageTest)	{
	public:
		//@author A0121007A
		TEST_METHOD(SaveTest) {
			/* create a vector of Tasks */
			string calName = "calendarTest.KeepUp";
			vector<Task> tasks;
			string input = "buy a pear in <Clementi> at 3pm on 4/5";
			vector<string> parsedString = CommandParser::getParsedUserInput(input);
			Task t = Task(parsedString);
			tasks.push_back(t);
			Assert::IsTrue(Storage::save(calName, tasks));
		}

	};
}