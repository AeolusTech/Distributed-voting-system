#include "Config.hpp"
#include "Database.hpp"

#include <gtest/gtest.h>

using ::testing::Test;

class DatabaseTest : public Test
{
public:
  DatabaseTest() : db(PATH_OK)
  {
  }

  Database db;
  constexpr static const auto PATH_OK = "./db.sqlite";
};

TEST_F(DatabaseTest, ConstructionTest)
{
  constexpr const auto PATH_INVALID = "/root/invalid/db.sqlite";
  ASSERT_ANY_THROW(Database invalid_db(PATH_INVALID););
}

TEST_F(DatabaseTest, SaveTest)
{
  EXPECT_NO_THROW(db.SaveVote());
}