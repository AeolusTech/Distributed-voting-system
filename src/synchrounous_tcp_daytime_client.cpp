#include "VotingBooth.hpp"

#include <memory>

int main()
{
  std::unique_ptr<IVotingBooth> booth = std::make_unique<VotingBooth>();

  booth->SendResultsToVoteGatherer();
}