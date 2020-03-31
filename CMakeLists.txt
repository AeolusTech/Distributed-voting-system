cmake_minimum_required(VERSION 3.10)
project (DistributedVotingSystem
		 VERSION 0.1
		 LANGUAGES CXX
		)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory (src)

enable_testing()

# this shall work fine, but... I don't have time to do that
add_subdirectory (tests)# EXCLUDE_FROM_ALL)
