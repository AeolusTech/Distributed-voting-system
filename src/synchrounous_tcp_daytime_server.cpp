#include "VotesGatherer.hpp"

#include <memory>

int main()
{
  std::unique_ptr<IVotesGatherer> gatherer = std::make_unique<VotesGatherer>();

  gatherer->Collect();
}