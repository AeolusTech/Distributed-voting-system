
add_executable(VotesGathererUT VotesGathererUT.cpp ../src/VotesGatherer.cpp ../src/VotingBooth.cpp)
include_directories(../ifc)

target_include_directories(VotesGathererUT PRIVATE ../inc)
target_link_libraries(VotesGathererUT gtest_main zmq zmqpp)

set_target_properties( VotesGathererUT
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)


add_test(
  NAME
    ut
  COMMAND
     env GTEST_COLOR=1 ${CMAKE_BINARY_DIR}/bin/VotesGathererUT
  )
