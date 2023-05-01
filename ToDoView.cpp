#include "ToDoView.h"

void ToDoView::render(string text, bool clear)
{
	if (clear) 
		system("cls");

	cout << text << endl;
}

void ToDoView::render(vector<TaskData> tasks, bool clear)
{
	cout << setw(40) << "\n----------------------------------------------------------------\n";
	cout << setw(40) << "Current Tasks\n";
	cout << setw(40) << "----------------------------------------------------------------\n";


	cout << setw(4) << "ID";
	cout << setw(40) << "TASK";
	cout << setw(10) << "CLOSED";
	cout << setw(40) << "\n----------------------------------------------------------------\n";

	for (auto it = tasks.begin(); it != tasks.end(); ++it)
	{
		cout << setw(4) << it->Id;
		cout << setw(40) << it->Task;
		cout << setw(10) << (it->Closed ? "TRUE" : "FALSE");
		cout << endl;
	}

	cout << setw(40) << "\n----------------------------------------------------------------\n";

}
