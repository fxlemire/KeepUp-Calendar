//@author A0121007A
#include "Calendar.h"
#include "CommandParser.h"
#include "Storage.h"

//@author A0121007A
const string Calendar::DEFAULT_NAME = "myCalendar";

//@author A0121007A
const string Calendar::COMMAND_ADD = "add";
const string Calendar::COMMAND_BLOCK = "block";
const string Calendar::COMMAND_DECORATE = "decorate";
const string Calendar::COMMAND_DELETE = "delete";
const string Calendar::COMMAND_DONE = "done";
const string Calendar::COMMAND_EDIT = "edit";
const string Calendar::COMMAND_EXIT = "exit";
const string Calendar::COMMAND_HELP = "help";
const string Calendar::COMMAND_LOAD = "load";
const string Calendar::COMMAND_PRINT = "print";
const string Calendar::COMMAND_REDO = "redo";
const string Calendar::COMMAND_REMIND = "remind";
const string Calendar::COMMAND_REPEAT = "repeat";
const string Calendar::COMMAND_SAVE = "save";
const string Calendar::COMMAND_UNDO = "undo";
const string Calendar::COMMAND_VIEW = "view";
const string Calendar::COMMAND_VIEW_DONE = "-done";
const string Calendar::COMMAND_VIEW_DEL = "-del";
const string Calendar::COMMAND_WEATHER = "weather";
const string Calendar::COMMAND_INVALID = "invalid";

//@author A0121007A
/* messages */
const string Calendar::MESSAGE_EDIT_NOT_EDITED = "Task could not be edited";
const string Calendar::MESSAGE_EDIT_EDITED = "Task edited!";
const string Calendar::MESSAGE_NOT_YET_IMPLEMENTED = "Sorry, this feature is not yet implemented... :(";

//@author A0121007A
/* help */
const string Calendar::HELP_INTRO = "Here are the commands you can use in KeepUp:";
const string Calendar::HELP_HOW_TO = "To know more about a specific command, type \"help 'command'\"";
const string Calendar::HELP_ADD_1 = "Adds a task. Format is :";
const string Calendar::HELP_ADD_2 = "[task name] in [<location>] at <time> on <date>";
const string Calendar::HELP_ADD_3 = "Square brackets are omitted. Location and/or time and/or date can be omitted.";
const string Calendar::HELP_ADD_4 = "Time can be a single value expressed in different ways, such as : 2, 2:30, 2.30, 2am, 2pm, 2:30am, 2:30pm";
const string Calendar::HELP_ADD_5 = "--> It can also be a range, such as : 2:30pm-16:45";
const string Calendar::HELP_ADD_6 = "Date is expressed as DD/MM/YYYY can be a single value expressed in different ways, such as : 1 or 1/10 or 1/10/2015";
const string Calendar::HELP_ADD_7 = "--> It can also be a range, such as : 1/9/2014-30/4/2017";
const string Calendar::HELP_ADD_8 = "--> keywords: today, td, tomorrow, tmr, tmrw, next ";
const string Calendar::HELP_ADD_9 = "------------> mon, tue, wed, thu, thur, fri, sat, sun, and their corresponding full names";
const string Calendar::HELP_ADD_10 = "------------> jan, feb, mar, may, jun, jul, aug, sep, sept, oct, nov, dec and their corresponding full names";
const string Calendar::HELP_ADD_11 = "------------> 1 jan, 1st may, feb 2nd, oct 3rd, april 4, sept 7th 2016";
const string Calendar::HELP_BLOCK = Calendar::MESSAGE_NOT_YET_IMPLEMENTED;
const string Calendar::HELP_DECORATE = Calendar::MESSAGE_NOT_YET_IMPLEMENTED;
const string Calendar::HELP_DELETE_1 = "Delete a task. Write delete and you will be prompted for your keyword.";
const string Calendar::HELP_DELETE_2 = "If the task you want to delete appears in the results, select it.";
const string Calendar::HELP_DONE_1 = "Marks a task as done. Write done and you will be prompted for your keyword.";
const string Calendar::HELP_DONE_2 = "If the task you want to mark as done appears in the results, select it.";
const string Calendar::HELP_EDIT_1 = "Allows task editing. Write edit and you will be prompted for your keyword.";
const string Calendar::HELP_EDIT_2 = "Choose your task and choose which attribute you want to edit.";
const string Calendar::HELP_EDIT_3 = "Edit the attribute the same way you would in the general query.";
const string Calendar::HELP_EXIT = "Leaves the software. Will ask for confirmation.";
const string Calendar::HELP_LOAD = "Loads all tasks from a file. If the calendar currently already has tasks, the tasks from the file will be added to the current calendar";
const string Calendar::HELP_PRINT = Calendar::MESSAGE_NOT_YET_IMPLEMENTED;
const string Calendar::HELP_REDO = "Redoes the last command undone.";
const string Calendar::HELP_REMIND = Calendar::MESSAGE_NOT_YET_IMPLEMENTED;
const string Calendar::HELP_REPEAT = Calendar::MESSAGE_NOT_YET_IMPLEMENTED;
const string Calendar::HELP_SAVE_1 = "Saves all tasks inside a file of your specified name. The extension is .KeepUp";
const string Calendar::HELP_SAVE_2 = "Format: save myCalendar";
const string Calendar::HELP_UNDO = "Undoes the last command entered.";
const string Calendar::HELP_VIEW_1 = "'view' shows all tasks that are not completed and not deleted."; 
const string Calendar::HELP_VIEW_2 = "'view [keyword]' searches among all tasks for the specific keyword (without '[]')";
const string Calendar::HELP_VIEW_3 = "'view -del' shows all deleted tasks.";
const string Calendar::HELP_VIEW_4 = "'view -done' shows all completed tasks.";
const string Calendar::HELP_WEATHER = Calendar::MESSAGE_NOT_YET_IMPLEMENTED;

//@author A0121007A
/* config */
const int Calendar::TASK_NOT_FOUND = -1;
const string Calendar::TASK_DELETED = "true";
const string Calendar::TASK_DONE = "true";
const string Calendar::ESCAPE_CHAR = "\\";
const int Calendar::GO_BACK_OPTION = -1;

//@author A0121007A
/* prompt messages */
//const string Calendar::MESSAGE_PROMPT_SEARCH_TERM = "Please enter your keyword "
//	"for the task you wish to edit:";
const string Calendar::MESSAGE_PROMPT_TASK_CHOICE_WITHIN_RESULTS = "Please choose the corresponding task:";
const string Calendar::MESSAGE_EDIT_CHOICE_INTRO = "What would you like to edit?";
const string Calendar::MESSAGE_INVALID_CHOICE = "Wrong choice. Please reselect.";

//@author A0121007A
/* edit choices */
const string Calendar::MESSAGE_EDIT_CHOICE_TITLE =
	to_string(EDIT_TYPE::EDIT_TYPE::TITLE) + ". " + "Title";
const string Calendar::MESSAGE_EDIT_CHOICE_DATE_TIME =
	to_string(EDIT_TYPE::EDIT_TYPE::DATETIME) + ". " + "Date and Time";
const string Calendar::MESSAGE_EDIT_CHOICE_LOCATION =
	to_string(EDIT_TYPE::EDIT_TYPE::LOCATION) + ". " + "Location";
const string Calendar::MESSAGE_EDIT_CHOICE_REMINDER =
	to_string(EDIT_TYPE::EDIT_TYPE::REMINDER) + ". " + "Reminder";
const string Calendar::MESSAGE_EDIT_CHOICE_DESCRIPTION =
	to_string(EDIT_TYPE::EDIT_TYPE::DESCRIPTION) + ". " + "Description";
const string Calendar::MESSAGE_EDIT_CHOICE_PRIORITY =
to_string(EDIT_TYPE::EDIT_TYPE::PRIORITY) + ". " + "Priority";
const string Calendar::MESSAGE_EDIT_CHOICE_ATTACH =
	to_string(EDIT_TYPE::EDIT_TYPE::ATTACHFILE) + ". " + "Attach file";
const string Calendar::MESSAGE_EDIT_CHOICE_EVERYTHING =
	to_string(EDIT_TYPE::EDIT_TYPE::EVERYTHING) + ". " + "Overwrite with a new query";
const string Calendar::MESSAGE_EDIT_CHOICE_GO_BACK =
	to_string(EDIT_TYPE::EDIT_TYPE::EVERYTHING + 1) + ". " + "Go back";

//@author A0121007A
/* edit prompt for new data*/
const string Calendar::MESSAGE_EDIT_NEW_TITLE = "Enter new title:";
const string Calendar::MESSAGE_EDIT_NEW_DATE_TIME = "Enter new date and time:";
const string Calendar::MESSAGE_EDIT_NEW_LOCATION = "Enter new location:";
const string Calendar::MESSAGE_EDIT_NEW_REMINDER = "Enter new reminder:";
const string Calendar::MESSAGE_EDIT_NEW_DESCRIPTION = "Enter new description:";
const string Calendar::MESSAGE_EDIT_NEW_PRIORITY = "Please enter your priority number:";
const string Calendar::MESSAGE_EDIT_NEW_ATTACH = "Enter new attach file:";
const string Calendar::MESSAGE_EDIT_NEW_EVERYTHING = "You can retype the whole new task:";

//@author A0121007A
/* edit confirm changes */
const string Calendar::MESSAGE_EDIT_CONFIRM_EDIT = "Task edited!";
const string Calendar::MESSAGE_EDIT_CONFIRM_PRIORITY = "Task received new priority!";

//@author A0121007A
/* menu back */
const string Calendar::GO_BACK = ". Go back";

//@author A0081254L
/* undo/redo messages */
const string Calendar::MESSAGE_UNDO_CAN = "Last command undone!";
const string Calendar::MESSAGE_REDO_CAN = "Last command redone!";
const string Calendar::MESSAGE_UNDO_CANNOT = "There are no more commands to be undone";
const string Calendar::MESSAGE_REDO_CANNOT = "There are no more commands to be redone";

//@author A0081254L
/* view messages */
const string Calendar::MESSAGE_VIEW_TIMED_TASK = "Timed Tasks";
const string Calendar::MESSAGE_VIEW_DEADLINE_TASK = "Deadline Tasks";
const string Calendar::MESSAGE_VIEW_FLOATING_TASK = "Floating Tasks";
const string Calendar::MESSAGE_VIEW_SEPARATOR = "----------------------";
const string Calendar::MESSAGE_VIEW_DONE_TASK = "Here's what's done!";
const string Calendar::MESSAGE_VIEW_DEL_TASK = "Here's what's deleted!";
const string Calendar::MESSAGE_VIEW_ALL_TASK = "Here's what's left!";


vector<string> Calendar::editChoices(EDIT_TYPE::EDIT_TYPE::EVERYTHING + 1);

Calendar::Calendar() {
	taskCollection;
	undoTaskStack;
	redoTaskStack;
	undoIdxStack;
	redoIdxStack;
	timedTask;
	deadlineTask;
	floatingTask;
}

void Calendar::taskAdd(Task newTask) {
	moveToUndo(newTask);
	taskCollection.push_back(newTask);
	undoIdxStack.push(taskCollection.size()-1);
}

void Calendar::taskDelete(int posTask) {
	moveToUndo(posTask);
	undoIdxStack.push(posTask);
	taskCollection.at(posTask).setIsDeleted();
	Utility::clearVector(searchResults);
	Utility::clearVector(searchResultsForDisplay);
}  

//@author A0121007A
void Calendar::taskView(string param) {
	if (Utility::areEqual(param, Calendar::COMMAND_VIEW_DONE)) {
		taskDisplayDone();
	}
	if (Utility::areEqual(param, Calendar::COMMAND_VIEW_DEL)) {
		taskDisplayDeleted();
	}
	if (Utility::areEqual(param, Calendar::COMMAND_VIEW)) {
		taskDisplayAll();
	}
	else {
		Utility::removeEscapeChar(param);
		Calendar::getSearchResults(param);

		if (Utility::isEmpty(searchResults)) {
			return;
		}

		displaySearchResults();
		displayBackOption();

		int userChoice;
		bool notFine = true;

		do {
			try {
				userChoice = pickResult();

				if (userChoice == searchResults.size()) {
					Utility::clearVector(searchResults);
					Utility::clearVector(searchResultsForDisplay);
					return;
				}

				int taskID = searchResults.at(userChoice);
				Task toView = taskCollection.at(taskID);
				vector<string> wholeTask = toView.getAttributesForDisplay();
				Utility::showToUser(wholeTask);
				notFine = false;
			}
			catch (exception &) {
				Utility::showToUser(Calendar::MESSAGE_INVALID_CHOICE);
			}
		} while (notFine);

		Utility::clearVector(searchResults);
		Utility::clearVector(searchResultsForDisplay);
	}
}

//@author A0081254L
bool sortByDateTime(Task firstTask, Task secondTask) {
	if(firstTask.getEndYear() != Task::STRING_NOT_EXIST && secondTask.getEndYear() != Task::STRING_NOT_EXIST) {
		if (firstTask.getEndYear() != secondTask.getEndYear()) {
			return firstTask.getEndYear() < secondTask.getEndYear();
		}
   }
	if(firstTask.getEndMonth() != Task::STRING_NOT_EXIST && secondTask.getEndMonth() != Task::STRING_NOT_EXIST) {
		if (firstTask.getEndMonth() != secondTask.getEndMonth()) {
			return firstTask.getEndMonth() < secondTask.getEndMonth();
		}
   }
	if(firstTask.getEndDay() != Task::STRING_NOT_EXIST && secondTask.getEndDay() != Task::STRING_NOT_EXIST) {
		if (firstTask.getEndDay() != secondTask.getEndDay()) {
			return firstTask.getEndDay() < secondTask.getEndDay();
		}
   }
	if(firstTask.getEndHour() != Task::STRING_NOT_EXIST && secondTask.getEndHour() != Task::STRING_NOT_EXIST) {
		if (firstTask.getEndHour() != secondTask.getEndHour()) {
		   return firstTask.getEndHour() < secondTask.getEndHour();
		}
   }
	if(firstTask.getEndMinute() != Task::STRING_NOT_EXIST && secondTask.getEndMinute() != Task::STRING_NOT_EXIST) {
		if (firstTask.getEndMinute() != secondTask.getEndMinute()) {
			return firstTask.getEndMinute() < secondTask.getEndMinute();
		}
	}
	if(firstTask.getStartYear() != Task::STRING_NOT_EXIST && secondTask.getStartYear() != Task::STRING_NOT_EXIST) {
		if (firstTask.getStartYear() != secondTask.getStartYear()) {
			return firstTask.getStartYear() < secondTask.getStartYear();
		}
   }
	if(firstTask.getStartMonth() != Task::STRING_NOT_EXIST && secondTask.getStartMonth() != Task::STRING_NOT_EXIST) {
		if (firstTask.getStartMonth() != secondTask.getStartMonth()) {
			return firstTask.getStartMonth() < secondTask.getStartMonth();
		}
   }
	if(firstTask.getStartDay() != Task::STRING_NOT_EXIST && secondTask.getStartDay() != Task::STRING_NOT_EXIST) {
		if (firstTask.getStartDay() != secondTask.getStartDay()) {
			return firstTask.getStartDay() < secondTask.getStartDay();
		}
   }
	if(firstTask.getStartHour() != Task::STRING_NOT_EXIST && secondTask.getStartHour() != Task::STRING_NOT_EXIST) {
		if (firstTask.getStartHour() != secondTask.getStartHour()) {
		   return firstTask.getStartHour() < secondTask.getStartHour();
		}
   }
	if(firstTask.getStartMinute() != Task::STRING_NOT_EXIST && secondTask.getStartMinute() != Task::STRING_NOT_EXIST) {
		if (firstTask.getStartMinute() != secondTask.getStartMinute()) {
			return firstTask.getStartMinute() < secondTask.getStartMinute();
		}
	}

	return firstTask.getName() < secondTask.getName();
}

void Calendar::taskDisplayAll() {
	int j=1;

	for(int i=0; i<taskCollection.size(); i++) {
		Task resultTask = taskCollection.at(i);
		
		if ((resultTask.getIsDeleted() != Calendar::TASK_DELETED) && (resultTask.getIsDone() != Calendar::TASK_DONE)) {
			taskSortAll(resultTask);
		}
	}

	if(timedTask.size() > 0 || deadlineTask.size() > 0 || floatingTask.size() > 0) {
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_ALL_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
	}

	if(timedTask.size() > 0) {
		int j=1;
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_TIMED_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		sort(timedTask.begin(), timedTask.end(), sortByDateTime);
		for(int i=0; i<timedTask.size(); i++) {
			Task resultTask = timedTask.at(i);
			string resultName = resultTask.getDisplay();
			string taskNameNumbered = Utility::numberize(j, resultName);
			Utility::showToUser(taskNameNumbered);
			j++;
		}
	}

	if(deadlineTask.size() > 0) {
		int j=1;
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_DEADLINE_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		sort(deadlineTask.begin(), deadlineTask.end(), sortByDateTime);
		for(int i=0; i<deadlineTask.size(); i++) {
			Task resultTask = deadlineTask.at(i);
			string resultName = resultTask.getDisplay();
			string taskNameNumbered = Utility::numberize(j, resultName);
			Utility::showToUser(taskNameNumbered);
			j++;
		}
	}

	if(floatingTask.size() > 0) {
		int j=1;
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_FLOATING_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		for(int i=0; i<floatingTask.size(); i++) {
			Task resultTask = floatingTask.at(i);
			string resultName = resultTask.getDisplay();
			string taskNameNumbered = Utility::numberize(j, resultName);
			Utility::showToUser(taskNameNumbered);
			j++;
		}
	}
	Utility::clearVector(timedTask);
	Utility::clearVector(deadlineTask);
	Utility::clearVector(floatingTask);
}

void Calendar::taskDisplayDone() {
	int j=1;

	for(int i=0; i<taskCollection.size(); i++) {
		Task resultTask = taskCollection.at(i);
		
		if (resultTask.getIsDone() == Calendar::TASK_DONE) {
			taskSortAll(resultTask);
		}
	}

	if(timedTask.size() > 0 || deadlineTask.size() > 0 || floatingTask.size() > 0) {
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_DONE_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
	}

	if(timedTask.size() > 0) {
		int j=1;
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_TIMED_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		sort(timedTask.begin(), timedTask.end(), sortByDateTime);
		for(int i=0; i<timedTask.size(); i++) {
			Task resultTask = timedTask.at(i);
			string resultName = resultTask.getDisplay();
			string taskNameNumbered = Utility::numberize(j, resultName);
			Utility::showToUser(taskNameNumbered);
			j++;
		}
	}

	if(deadlineTask.size() > 0) {
		int j=1;
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_DEADLINE_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		sort(deadlineTask.begin(), deadlineTask.end(), sortByDateTime);
		for(int i=0; i<deadlineTask.size(); i++) {
			Task resultTask = deadlineTask.at(i);
			string resultName = resultTask.getDisplay();
			string taskNameNumbered = Utility::numberize(j, resultName);
			Utility::showToUser(taskNameNumbered);
			j++;
		}
	}

	if(floatingTask.size() > 0) {
		int j=1;
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_FLOATING_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		for(int i=0; i<floatingTask.size(); i++) {
			Task resultTask = floatingTask.at(i);
			string resultName = resultTask.getDisplay();
			string taskNameNumbered = Utility::numberize(j, resultName);
			Utility::showToUser(taskNameNumbered);
			j++;
		}
	}
	Utility::clearVector(timedTask);
	Utility::clearVector(deadlineTask);
	Utility::clearVector(floatingTask);
}

void Calendar::taskDisplayDeleted() {
	int j=1;

	for(int i=0; i<taskCollection.size(); i++) {
		Task resultTask = taskCollection.at(i);
		
		if (resultTask.getIsDeleted() == Calendar::TASK_DELETED) {
			taskSortAll(resultTask);
		}
	}

	if(timedTask.size() > 0 || deadlineTask.size() > 0 || floatingTask.size() > 0) {
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_DEL_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
	}

	if(timedTask.size() > 0) {
		int j=1;
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_TIMED_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		sort(timedTask.begin(), timedTask.end(), sortByDateTime);
		for(int i=0; i<timedTask.size(); i++) {
			Task resultTask = timedTask.at(i);
			string resultName = resultTask.getDisplay();
			string taskNameNumbered = Utility::numberize(j, resultName);
			Utility::showToUser(taskNameNumbered);
			j++;
		}
	}

	if(deadlineTask.size() > 0) {
		int j=1;
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_DEADLINE_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		sort(deadlineTask.begin(), deadlineTask.end(), sortByDateTime);
		for(int i=0; i<deadlineTask.size(); i++) {
			Task resultTask = deadlineTask.at(i);
			string resultName = resultTask.getDisplay();
			string taskNameNumbered = Utility::numberize(j, resultName);
			Utility::showToUser(taskNameNumbered);
			j++;
		}
	}

	if(floatingTask.size() > 0) {
		int j=1;
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		Utility::showToUser(Calendar::MESSAGE_VIEW_FLOATING_TASK);
		Utility::showToUser(Calendar::MESSAGE_VIEW_SEPARATOR);
		for(int i=0; i<floatingTask.size(); i++) {
			Task resultTask = floatingTask.at(i);
			string resultName = resultTask.getDisplay();
			string taskNameNumbered = Utility::numberize(j, resultName);
			Utility::showToUser(taskNameNumbered);
			j++;
		}
	}
	Utility::clearVector(timedTask);
	Utility::clearVector(deadlineTask);
	Utility::clearVector(floatingTask);
}

void Calendar::taskSortAll(Task currTask) {
	if (((currTask.getStartYear() != Task::STRING_NOT_EXIST) && 
		(currTask.getStartMonth() != Task::STRING_NOT_EXIST) && 
		(currTask.getStartDay() != Task::STRING_NOT_EXIST) && 
		(currTask.getEndYear() != Task::STRING_NOT_EXIST) && 
		(currTask.getEndMonth() != Task::STRING_NOT_EXIST)  && 
		(currTask.getEndDay() != Task::STRING_NOT_EXIST))||
		((currTask.getStartHour() != Task::STRING_NOT_EXIST) && 
		(currTask.getStartMinute() != Task::STRING_NOT_EXIST) && 
		(currTask.getEndHour() != Task::STRING_NOT_EXIST)  && 
		(currTask.getEndMinute() != Task::STRING_NOT_EXIST))) {
				timedTask.push_back(currTask);
	}
	else if (((currTask.getStartYear() == Task::STRING_NOT_EXIST) && 
		(currTask.getStartMonth() == Task::STRING_NOT_EXIST) && 
		(currTask.getStartDay() == Task::STRING_NOT_EXIST) && 
		(currTask.getEndYear() != Task::STRING_NOT_EXIST) && 
		(currTask.getEndMonth() != Task::STRING_NOT_EXIST)  && 
		(currTask.getEndDay() != Task::STRING_NOT_EXIST))) {
				deadlineTask.push_back(currTask);
	}
	else if (((currTask.getStartYear() != Task::STRING_NOT_EXIST) && 
		(currTask.getStartMonth() != Task::STRING_NOT_EXIST) && 
		(currTask.getStartDay() != Task::STRING_NOT_EXIST) && 
		(currTask.getEndYear() == Task::STRING_NOT_EXIST) && 
		(currTask.getEndMonth() == Task::STRING_NOT_EXIST)  && 
		(currTask.getEndDay() == Task::STRING_NOT_EXIST))) {
				deadlineTask.push_back(currTask);
	}
	else {
			floatingTask.push_back(currTask);
	} 
}

//@author A0121007A
void Calendar::taskDone(int posTask) {
	moveToUndo(posTask);
	Task doneTask = taskCollection.at(posTask);
	doneTask.setIsDone();
	undoIdxStack.push(posTask);
	taskCollection.at(posTask) = doneTask;
	Utility::clearVector(searchResults);
	Utility::clearVector(searchResultsForDisplay);
}

//@author A0121007A
void Calendar::taskEdit(int posTask) {
	Task toEdit = taskCollection.at(posTask);

	do {
		Calendar::editTaskPrompt();

		int editType = Utility::getIntFromUser();

		if (editType == EDIT_TYPE::EDIT_TYPE::EVERYTHING + 1) {
			Utility::clearVector(searchResults);
			Utility::clearVector(searchResultsForDisplay);
			return;
		}

		toEdit = processEdit(toEdit, editType);

		moveToUndo(posTask);
		undoIdxStack.push(posTask);

		taskCollection.at(posTask) = toEdit;
	} while (/*will leave if user chooses go back*/true);

	Utility::clearVector(searchResults);
	Utility::clearVector(searchResultsForDisplay);
}

//@author A0121007A
Task Calendar::processEdit(Task toEdit, int editType) {

	string input;
	vector<string> uInputParsed;
	vector<string> dateAndTime(DATE_ENUM::DATE_ENUM::LASTPOSITION);

	do {
		switch (editType) {
		case EDIT_TYPE::EDIT_TYPE::TITLE:
			Utility::showToUser(Calendar::MESSAGE_EDIT_NEW_TITLE);
			input = Utility::getStringFromUser();
			toEdit.setName(input);
			Utility::showToUser(Calendar::MESSAGE_EDIT_EDITED);
			return toEdit;
			break;
		case EDIT_TYPE::EDIT_TYPE::DATETIME:
			Utility::showToUser(Calendar::MESSAGE_EDIT_NEW_DATE_TIME);
			input = Utility::getStringFromUser();
			dateAndTime = CommandParser::getDateAndTime(input);
			if (isValidDateTimeEdit(dateAndTime)) {
				toEdit.setDateAndTime(dateAndTime);
				Utility::showToUser(Calendar::MESSAGE_EDIT_CONFIRM_EDIT);
			}
			return toEdit;
			break;
		case EDIT_TYPE::EDIT_TYPE::LOCATION:
			Utility::showToUser(Calendar::MESSAGE_EDIT_NEW_LOCATION);
			input = Utility::getStringFromUser();
			toEdit.setLocation(input);
			Utility::showToUser(Calendar::MESSAGE_EDIT_EDITED);
			return toEdit;
			break;
		case EDIT_TYPE::EDIT_TYPE::REMINDER:
			//Utility::showToUser(Calendar::MESSAGE_EDIT_NEW_REMINDER);
			//input = Utility::getStringFromUser();
			Utility::showToUser(Calendar::MESSAGE_NOT_YET_IMPLEMENTED);
			return toEdit;
			break;
		case EDIT_TYPE::EDIT_TYPE::DESCRIPTION:
			Utility::showToUser(Calendar::MESSAGE_EDIT_NEW_DESCRIPTION);
			input = Utility::getStringFromUser();
			toEdit.setDescription(input);
			Utility::showToUser(Calendar::MESSAGE_EDIT_EDITED);
			return toEdit;
			break;
		case EDIT_TYPE::EDIT_TYPE::PRIORITY:
			input = Calendar::getUserPriority();
			toEdit.setPriority(input);
			Utility::showToUser(Calendar::MESSAGE_EDIT_CONFIRM_PRIORITY);
			Utility::showToUser(Calendar::MESSAGE_EDIT_EDITED);
			return toEdit;
			break;
		case EDIT_TYPE::EDIT_TYPE::ATTACHFILE:
			//Utility::showToUser(Calendar::MESSAGE_EDIT_NEW_ATTACH);
			//input = Utility::getStringFromUser();
			Utility::showToUser(Calendar::MESSAGE_NOT_YET_IMPLEMENTED);
			return toEdit;
			break;
		case EDIT_TYPE::EDIT_TYPE::EVERYTHING:
			Utility::showToUser(Calendar::MESSAGE_EDIT_NEW_EVERYTHING);
			input = Utility::getStringFromUser();
			Utility::addEscapeChar(input);
			uInputParsed = CommandParser::getParsedUserInput(input);
			Utility::removeEscapeChar(uInputParsed.at(Task::ATTR::NAME));
			toEdit = Task(uInputParsed);
			Utility::showToUser(Calendar::MESSAGE_EDIT_EDITED);
			return toEdit;
			break;
		default:
			Utility::showToUser(Calendar::MESSAGE_INVALID_CHOICE);
			break;
		}
	} while (/*invalid choice by user. Valid choice returns!*/ true);
	return toEdit;
}

//@author A0121007A
/* returns the position of the searched task in the vector of the calendar stored tasks */
int Calendar::taskSearch(string searchTerm) {
	Calendar::getSearchResults(searchTerm);

	if (Utility::isEmpty(searchResults)) {
		return Calendar::TASK_NOT_FOUND;
	}
	displaySearchResults();
	displayBackOption();

	int userChoice;
	int result;
	bool notFine = true;
	do {
		try {
			userChoice = pickResult();

			if (userChoice == searchResults.size()) {
				Utility::clearVector(searchResults);
				Utility::clearVector(searchResultsForDisplay);
				return Calendar::GO_BACK_OPTION;
			}

			result = searchResults.at(userChoice);
			notFine = false;
		}
		catch (exception &) {
			Utility::showToUser(Calendar::MESSAGE_INVALID_CHOICE);
		}
	} while (notFine);

	return result;
}

//@author A0121007A
int Calendar::pickResult() {
	Utility::showToUser(Calendar::MESSAGE_PROMPT_TASK_CHOICE_WITHIN_RESULTS);

	int pickTask = Utility::getIntFromUser();

	return pickTask-1;
}

//@author A0121007A
void Calendar::displaySearchResults() {
	formatResultsForDisplay();
	Utility::showToUser(Calendar::searchResultsForDisplay);
}

//@author A0121007A
void Calendar::displayBackOption() {
	int num = searchResults.size() + 1;
	string formatGoBack = to_string(num) + Calendar::GO_BACK;
	Utility::showToUser(formatGoBack);
}

//@author A0121007A
void Calendar::formatResultsForDisplay() {
	for (unsigned int i = 0; i < searchResults.size(); i++) {
		Task resultTask = taskCollection.at(searchResults.at(i));
		string resultName = resultTask.getDisplay();
		string toDisplay = Utility::numberize(i+1, resultName);
		searchResultsForDisplay.push_back(toDisplay);
	}
}

//@author A0121007A
string Calendar::getSearchTerm() {
	string searchTerm;
	//Utility::showToUser(Calendar::MESSAGE_PROMPT_SEARCH_TERM);
	getline(cin, searchTerm);
	return searchTerm;
}

//@author A0121007A
string Calendar::getUserPriority() {
	string priority;
	bool notFine = true;
	Utility::showToUser(Calendar::MESSAGE_EDIT_NEW_PRIORITY);
	do {
		getline(cin, priority);
		try {
			stoi(priority);
			notFine = false;
		}
		catch (exception &) {
			Utility::showToUser(Utility::ERROR_ENTER_NUMBER);
		}
	} while (notFine);
	return priority;
}

//@author A0121007A
void Calendar::editTaskPrompt() {
	Calendar::initializeEditChoices();

	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_INTRO);
	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_TITLE);
	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_DATE_TIME);
	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_LOCATION);
	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_REMINDER);
	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_DESCRIPTION);
	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_PRIORITY);
	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_ATTACH);
	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_EVERYTHING);
	Utility::showToUser(Calendar::MESSAGE_EDIT_CHOICE_GO_BACK);
}

//@author A0121007A
void Calendar::initializeEditChoices() {
	Calendar::editChoices.at(EDIT_TYPE::EDIT_TYPE::TITLE) =
		Calendar::MESSAGE_EDIT_CHOICE_TITLE;
	Calendar::editChoices.at(EDIT_TYPE::EDIT_TYPE::DATETIME) =
		Calendar::MESSAGE_EDIT_CHOICE_DATE_TIME;
	Calendar::editChoices.at(EDIT_TYPE::EDIT_TYPE::LOCATION) =
		Calendar::MESSAGE_EDIT_CHOICE_LOCATION;
	Calendar::editChoices.at(EDIT_TYPE::EDIT_TYPE::REMINDER) =
		Calendar::MESSAGE_EDIT_CHOICE_REMINDER;
	Calendar::editChoices.at(EDIT_TYPE::EDIT_TYPE::DESCRIPTION) =
		Calendar::MESSAGE_EDIT_CHOICE_DESCRIPTION;
	Calendar::editChoices.at(EDIT_TYPE::EDIT_TYPE::ATTACHFILE) =
		Calendar::MESSAGE_EDIT_CHOICE_ATTACH;
	Calendar::editChoices.at(EDIT_TYPE::EDIT_TYPE::EVERYTHING) =
		Calendar::MESSAGE_EDIT_CHOICE_EVERYTHING;
	Calendar::editChoices.at(0) =
		Calendar::MESSAGE_EDIT_CHOICE_GO_BACK;
}

//@author A0121007A
void Calendar::getSearchResults(string searchTerm) {
	for (unsigned int i = 0; i<taskCollection.size(); i++) {
		Task searchedTask = taskCollection.at(i);

		if (!Utility::stringToBool(searchedTask.getIsDeleted())) {
			string searchedName = searchedTask.getName();
			size_t found = searchedName.find(searchTerm);

			if (found != std::string::npos) {
				//Holds the position of Tasks in taskCollection
				searchResults.push_back(i);
			}
		}
	}
}

//@author A0121007A
bool Calendar::isFound(int task) {
	if (task != Calendar::TASK_NOT_FOUND) {
		return true;
	}
	return false;
}

//@author A0121007A
bool Calendar::isValidDateTimeEdit(vector<string> dateAndTime) {
	vector<string> dateTimeAsTASK_ATTR = Utility::convert_DATE_ENUM_to_TASK_ATTR(dateAndTime);

	if (Task::isValidTime(dateTimeAsTASK_ATTR)) {
		return(Task::isValidDate(dateTimeAsTASK_ATTR));
	}
	return false;
}

//@author A0081254L
void Calendar::replaceTask(Task newTask, int posTask) {
	taskCollection.at(posTask) = newTask;
}
void Calendar::moveToUndo(Task newTask) {
	Task currentTask = newTask;
	currentTask.setIsDeleted();
	undoTaskStack.push(currentTask);
}

void Calendar::moveToUndo(int posTask) {
	Task currentTask = taskCollection.at(posTask);	
	undoTaskStack.push(currentTask);
}

void Calendar::redoCommand() {
	if(!redoTaskStack.empty() && !redoIdxStack.empty()) {
		Task redoTask = redoTaskStack.top();
		int posTask = redoIdxStack.top();
		undoTaskStack.push(taskCollection.at(posTask));
		undoIdxStack.push(posTask);
		replaceTask(redoTask, posTask);
		redoTaskStack.pop();
		redoIdxStack.pop();
		Utility::showToUser(Calendar::MESSAGE_REDO_CAN);
	}
	else {
		Utility::showToUser(Calendar::MESSAGE_REDO_CANNOT);
	}
}

void Calendar::undoCommand() {
	if(!undoTaskStack.empty() && !undoIdxStack.empty()) {
		Task undoTask = undoTaskStack.top();
		int posTask = undoIdxStack.top();
		redoTaskStack.push(taskCollection.at(posTask));
		redoIdxStack.push(posTask);
		replaceTask(undoTask, posTask);
		undoTaskStack.pop();
		undoIdxStack.pop();
		Utility::showToUser(Calendar::MESSAGE_UNDO_CAN);
	}
	else {
		Utility::showToUser(Calendar::MESSAGE_UNDO_CANNOT);
	}
}

//@author A0121007A
void Calendar::save(string calendar) {
	Storage::save(calendar, taskCollection);
}

//@author A0121007A
void Calendar::load(string calendar) {
	Storage::load(calendar, this);
}

//@author A0121007A
void Calendar::help() {
	Utility::showToUser(Calendar::HELP_INTRO);
	for (int i = HELP::HELP::FIRSTCOMMAND + 1; i < HELP::HELP::LASTCOMMAND; i++) {
		string command = Utility::getHelp(i);
		string display = to_string(i) + ". " + command;
		Utility::showToUser(display);
	}
	Utility::showToUser(Calendar::HELP_HOW_TO);
}

//@author A0121007A
void Calendar::help(string command) {
	Utility::getHelpForCommand(command);
}