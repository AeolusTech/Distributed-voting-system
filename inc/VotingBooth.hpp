#ifndef VOTING_BOOTH_HPP
#define VOTING_BOOTH_HPP

#include "../ifc/IVotingBooth.hpp"

#include <string>
#include <zmq.hpp>

class VotingBooth final : public IVotingBooth
{
public:
  VotingBooth();
  VotingBooth(const VotingBooth &) = delete;
  VotingBooth(VotingBooth &&) = default;
  VotingBooth &operator=(const VotingBooth &) = delete;
  VotingBooth &operator=(VotingBooth &&) = default;
  ~VotingBooth() = default;

  void Vote() override;
  void Run() override;
  void Stop() override;
  void SendResultsToVoteGatherer() override;

private:
  zmq::context_t context;
  zmq::socket_t socket{ context, ZMQ_REQ };
  int votes{ 0 };
  bool run{ true };
};

#endif