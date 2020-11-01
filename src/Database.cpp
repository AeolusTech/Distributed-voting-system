#include "Database.hpp"
#include <stdexcept>

// Create a callback function
int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
  // Return successful
  return 0;
}

Database::Database(const std::string& filename) : m_filename(filename)
{
  if (sqlite3_open(m_filename.c_str(), &m_pDb))
  {
    std::string errorMessage = "Could not open database";
    errorMessage.append(sqlite3_errmsg(m_pDb));
    throw std::runtime_error(errorMessage);
  }
  else
  {
    if (!TableAlreadyCreated())
    {
      CreateTable();
    }
  }
}

Database::~Database()
{
  sqlite3_close(m_pDb);
}

void Database::SaveVote()
{
}

bool Database::CreateTable()
{
  std::string sql_command = "CREATE TABLE PEOPLE ("
                            "ID INT PRIMARY KEY     NOT NULL,"
                            "NAME           TEXT    NOT NULL);";

  std::string zErrMsg;
  auto error_buffer = zErrMsg.data();

  int rc = sqlite3_exec(m_pDb, sql_command.c_str(), nullptr, 0, &error_buffer);

  if (rc != 0)
  {
    throw std::runtime_error(zErrMsg);
  }
}

bool Database::TableAlreadyCreated()
{
  std::string sql_command = "SELECT * FROM PEOPLE";

  std::string zErrMsg;
  auto error_buffer = zErrMsg.data();

  sqlite3_open(m_filename.c_str(), &m_pDb);
  int rc = sqlite3_exec(m_pDb, sql_command.c_str(), nullptr, 0, &error_buffer);

  return (rc != 0) ? false : true;
}