#pragma once
#include <string>

using std::string;

struct TaskData
{
public:
	TaskData(int id, string task, bool closed) : Id(id), Task(task), Closed(closed)
	{}

	int Id;
	string Task;
	bool Closed;
};