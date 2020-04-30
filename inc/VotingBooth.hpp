#ifndef VOTING_BOOTH_HPP
#define VOTING_BOOTH_HPP

#include "../ifc/IVotingBooth.hpp"

#include <string>
#include <zmqpp/zmqpp.hpp>

class VotingBooth final : public IVotingBooth
{
public:
  VotingBooth() = default;
  VotingBooth(const VotingBooth&) = delete;
  VotingBooth(VotingBooth&&) = default;
  VotingBooth& operator=(const VotingBooth&) = delete;
  VotingBooth& operator=(VotingBooth&&) = default;
  ~VotingBooth() = default;

  void Vote() override;
  void Run() override;
  void Stop() override;
  void SendResultsToVoteGatherer() override;

private:
  zmqpp::context context;
  zmqpp::socket_type type{ zmqpp::socket_type::req };
  zmqpp::socket socket{ context, type };
  int votes{ 0 };
  bool run{ true };
};

#endif