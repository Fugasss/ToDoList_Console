#include "DbProvider.h"

void DbProvider::save(string str)
{
	sqlite3_open("tasks.db", &_db);

	const char* sql= "INSERT INTO TASKS(TASK, ISCLOSED) VALUES(?, ?);";

	sqlite3_stmt* stmt;
	int result = sqlite3_prepare_v2(_db, sql, -1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, str.c_str(), str.length(), SQLITE_TRANSIENT);
	sqlite3_bind_int(stmt, 2, 0);
	
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

	if (result != SQLITE_OK)
		cout << "ERROR: " << sqlite3_errmsg(_db) << "\n";

	sqlite3_close(_db);
}

void DbProvider::remove(int id)
{
	sqlite3_open("tasks.db", &_db);


	string str;
	stringstream ss(str);
	ss << "DELETE FROM TASKS WHERE ROWID=?;";
	const char* sql = str.c_str();

	sqlite3_stmt* stmt;
	int result = sqlite3_prepare_v2(_db, sql, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 1, id);
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);

	if (result != SQLITE_OK)
		cout << "ERROR: " << sqlite3_errmsg(_db) << "\n";

	sqlite3_close(_db);

}

void DbProvider::loadAll(vector<TaskData>* datas)
{
	sqlite3_open("tasks.db", &_db);

	const char* sql = "SELECT ROWID, TASK, ISCLOSED FROM TASKS;";
	sqlite3_stmt* stmt;

	int result = sqlite3_prepare_v2(_db, sql, -1, &stmt, NULL);

	while (result = (sqlite3_step(stmt) == SQLITE_ROW))
	{
		TaskData data
		{
			sqlite3_column_int(stmt, 0),
			string((const char*)sqlite3_column_text(stmt, 1)),
			(bool)sqlite3_column_int(stmt, 2)
		};

		datas->push_back(data);
	}
	sqlite3_finalize(stmt);

	if (result != SQLITE_OK)
		cout << "ERROR: " << sqlite3_errmsg(_db) << "\n";

	sqlite3_close(_db);

}

void DbProvider::load(int id, TaskData* data)
{
	sqlite3_open("tasks.db", &_db);


	const char* sql =   "SELECT TASK, ISCLOSED FROM TASKS WHERE ID=?;";

	vector<TaskData> datas{};

	sqlite3_stmt* stmt;

	int result = sqlite3_prepare_v2(_db, sql, -1, &stmt, NULL);
	sqlite3_bind_int(stmt, 0, id);
	sqlite3_step(stmt);

	if (result != SQLITE_OK)
		cout << "ERROR: " << sqlite3_errmsg(_db) << "\n";

	*data = TaskData
	{
		id,
		string((const char*)sqlite3_column_text(stmt, 0)),
		(bool)sqlite3_column_int(stmt, 1)
	};

	sqlite3_finalize(stmt);
	sqlite3_close(_db);

}
