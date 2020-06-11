#include "Database.hpp"
#include <stdexcept>

Database::Database(const std::string& filename) : m_filename(filename)
{
  if (sqlite3_open(m_filename.c_str(), &m_pDb))
  {
    std::string errorMessage = "Could not open database";
    errorMessage.append(sqlite3_errmsg(m_pDb));
    throw std::runtime_error(errorMessage);
  }
}

Database::~Database()
{
  sqlite3_close(m_pDb);
}

void Database::SaveVote()
{
}