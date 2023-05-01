#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "TaskData.h"

using namespace std;

class ToDoView
{
public:
	ToDoView()
	{
	}

	void render(string, bool clear = false);
	void render(vector<TaskData> tasks, bool clear = false);
};