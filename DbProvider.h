#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "TaskData.h"
#include "plugins/sqlite3/sqlite3.h"

using namespace std;

class DbProvider
{
public:
	DbProvider()
	{
		int	result = sqlite3_open("tasks.db", &_db);

		if (result != SQLITE_OK)
		{
			fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(_db));
			system("pause");
		}

		//Create SQL DB if not exists
		const char* sql = "CREATE TABLE IF NOT EXISTS TASKS ("\
			"TASK			TEXT						NOT NULL,"\
			"ISCLOSED		NUMBER(1)					NOT NULL);";

		sqlite3_stmt* stmt;
		result = sqlite3_prepare_v2(_db, sql, -1, &stmt, NULL);

		sqlite3_step(stmt);
		sqlite3_finalize(stmt);

		if (result != SQLITE_OK)
			cout << "Err: " << sqlite3_errmsg(_db) << "\n";

		sqlite3_close(_db);
	}

	void save(string str);
	void remove(int id);
	void loadAll(vector<TaskData>*);
	void load(int id, TaskData*);

private:
	sqlite3* _db;

	//static int get_callback(void*, int, char**, char**);
};