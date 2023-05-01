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
		const char* sql =	"CREATE TABLE IF NOT EXISTS TASKS ("\
							"ID	INTEGER NOT NULL UNIQUE," \
							"TASK	TEXT NOT NULL, "\
							"ISCLOSED	NUMBER(1) NOT NULL,"\
							"PRIMARY KEY('ID' AUTOINCREMENT)"\
							");";

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
	void complete(int id);
	void loadAll(vector<TaskData>*);

private:
	sqlite3* _db;
};