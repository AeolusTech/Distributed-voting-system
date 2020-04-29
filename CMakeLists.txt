cmake_minimum_required(VERSION 3.10)
project (DistributedVotingSystem
		 VERSION 0.1
		 LANGUAGES CXX
        )
set(CMAKE_CXX_STANDARD 17) # C++17 has to be used because of Github Actions (Ubuntu 18.04)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

#those lines should be removed and travs.yml shall be used
include(cmake/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
    )

add_subdirectory (src)

# enable_testing()

# add_subdirectory (tests)# EXCLUDE_FROM_ALL)
