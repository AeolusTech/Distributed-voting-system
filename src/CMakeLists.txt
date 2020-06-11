set (COMMON_LIBS
    zmq
    zmqpp
)

set(SOURCES_BOOTH
    synchrounous_tcp_daytime_client.cpp
    VotingBooth.cpp
)

add_executable(booth ${SOURCES_BOOTH})
target_link_libraries(booth ${COMMON_LIBS})
set_target_properties( booth
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

include_directories(../inc)

set(SOURCES_GATHERER
    synchrounous_tcp_daytime_server.cpp
    VotesGatherer.cpp
    Database.cpp
    sqlite3.c
)

add_executable(gatherer ${SOURCES_GATHERER})
target_link_libraries(gatherer ${COMMON_LIBS} dl)
set_target_properties( gatherer
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
