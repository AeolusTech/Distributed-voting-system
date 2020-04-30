#include "VotingBooth.hpp"
#include "Config.hpp"

#include <iostream>

VotingBooth::VotingBooth()
{
  std::cout << "Connecting to hello world server…\n";
  const std::string endpoint{ std::string("tcp://localhost:") + std::to_string(config::PORT_NO) };
  socket.connect(endpoint);
}

void VotingBooth::Vote()
{
  votes++;
}

void VotingBooth::Run()
{
  while (run)
  {
    SendResultsToVoteGatherer();
  }
}

void VotingBooth::Stop()
{
  run = false;
}

void VotingBooth::SendResultsToVoteGatherer()
{
  std::cout << "Sending vote no: " << votes << "…\n";
  zmqpp::message message;
  message << votes;
  socket.send(message);
  std::string response;
  socket.receive(response);

  std::cout << "Received " << response << "\n";
}
