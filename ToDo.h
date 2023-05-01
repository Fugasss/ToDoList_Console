#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ToDoView.h"
#include "plugins/sqlite3/sqlite3.h"
#include "DbProvider.h"

using namespace std;

class ToDo
{
public:
	ToDo(ToDoView* view, DbProvider* dbProvider) : _view(*view), _dbProvider(*dbProvider)
	{
	}

	void Run();

	vector<string> getCommands() { return _commands; }

private:
	ToDoView _view;
	DbProvider _dbProvider;

	const vector<string> _commands =
	{
		"help",
		"add",
		"remove",
		"show",
		"close"
	};

	void help();
	void show();
	void add(string task);
	void remove(int taskNumber);

};