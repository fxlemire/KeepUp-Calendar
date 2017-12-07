//@author A0121007A
/*
One of the core classes of KeepUp. The calendar allows for task storage (until saved by storage)
and all command executions. It creates more enumerations for correct interaction with some specific classes
which can be useful for commandParser class, KeepUpLib and Utility.
*/
#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include <stack>
#include <stdio.h>
#include <string>
#include "Task.h"
#include <algorithm>  

using namespace std;

//@author A0121007A
/* enumeration used for the help command */
namespace HELP {
	//DEL is DELETE (seems to be reserved keyword by windows)
	enum HELP {
		FIRSTCOMMAND, ADD, BLOCK, DECORATE, DEL, DONE, EDIT, EXIT, LOAD, PRINT,
		REDO, REMIND, REPEAT, SAVE, UNDO, VIEW, WEATHER, LASTCOMMAND
	};
}

//@author A0121007A
/* enumeration used for specific date-only manipulations */
namespace DATE_ENUM {
	enum DATE_ENUM {
		STARTYEAR, STARTMONTH, STARTDAY, STARTHOUR, STARTMINUTE, ENDYEAR,
		ENDMONTH, ENDDAY, ENDHOUR, ENDMINUTE, ISDONE, HASDATE, HASEXPIRED, LASTPOSITION
	};
}

//@author A0121007A
/* enumeration used for edit command */
namespace EDIT {
	enum EDIT {
		COMMAND, PARAM, SEARCH_KEYWORDS, STARTYEAR, STARTMONTH, STARTDAY, STARTHOUR,
		STARTMINUTE, ENDYEAR, ENDMONTH, ENDDAY, ENDHOUR, ENDMINUTE, PRIORITY,
		NAME, DESCRIPTION, LOCATION, ISDONE, HASEXPIRED, HASDATE, LASTPOSITION
	};
}

//@author A0121007A
/* enumeration used for the choices inside edit */
namespace EDIT_TYPE {
	enum EDIT_TYPE {
		TITLE=1, DATETIME, LOCATION, REMINDER, DESCRIPTION, PRIORITY, ATTACHFILE,
		EVERYTHING
	};
}

//@author A0121007A
/* remind not implemented yet */
namespace REMIND {
	enum REMIND { COMMAND, SEARCH_KEYWORDS, YEAR, MONTH, DAY, HOUR, MINUTE, FREQUENCY };
}

//@author A0121007A
/* repeat not implemented yet */
namespace REPEAT {
	enum REPEAT { COMMAND, SEARCH_KEYWORDS, FREQUENCY };
}

/* frequency not implemented yet */
//namespace FREQUENCY {
//	enum FREQUENCY { DAILY, WEEKLY, MONTHLY, ANNUALLY };
//}

class Calendar {
public:
	//@author A0121007A
	/* constructor */
	Calendar();

	//@author A0121007A
	/* default name of calendar to be saved */
	static const string DEFAULT_NAME;

	//@author A0121007A
	/* commands keywords */
	static const string COMMAND_ADD;
	static const string COMMAND_BLOCK;
	static const string COMMAND_DECORATE;
	static const string COMMAND_DELETE;
	static const string COMMAND_DONE;
	static const string COMMAND_EDIT;
	static const string COMMAND_EXIT;
	static const string COMMAND_HELP;
	static const string COMMAND_SAVE;
	static const string COMMAND_LOAD;
	static const string COMMAND_PRINT;
	static const string COMMAND_REMIND;
	static const string COMMAND_REPEAT;
	static const string COMMAND_VIEW;
	static const string COMMAND_VIEW_DONE;
	static const string COMMAND_VIEW_DEL;
	static const string COMMAND_WEATHER;
	static const string COMMAND_INVALID;
	static const string COMMAND_UNDO;
	static const string COMMAND_REDO;

	//@author A0121007A
	/* help messages */
	static const string HELP_INTRO;
	static const string HELP_HOW_TO;
	static const string HELP_ADD_1;
	static const string HELP_ADD_2;
	static const string HELP_ADD_3;
	static const string HELP_ADD_4;
	static const string HELP_ADD_5;
	static const string HELP_ADD_6;
	static const string HELP_ADD_7;
	static const string HELP_ADD_8;
	static const string HELP_ADD_9;
	static const string HELP_ADD_10;
	static const string HELP_ADD_11;
	static const string HELP_BLOCK;
	static const string HELP_DECORATE;
	static const string HELP_DELETE_1;
	static const string HELP_DELETE_2;
	static const string HELP_DONE_1;
	static const string HELP_DONE_2;
	static const string HELP_EDIT_1;
	static const string HELP_EDIT_2;
	static const string HELP_EDIT_3;
	static const string HELP_EXIT;
	static const string HELP_LOAD;
	static const string HELP_PRINT;
	static const string HELP_REDO;
	static const string HELP_REMIND;
	static const string HELP_REPEAT;
	static const string HELP_SAVE_1;
	static const string HELP_SAVE_2;
	static const string HELP_UNDO;
	static const string HELP_VIEW_1;
	static const string HELP_VIEW_2;
	static const string HELP_VIEW_3;
	static const string HELP_VIEW_4;
	static const string HELP_WEATHER;

	//@author A0121007A
	/* config */
	static const int TASK_NOT_FOUND;
	static const string TASK_DELETED;
	static const string TASK_DONE;
	static const string ESCAPE_CHAR;
	static const int GO_BACK_OPTION;

	//@author A0121007A
	/* MESSAGES */
	//static const string MESSAGE_PROMPT_SEARCH_TERM;
	/* miscellaneous */
	static const string Calendar::GO_BACK;
	static const string Calendar::MESSAGE_INVALID_CHOICE;
	static const string MESSAGE_PROMPT_TASK_CHOICE_WITHIN_RESULTS;
	static const string Calendar::MESSAGE_NOT_YET_IMPLEMENTED;

	//@author A0121007A
	/* edit */
	static const string Calendar::MESSAGE_EDIT_NOT_EDITED;
	static const string Calendar::MESSAGE_EDIT_EDITED;
	static const string Calendar::MESSAGE_EDIT_CHOICE_INTRO;
	static const string Calendar::MESSAGE_EDIT_CHOICE_TITLE;
	static const string Calendar::MESSAGE_EDIT_CHOICE_DATE_TIME;
	static const string Calendar::MESSAGE_EDIT_CHOICE_LOCATION;
	static const string Calendar::MESSAGE_EDIT_CHOICE_REMINDER;
	static const string Calendar::MESSAGE_EDIT_CHOICE_DESCRIPTION;
	static const string Calendar::MESSAGE_EDIT_CHOICE_PRIORITY;
	static const string Calendar::MESSAGE_EDIT_CHOICE_ATTACH;
	static const string Calendar::MESSAGE_EDIT_CHOICE_EVERYTHING;
	static const string Calendar::MESSAGE_EDIT_CHOICE_GO_BACK;
	static const string Calendar::MESSAGE_EDIT_NEW_TITLE;
	static const string Calendar::MESSAGE_EDIT_NEW_DATE_TIME;
	static const string Calendar::MESSAGE_EDIT_NEW_LOCATION;
	static const string Calendar::MESSAGE_EDIT_NEW_REMINDER;
	static const string Calendar::MESSAGE_EDIT_NEW_DESCRIPTION;
	static const string Calendar::MESSAGE_EDIT_NEW_PRIORITY;
	static const string Calendar::MESSAGE_EDIT_NEW_ATTACH;
	static const string Calendar::MESSAGE_EDIT_NEW_EVERYTHING;
	static const string Calendar::MESSAGE_EDIT_CONFIRM_EDIT;
	static const string Calendar::MESSAGE_EDIT_CONFIRM_PRIORITY;

	//@author A0121007A
	/* messages to other commands */
	static const string Calendar::MESSAGE_UNDO_CAN;
	static const string Calendar::MESSAGE_REDO_CAN;
	static const string Calendar::MESSAGE_UNDO_CANNOT;
	static const string Calendar::MESSAGE_REDO_CANNOT;
	static const string Calendar::MESSAGE_VIEW_TIMED_TASK;
	static const string Calendar::MESSAGE_VIEW_DEADLINE_TASK;
	static const string Calendar::MESSAGE_VIEW_FLOATING_TASK;
	static const string Calendar::MESSAGE_VIEW_SEPARATOR;
	static const string Calendar::MESSAGE_VIEW_DONE_TASK;
	static const string Calendar::MESSAGE_VIEW_DEL_TASK;
	static const string Calendar::MESSAGE_VIEW_ALL_TASK;

	//@author A0121007A
	/* enum for calendar command interaction */
	enum COMMAND_TYPE {
		EXIT, TASKADD, TASKBLOCK, TASKDECORATE, TASKDELETE, TASKDONE, TASKEDIT,
		HELP, SAVE, LOAD, TASKPRINT, TASKREMIND, TASKREPEAT, TASKVIEW, TASKUNDO,
		TASKREDO, TASKWEATHER, TASKINVALID
	};

	//@author A0121007A
	/* variables */
	vector<string> searchResultsForDisplay; //public for testing matters
	/* serves as a storage to smartly print edit choices */
	static vector<string> editChoices;

	//@author A0121007A
	/* methods */
	bool isFound(int task);
	bool isValidDateTimeEdit(vector<string> dateAndTime);
	int taskSearch(string searchTerm);
	string getSearchTerm();
	Task processEdit(Task toEdit, int editType);
	void taskAdd(Task newTask);
	void taskDelete(int posTask);
	void taskEdit(int posTask);
	void help();
	void help(string command);
	void taskDisplayAll();
	void taskDisplayDone();
	void taskDisplayDeleted();
	void taskSortAll(Task currTask);
	void taskView(string param);
	void taskDone(int posTask);
	void getSearchResults(string searchTerm);
	void displayBackOption();
	void displaySearchResults();
	void undoCommand();
	void redoCommand();
	void save(string calendar);
	void load(string calendar);
	void formatResultsForDisplay(); //public for testing matters

private:
	//@author A0121007A
	/* variables */
	vector<Task> taskCollection; //task storage
	vector<int> searchResults;
	stack<Task> undoTaskStack;
	stack<Task> redoTaskStack;
	stack<int> undoIdxStack;
	stack<int> redoIdxStack;
	vector<Task> timedTask;
	vector<Task> deadlineTask;
	vector<Task> floatingTask;

	//@author A0121007A
	/* calendar private helper methods */
	string getUserPriority();
	void Calendar::editTaskPrompt();
	void initializeEditChoices();
	int pickResult();
	void Calendar::moveToUndo(int posTask);
	void Calendar::moveToUndo(Task currTask);
	void Calendar::replaceTask(Task newTask, int posTask);

	void Calendar::editTaskExecute(Task editedTask);

};

#endif