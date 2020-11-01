set (SOURCES_UT
  VotesGathererUT.cpp
  DatabaseUT.cpp
  ../src/VotesGatherer.cpp
  ../src/VotingBooth.cpp
  ../src/Database.cpp
  ../src/sqlite3.c
)

add_executable(uts ${SOURCES_UT})
include_directories(../ifc)

target_include_directories(uts PRIVATE ../inc)
target_link_libraries(uts gtest_main zmq zmqpp dl)

set_target_properties( uts
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)


add_test(
  NAME
    ut
  COMMAND
     env GTEST_COLOR=1 ${CMAKE_BINARY_DIR}/bin/uts
  )
