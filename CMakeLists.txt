
cmake_minimum_required(VERSION 2.8)

project(SymphonyOfPewPew CXX)

include(utils.cmake)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -pedantic")

set(sopp_ROOT ${CMAKE_SOURCE_DIR})
add_subdirectory(src)
list(APPEND sopp_SRCS ${src_SRCS})
list(APPEND sopp_LIBS ${src_LIBS})
list(REMOVE_DUPLICATES sopp_SRCS)
list(REMOVE_DUPLICATES sopp_LIBS)

add_executable(sopp ${sopp_SRCS})
target_link_libraries(sopp ${sopp_LIBS})

