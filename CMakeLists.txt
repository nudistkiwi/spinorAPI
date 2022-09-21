cmake_minimum_required(VERSION 3.1...3.16)
project(API VERSION 1.0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

if (UNIX)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-lboost_system -lboost_thread -lpthread -pthread")
endif (UNIX)

add_subdirectory(library)

find_package(Boost COMPONENTS thread system REQUIRED)
find_package(OpenSSL)
if (WIN32)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif (WIN32)



add_executable(API main.cpp)
target_link_libraries (API ssl-client httpserver_ssl)


