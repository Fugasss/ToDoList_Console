#include "ToDo.h"

void ToDo::Run()
{
	bool close = false;
	string command;
	string buffer;

	while (!close)
	{
		help(false);
		show(false);

		cin >> command;

		trim(command);

		if (command == _commands[0])
		{
			_view.render("Enter task to save");

			getline(cin, buffer);
			add(buffer);
		}
		else if (command == _commands[1])
		{
			_view.render("Enter task number to remove");

			int id = 0;
			cin >> id;

			remove(id);
		}
		else if (command == _commands[2])
		{
			_view.render("Enter task number to mark as completed");

			int id = 0;
			cin >> id;

			complete(id);
		}
		else if (command == _commands[3])
		{
			close = true;
		}
	}
}

void ToDo::help(bool clear)
{
	_view.render("~~~Allowed Commands~~~", clear);

	int i = 0;
	for (auto it = _commands.begin(); it != _commands.end(); ++it, ++i)
	{
		_view.render(" " + (*it));
	}
}

void ToDo::show(bool clear)
{
	vector<TaskData> data{};
	_dbProvider.loadAll(&data);

	_view.render(data, clear);
}

void ToDo::complete(int taskNumber)
{
	_dbProvider.complete(taskNumber);
}

void ToDo::add(string task)
{

	_dbProvider.save(task);
}

void ToDo::remove(int taskNumber)
{
	_dbProvider.remove(taskNumber);
}