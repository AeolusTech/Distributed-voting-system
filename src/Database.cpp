#include "Database.hpp"
#include "Config.hpp"
#include <stdexcept>

// Create a callback function
int callback(void* NotUsed, int argc, char** argv, char** azColName)
{
  // Return successful
  return 0;
}

Database::Database(const std::string& filename) : m_filename(filename), uniqueID(0)
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
  const std::string name = "john";
  const int voteNo = 1;
  std::string sql_command = "INSERT INTO " + config::VOTES_TABLE_NAME + " VALUES (" +
                            std::to_string(uniqueID) + ", \"" + name + "\", " +
                            std::to_string(voteNo) + ");";

  char* errorBuffer = m_errorString.data();
  int rc = sqlite3_exec(m_pDb, sql_command.c_str(), nullptr, 0, &errorBuffer);

  if (rc != 0)
  {
    throw std::runtime_error(m_errorString);
  }
  uniqueID++;
}

void Database::CreateTable()
{
  std::string sql_command = "CREATE TABLE " + config::VOTES_TABLE_NAME +
                            "(ID INT PRIMARY KEY     NOT NULL,"
                            "NAME           VARCHAR(20)    NOT NULL,"
                            "VOTE           INT    NOT NULL);";

  std::string zErrMsg;
  auto error_buffer = zErrMsg.data();

  char* errorBuffer = m_errorString.data();
  int rc = sqlite3_exec(m_pDb, sql_command.c_str(), nullptr, 0, &errorBuffer);

  if (rc != 0)
  {
    throw std::runtime_error(m_errorString);
  }
}

bool Database::TableAlreadyCreated()
{
  std::string sql_command = "SELECT * FROM " + config::VOTES_TABLE_NAME + ";";

  std::string zErrMsg;
  auto error_buffer = zErrMsg.data();

  char* errorBuffer = m_errorString.data();
  int rc = sqlite3_exec(m_pDb, sql_command.c_str(), nullptr, 0, &errorBuffer);

  return (rc != 0) ? false : true;
}