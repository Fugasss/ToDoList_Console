#include "ToDoView.h"
#include "StringExtension.h"

void ToDoView::render(string text, bool clear)
{
	if (clear)
		system("cls");

	cout << text << endl;
}

void ToDoView::render(vector<TaskData> tasks, bool clear)
{
	if (clear)
		system("cls");

	const int maxSize = 80;
	const int idSize = 2;
	const int closedSize = 8;
	const string horizontalLine = "\n" + string(maxSize + 1, '-') + "\n";

	cout << setw(maxSize) << horizontalLine;
	cout << "|" << setw(idSize) << "ID" << "|";
	cout << setw(maxSize - closedSize - idSize - 3) << "TASK" << '|';
	cout << setw(closedSize) << "CLOSED" << "|";
	cout << setw(maxSize) << horizontalLine;

	for (auto it = tasks.begin(); it != tasks.end(); ++it)
	{
		cout << "|" << setw(idSize) << it->Id << "|";

		vector<string> splitted;
		splitString(it->Task, maxSize - idSize - closedSize - 2, '|', &splitted);

		cout << setw(maxSize - idSize - closedSize - 2) << *splitted.begin();

		cout << setw(closedSize) << (it->Closed ? "TRUE" : "FALSE") << "|";

		if (splitted.begin() + 1 != splitted.end())
			cout << "\n";

		for (auto it = splitted.begin() + 1; it != splitted.end(); ++it) {
			cout << setw(maxSize - idSize - closedSize + 2) << *it;
			if (it != splitted.end())
				cout << "\n";
		}

		cout << setw(maxSize) << horizontalLine;
	}
}