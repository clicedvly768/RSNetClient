cmake_minimum_required(VERSION 3.15)
project(RSNetClient VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

set(SOURCES
        src/cli/main.cpp
        src/core/node.cpp
        src/core/peer_manager.cpp
        src/network/tcp_transport.cpp
)

add_executable(rsnet_cli ${SOURCES})

if(WIN32)
    target_link_libraries(rsnet_cli PRIVATE ws2_32)
    add_compile_definitions(WIN32_LEAN_AND_MEAN)
endif()

find_package(Threads REQUIRED)
target_link_libraries(rsnet_cli PRIVATE Threads::Threads)