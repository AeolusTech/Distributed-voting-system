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
  while (run) {
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
  std::array<int, 1> arr{ votes };
  zmq::message_t message(arr.data(), arr.size());
  socket.send(message);
  zmq::message_t received_msg;
  socket.recv(received_msg);

  std::cout << "Received " << received_msg.data() << "\n";
}
