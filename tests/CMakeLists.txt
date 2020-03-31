find_package(GTest REQUIRED)
# include(GoogleTest)

add_executable(VotesGathererUT VotesGathererUT.cpp)
target_include_directories(VotesGathererUT PRIVATE ../inc)
target_link_libraries(VotesGathererUT GTest::GTest gtest_main)


add_test(ut VotesGathererUT)
#
# add_custom_target(
#   check
#   COMMAND $COMMAND env CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND}
#   DEPENDS ut)
#
# # TODO: make output colorful and output_on_failure
# # I cannot believe they make it that hard to find
#
# # add_custom_target(check
# #   COMMAND env CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND}
# #   DEPENDS ut)
