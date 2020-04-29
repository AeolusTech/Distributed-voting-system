add_executable(booth synchrounous_tcp_daytime_client.cpp VotingBooth.cpp)
target_link_libraries(booth pthread)
# target_include_directories(client
#     PUBLIC ../inc
#     INTERFACE ../ifc
# )
set_target_properties( booth
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

include_directories(../inc)

add_executable(gatherer synchrounous_tcp_daytime_server.cpp VotesGatherer.cpp)
target_link_libraries(gatherer pthread)
# target_include_directories(server
#     PUBLIC ../inc
#     INTERFACE ../ifc
# )
set_target_properties( gatherer
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
