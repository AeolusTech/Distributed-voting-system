#include "VotesGatherer.hpp"
#include "Config.hpp"

#include <iostream>
#include <chrono>
#include <thread>

VotesGatherer::VotesGatherer()
{
  const std::string endpoint{ std::string("tcp://*:") + std::to_string(config::PORT_NO) };
  socket.bind(endpoint);
}

void VotesGatherer::Run()
{
  while (run)
  {
    Collect();
  }
}

void VotesGatherer::Stop()
{
  run = false;
}

void VotesGatherer::Collect()
{
  zmqpp::message message;
  socket.receive(message);
  message >> votes_no;

  std::this_thread::sleep_for(config::DELAY_CHECK);
  std::cout << "Received votes. Count: " << votes_no << "\n";
  socket.send(std::to_string(votes_no));
}

int VotesGatherer::GetResults() const
{
  return votes_no;
}

void VotesGatherer::Save()
{
}