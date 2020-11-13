#ifndef VOTES_GATHERER_HPP
#define VOTES_GATHERER_HPP

#include "../ifc/IVotesGatherer.hpp"

#include <zmq.hpp>
#include <string>

class VotesGatherer final : public IVotesGatherer
{
public:
  VotesGatherer();
  VotesGatherer(const VotesGatherer &) = delete;
  VotesGatherer(VotesGatherer &&) = default;
  VotesGatherer &operator=(const VotesGatherer &) = delete;
  VotesGatherer &operator=(VotesGatherer &&) = default;
  ~VotesGatherer() = default;

  void Run() override;
  void Collect() override;
  void Stop() override;

  int GetResults() const;

private:
  void Save();

  zmq::context_t context;
  zmq::socket_t socket{ context, ZMQ_REP };
  int votes_no{ 0 };
  bool run{ true };
};

#endif