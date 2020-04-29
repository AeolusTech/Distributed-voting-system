#ifndef VOTING_BOOTH_HPP
#define VOTING_BOOTH_HPP

#include "../ifc/IVotesGatherer.hpp"

class VotesGatherer final : public IVotesGatherer
{
public:
  ~VotesGatherer() = default;
  void Run() override;
  void Collect() override;
};

#endif