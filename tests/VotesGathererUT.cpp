#include "Config.hpp"
#include "VotesGatherer.hpp"
#include "VotingBooth.hpp"

#include <gtest/gtest.h>
#include <chrono>
#include <memory>
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
    thread_booth.join();
    thread_gatherer.join();
  }

  VotingBooth booth;
  VotesGatherer gatherer;
  std::thread thread_booth{ &VotingBooth::Run, &booth };
  std::thread thread_gatherer{ &VotesGatherer::Run, &gatherer };

private:
  // std::cref() could be used to avoid copy
  // std::future<void> future_booth = std::async(std::launch::async, &VotingBooth::Run, std::move(booth));
  // std::future<void> future_gatherer = std::async(std::launch::async, &VotesGatherer::Run, std::move(gatherer));
};

TEST_F(VotingTest, no_votes)
{
  std::this_thread::sleep_for(config::DELAY_CHECK / 2);
  booth.Stop();
  gatherer.Stop();
  EXPECT_EQ(0, gatherer.GetResults());
}

TEST_F(VotingTest, votes_success)
{
  booth.Vote();
  std::this_thread::sleep_for(std::chrono::milliseconds(config::DELAY_CHECK * 2));
  booth.Stop();
  gatherer.Stop();
  EXPECT_EQ(1, gatherer.GetResults());
}