#include "VotesGatherer.hpp"
#include "VotingBooth.hpp"

#include <gtest/gtest.h>
#include <chrono>
#include <future>
#include <thread>

using ::testing::Test;

class VotingTest : public Test
{
public:
  void SetUp() override
  {
  }

  void TearDown() override
  {
    future_booth.wait();
    future_gatherer.wait();
  }
  VotingBooth booth;
  VotesGatherer gatherer;

private:
  // std::cref() could be used to avoid copy
  std::future<void> future_booth = std::async(std::launch::async, &VotingBooth::Run, std::move(booth));
  std::future<void> future_gatherer = std::async(std::launch::async, &VotesGatherer::Run, std::move(gatherer));
};

TEST_F(VotingTest, no_votes)
{
  booth.Stop();
  gatherer.Stop();
  EXPECT_EQ(0, gatherer.GetResults());
}

TEST_F(VotingTest, votes_success)
{
  booth.Vote();
  std::this_thread::sleep_for(std::chrono::milliseconds(20));
  booth.Stop();
  gatherer.Stop();
  EXPECT_EQ(1, gatherer.GetResults());
}
