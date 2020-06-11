#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <chrono>

using std::literals::chrono_literals::operator""ms;

namespace config
{
const int PORT_NO = 5555;
const auto DELAY_CHECK = 200ms;
}  // namespace config

#endif