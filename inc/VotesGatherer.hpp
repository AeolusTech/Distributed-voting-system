#ifndef VOTES_GATHERER_HPP
#define VOTES_GATHERER_HPP

#include "../ifc/IVotesGatherer.hpp"

#include <zmqpp/zmqpp.hpp>
#include <string>

class VotesGatherer final : public IVotesGatherer
{
public:
  VotesGatherer();
  VotesGatherer(const VotesGatherer&) = delete;
  VotesGatherer(VotesGatherer&&) = default;
  VotesGatherer& operator=(const VotesGatherer&) = delete;
  VotesGatherer& operator=(VotesGatherer&&) = default;
  ~VotesGatherer() = default;

  void Run() override;
  void Collect() override;
  void Stop() override;

  int GetResults() const;

private:
  void Save();

  zmqpp::context context;
  zmqpp::socket_type type{ zmqpp::socket_type::reply };
  zmqpp::socket socket{ context, type };
  int votes_no{ 0 };
  bool run{ true };
};

#endif