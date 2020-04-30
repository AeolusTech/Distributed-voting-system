#ifndef I_VOTING_BOOTH_HPP
#define I_VOTING_BOOTH_HPP

class IVotingBooth
{
public:
  virtual ~IVotingBooth() = default;
  virtual void Vote() = 0;
  virtual void Run() = 0;
  virtual void SendResultsToVoteGatherer() = 0;
  virtual void Stop() = 0;
};

#endif