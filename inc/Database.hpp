#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>

extern "C" {
#include "sqlite3.h"
}
class Database final
{
public:
  explicit Database(const std::string& filename);
  ~Database();
  void SaveVote();
  std::string ReadVotes();

private:
  void CreateTable();
  bool TableAlreadyCreated();

  sqlite3* m_pDb;
  std::string m_filename;
  unsigned uniqueID;
  std::string m_errorString;
};

#endif