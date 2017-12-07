//@author A0121007A
/*
KeepUpLib is the class that coordinates all actions together and allows interaction
between user, calendar and command parser.
*/
#ifndef KEEPUP_H
#define KEEPUP_H

#include <assert.h>
#include "Calendar.h"
#include "CommandParser.h"
#include "Task.h"
#include "Utility.h"
#include "Storage.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class KeepUpLib {
public:
	//@author A0121007A
	/* the main method of KeepUpLib */
	void start();
private:
	//@author A0121007A
	/* messages for the user */
	static const string MESSAGE_GOODBYE;
	static const string MESSAGE_WELCOME;
	static const string MESSAGE_PROMPT_COMMAND;
	static const string MESSAGE_PROMPT_SEARCH;
	static const string MESSAGE_CONFIRM_EXIT;
	static const string MESSAGE_CONFIRM_TASKADD;
	static const string MESSAGE_CONFIRM_TASKDEL;
	static const string MESSAGE_CONFIRM_TASKDONE;
	static const string MESSAGE_NOTFOUND;

	//@author A0121007A
	/* methods */
	/* checks everything is fine before pursuing */
	bool isAllValid(vector<string> userInputParsed);
	void confirmExit();
	void executeUserInput(vector<string> userInputParsed, Calendar *cal);
	void run(Calendar *cal);
	void goodbyeMessage();
	void welcomeMessage();

	//@author A0121007A
	/* helper method */
	string promptUserForInput();

	//@author A0121007A
	/* variable */
	bool fineToExit;
};

#endif