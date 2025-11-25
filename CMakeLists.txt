cmake_minimum_required(VERSION 3.16)
project(RSNetClient VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Threads REQUIRED)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/src
)

set(CORE_SOURCES
        src/core/node.cpp
        src/core/peer_manager.cpp
        src/network/tcp_transport.cpp
)

set(GUI_SOURCES
        src/main_gui.cpp
        src/gui/main_window.cpp
        src/gui/main_window.h
        src/gui/node_bridge.h
)

add_executable(rsnet_gui ${CORE_SOURCES} ${GUI_SOURCES})

target_link_libraries(rsnet_gui PRIVATE Qt6::Widgets Threads::Threads)

if(WIN32)
    target_link_libraries(rsnet_gui PRIVATE ws2_32)
endif()

install(TARGETS rsnet_gui DESTINATION bin)

set(CPACK_PACKAGE_NAME "rsnet-client")
set(CPACK_PACKAGE_VENDOR "Clicedvly768")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "P2P Client for RSNet")
set(CPACK_PACKAGE_VERSION "0.1.0")
set(CPACK_PACKAGE_CONTACT "harepro29@gmail.com")
set(CPACK_LICENSE_FILE "${CMAKE_SOURCE_DIR}/CMakeLists.txt")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Clicedvly768 <harepro29@gmail.com>")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

set(CPACK_RPM_PACKAGE_LICENSE "MIT")
set(CPACK_RPM_PACKAGE_GROUP "Applications/Internet")

include(CPack)