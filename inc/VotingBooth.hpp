#ifndef VOTING_BOOTH_HPP
#define VOTING_BOOTH_HPP

#include "../ifc/IVotingBooth.hpp"

class VotingBooth final : public IVotingBooth
{
public:
  ~VotingBooth() = default;
  void Vote() override;
  void Run() override;
  void SendResultsToVoteGatherer() override;
};

#endif