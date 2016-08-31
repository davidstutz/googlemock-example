cmake_minimum_required (VERSION 2.8)
project (googlemock_example)

include_directories(../ ../vendor/googletest/googletest/include ../vendor/googletest/googlemock/include)
add_executable(order order.cpp)
target_link_libraries(order gmock gtest)
