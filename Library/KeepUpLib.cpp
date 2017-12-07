//@author A0121007A
#include "KeepUpLib.h"

/* KeepUp Calendar v0.1
 * Team Members:
 * Francois-Xavier Lemire
 * Guan Tengyan
 * Ong Shi Rong
 * Sun Yangge
 * Xie Xin
 */

//@author A0121007A
const string KeepUpLib::MESSAGE_WELCOME = "Welcome to KeepUp!";
const string KeepUpLib::MESSAGE_PROMPT_COMMAND = "Please enter command:";
const string KeepUpLib::MESSAGE_PROMPT_SEARCH = "Please enter search term:";
const string KeepUpLib::MESSAGE_GOODBYE = "Goodbye!";
const string KeepUpLib::MESSAGE_CONFIRM_EXIT = "Are you sure you wish to exit? All unsaved changes will be lost. (Y/n)";
const string KeepUpLib::MESSAGE_CONFIRM_TASKADD = "Task added!";
const string KeepUpLib::MESSAGE_CONFIRM_TASKDEL = "Task deleted!";
const string KeepUpLib::MESSAGE_CONFIRM_TASKDONE = "Task marked done!";
const string KeepUpLib::MESSAGE_NOTFOUND = "Sorry! The task you want is not found!";

//@author A0121007A
void KeepUpLib::welcomeMessage() {
	Utility::showToUser(MESSAGE_WELCOME);
}
//@author A0121007A
void KeepUpLib::goodbyeMessage() {
	Utility::showToUser(MESSAGE_GOODBYE);
}
//@author A0121007A
string KeepUpLib::promptUserForInput() {
	string operation;
	getline(cin, operation);
	return operation;
}
//@author A0121007A
void KeepUpLib::executeUserInput(vector<string> uInputParsed, Calendar *cal) {
	Calendar::COMMAND_TYPE command = Utility::stringToCOMMAND_TYPE(uInputParsed[Task::ATTR::COMMAND]);
	assert(Utility::isValidCommand(command));

	//exit if is command add unvalid params
	if (Utility::isAdd(command) && !(isAllValid(uInputParsed))) {
		return;
	}

	int taskID;
	string searchTerm;
	string param;
	Task t = Task();

	if (Utility::isAdd(command)) {
		Utility::removeEscapeChar(uInputParsed.at(Task::ATTR::NAME));
		t = Task(uInputParsed);
	}
	
	switch (command) {
	case Calendar::TASKADD:
		cal->taskAdd(t);
		Utility::showToUser(KeepUpLib::MESSAGE_CONFIRM_TASKADD);
		break;
	case Calendar::TASKBLOCK:
		Utility::showToUser(Calendar::MESSAGE_NOT_YET_IMPLEMENTED);
		break;
	case Calendar::TASKDECORATE:
		Utility::showToUser(Calendar::MESSAGE_NOT_YET_IMPLEMENTED);
		break;
	case Calendar::TASKDELETE:
		Utility::showToUser(KeepUpLib::MESSAGE_PROMPT_SEARCH);
		getline(cin, searchTerm);
		taskID = cal->taskSearch(searchTerm);
		if (taskID == Calendar::GO_BACK_OPTION) {
			return;
		}
		if (cal->isFound(taskID)) {
			cal->taskDelete(taskID);
			Utility::showToUser(KeepUpLib::MESSAGE_CONFIRM_TASKDEL);
		}
		else {
			Utility::showToUser(KeepUpLib::MESSAGE_NOTFOUND);
		}
		break;
	case Calendar::TASKDONE:
		Utility::showToUser(KeepUpLib::MESSAGE_PROMPT_SEARCH);
		searchTerm = cal->getSearchTerm();
		taskID = cal->taskSearch(searchTerm);
		if (taskID == Calendar::GO_BACK_OPTION) {
			return;
		}
		if (cal->isFound(taskID)) {
			cal->taskDone(taskID);
			Utility::showToUser(KeepUpLib::MESSAGE_CONFIRM_TASKDONE);
		}
		else {
			Utility::showToUser(KeepUpLib::MESSAGE_NOTFOUND);
		}
		break;
	case Calendar::TASKEDIT:
		Utility::showToUser(KeepUpLib::MESSAGE_PROMPT_SEARCH);
		searchTerm = cal->getSearchTerm();
		taskID = cal->taskSearch(searchTerm);
		if (taskID == Calendar::GO_BACK_OPTION) {
			return;
		}
		if (cal->isFound(taskID)) {
			cal->taskEdit(taskID);
		} else {
			Utility::showToUser(KeepUpLib::MESSAGE_NOTFOUND);
		}
		break;
	case Calendar::HELP:
		param = uInputParsed.at(Task::ATTR::NAME);
		if (Utility::areEqual(param, Calendar::COMMAND_HELP)) {
			cal->help();
		} else {
			cal->help(param);
		}
		break;
	case Calendar::SAVE:
		param = uInputParsed.at(Task::ATTR::NAME);
		if (Utility::areEqual(param, Calendar::COMMAND_SAVE)) {
			param = Calendar::DEFAULT_NAME;
		}
		cal->save(param);
		break;
	case Calendar::LOAD:
		param = uInputParsed.at(Task::ATTR::NAME);
		if (Utility::areEqual(param, Calendar::COMMAND_LOAD)) {
			param = Calendar::DEFAULT_NAME;
		}
		cal->load(param);
		break;
	case Calendar::TASKPRINT:
		Utility::showToUser(Calendar::MESSAGE_NOT_YET_IMPLEMENTED);
		//cal.taskPrint();
		break;
	case Calendar::TASKREMIND:
		Utility::showToUser(Calendar::MESSAGE_NOT_YET_IMPLEMENTED);
		//cal.taskRemind();
		break;
	case Calendar::TASKREPEAT:
		Utility::showToUser(Calendar::MESSAGE_NOT_YET_IMPLEMENTED);
		//cal.taskRepeat();
		break;
	case Calendar::TASKVIEW:
		param = uInputParsed.at(Task::ATTR::NAME);
		cal->taskView(param);
		break;
	case Calendar::TASKWEATHER:
		Utility::showToUser(Calendar::MESSAGE_NOT_YET_IMPLEMENTED);
		//cal.taskWeather();
		break;
	case Calendar::TASKUNDO:
		cal->undoCommand();
		break;
	case Calendar::TASKREDO:
		cal->redoCommand();
		break;
	default:
		break;
	}
}

//@author A0121007A
bool KeepUpLib::isAllValid(vector<string> userInputParsed) {
	bool validTime = Task::isValidTime(userInputParsed);
	bool validPriority = Task::isValidPriority(userInputParsed.at(Task::ATTR::PRIORITY));
	if (validTime && validPriority) {
		bool validDate = Task::isValidDate(userInputParsed);
		return validDate;
	}
	return false;
}
//@author A0121007A
void KeepUpLib::run(Calendar *cal) {
	vector<string> uInputParsed(Task::ATTR::SIZE);
	uInputParsed.at(Task::ATTR::COMMAND) = Calendar::COMMAND_EXIT; //avoid infinite loop?
	do {
		Utility::showToUser(KeepUpLib::MESSAGE_PROMPT_COMMAND);
		string uInput = promptUserForInput();
		try {
			uInputParsed = CommandParser::getParsedUserInput(uInput);
		} catch (exception &e) {
			Utility::showToUser(e.what());
		}
		executeUserInput(uInputParsed, cal);
	} while (uInputParsed[Task::ATTR::COMMAND] != Calendar::COMMAND_EXIT);
}
//@author A0121007A
void KeepUpLib::confirmExit() {
	Utility::showToUser(KeepUpLib::MESSAGE_CONFIRM_EXIT);
	if (Utility::getYesNoConfirmation()) {
		fineToExit = true;
	} else {
		fineToExit = false;
	}
}
//@author A0121007A
void KeepUpLib::start() {
	welcomeMessage();
	fineToExit = false;
	Calendar *cal = new Calendar(); //or load from storage
	do {
		run(cal);
		confirmExit();
	} while (!fineToExit);
	goodbyeMessage();
	free(cal);
}