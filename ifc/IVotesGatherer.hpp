#ifndef I_VOTES_GATHERER_HPP
#define I_VOTES_GATHERER_HPP

class IVotesGatherer
{
public:
  virtual ~IVotesGatherer() = default;
  virtual void Run() = 0;
  virtual void Collect() = 0;
};

#endif