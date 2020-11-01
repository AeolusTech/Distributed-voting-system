#include "Config.hpp"

#define private public
#include "Database.hpp"
#undef private

#include <gtest/gtest.h>
#include <cstdio>

using ::testing::Test;

class DatabaseTest : public Test
{
public:
  DatabaseTest() : db(PATH_OK)
  {
  }

  ~DatabaseTest() override
  {
    removeFile(PATH_OK);
  }

  void removeFile(const std::string& filepath)
  {
    remove(filepath.c_str());
  }

  Database db;
  constexpr static const auto PATH_OK = "./db.sqlite";
};

TEST_F(DatabaseTest, ConstructionTestInvalidPath)
{
  constexpr const auto PATH_INVALID = "/root/invalid/db.sqlite";
  ASSERT_ANY_THROW(Database invalid_db(PATH_INVALID););
}

TEST_F(DatabaseTest, TableShallBeCreatedInTheConstructor)
{
  constexpr auto PATH_OK2 = "./db2.sqlite";

  Database db2(PATH_OK2);
  EXPECT_TRUE(db2.TableAlreadyCreated());

  removeFile(PATH_OK2);
}

TEST_F(DatabaseTest, SaveTest)
{
  EXPECT_NO_THROW(db.SaveVote());
}

TEST_F(DatabaseTest, DoubleSaveTest)
{
  EXPECT_NO_THROW({
    db.SaveVote();
    db.SaveVote();
  });
}