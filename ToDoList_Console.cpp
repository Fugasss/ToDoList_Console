#include <iostream>
#include "ToDo.h"
#include "ToDoView.h"
#include "DbProvider.h"

int main()
{
	setlocale(LC_ALL, "");

	DbProvider dbProvider = DbProvider();
	ToDoView view = ToDoView();
	ToDo todo = ToDo(&view, &dbProvider);

	todo.Run();
}