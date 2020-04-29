#include "VotingBooth.hpp"

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void VotingBooth::Vote()
{
}

void VotingBooth::Run()
{
}

void VotingBooth::SendResultsToVoteGatherer()
{
  try
  {
    boost::asio::io_context io_context;

    tcp::resolver resolver(io_context);
    tcp::resolver::results_type endpoints = resolver.resolve("", "daytime");

    tcp::socket socket(io_context);
    boost::asio::connect(socket, endpoints);

    while (true)
    {
      boost::array<char, 128> buf;
      boost::system::error_code error;

      size_t len = socket.read_some(boost::asio::buffer(buf), error);

      if (error == boost::asio::error::eof)
        break;  // Connection closed cleanly by peer.
      else if (error)
        throw boost::system::system_error(error);  // Some other error.

      std::cout.write(buf.data(), len);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }
}