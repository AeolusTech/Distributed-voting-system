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


target_include_directories(uts
  PRIVATE
  ../inc
  ${CONAN_INCLUDE_DIRS_GTEST}
  ${CONAN_INCLUDE_DIRS_CPPZMQ}
  ${CONAN_INCLUDE_DIRS_ZMQ}
  )

target_link_libraries(uts
  ${CONAN_LIB_DIRS_GTEST}/libgtestd.a
  ${CONAN_LIB_DIRS_GTEST}/libgtest_maind.a
  ${CONAN_LIB_DIRS_CPPZMQ}
  ${ZMQ_LIB}
  ${SODIUM_LIB}
  pthread
  dl)

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
