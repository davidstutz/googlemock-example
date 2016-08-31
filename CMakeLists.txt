cmake_minimum_required (VERSION 2.8)
project (googlemock_example)

set(CMAKE_CXX_FLAGS  "-Wall -Wno-sign-compare -g -std=c++0x -O4")

add_subdirectory(vendor/googletest)
add_subdirectory(tests)
