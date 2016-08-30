cmake_minimum_required (VERSION 2.8)
project (sparse_coding)

include_directories(../ ../vencor/googletest/googletest/include ../vencor/googletest/googlemock/include)
add_executable(order order.cpp)
target_link_libraries(order gmock gtest)
