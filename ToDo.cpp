#include "ToDo.h"

void ToDo::Run()
{
	_view.render("!Welcome To ToDoList!");
	help();

	bool close = false;
	string command;
	string buffer;

	while (!close)
	{
		getline(cin, command);
		
		if (command == _commands[0]) 
		{
			help();
		}
		else if (command == _commands[1]) 
		{
			_view.render("Enter task to save");

			getline(cin, buffer);
			add(buffer);
		}
		else if(command == _commands[2])
		{
			_view.render("Enter task number to remove");

			int id = 0;
			cin >> id;

			remove(id);
		}
		else if (command == _commands[3])
		{
			show();
		}
		else if (command == _commands[4])
		{
			close = true;
		}
	}
}

void ToDo::help()
{
	_view.render("~~~Allowed Commands~~~");

	int i = 0;
	for (auto it = _commands.begin(); it != _commands.end(); ++it, ++i)
	{
		_view.render("\t" + (*it));
	}
}

void ToDo::show()
{
	vector<TaskData> data{};
	_dbProvider.loadAll(&data);

	_view.render(data);
}

void ToDo::add(string task)
{
	_dbProvider.save(task);
}

void ToDo::remove(int taskNumber)
{
	_dbProvider.remove(taskNumber);
}
