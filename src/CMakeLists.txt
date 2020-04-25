add_executable(boost_asio_example boost_example.cpp)
target_link_libraries(boost_asio_example pthread)


add_executable(main VotesGatherer.cpp main.cpp)
target_include_directories(main PRIVATE ../inc)
set_target_properties( main
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)