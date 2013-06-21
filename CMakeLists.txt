
cmake_minimum_required(VERSION 2.8)

project(SymphonyOfPewPew CXX)

include(utils.cmake)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -pedantic")

## Game resources must be copied ##
file(COPY resources/ DESTINATION ${PROJECT_BINARY_DIR}/resources/)

## Options ##
option(POLYCODE_BASE "Set URL for Polycode" OFF)

## Gathering sources and libraries ##
set(sopp_ROOT ${CMAKE_SOURCE_DIR})
add_subdirectory(src)
list(APPEND sopp_SRCS ${src_SRCS})
list(APPEND sopp_LIBS ${src_LIBS})
list(REMOVE_DUPLICATES sopp_SRCS)
list(REMOVE_DUPLICATES sopp_LIBS)

## Localizing Polycode is vital ##
if (NOT POLYCODE_BASE)
	message (FATAL_ERROR
		"This project depends on Polycode\n"
		"Run cmake with -DPOLYCODE_BASE=<URL> to specify location\n"
		"Please specify the location of Polycode Core\n"
		"Should look like Polycode/Release/<platftorm>/Framework/"
	)
endif ()

## Including headers (-I) ##
include_directories("${POLYCODE_BASE}Core/include")
include_directories("${POLYCODE_BASE}Core/Dependencies/include")
include_directories("${POLYCODE_BASE}Core/Dependencies/include/AL")
include_directories("${POLYCODE_BASE}Modules/include")
include_directories("${POLYCODE_BASE}Modules/Dependencies/include")
include_directories("${POLYCODE_BASE}Modules/Dependencies/include/bullet")

## Including libraries (-L) ##
link_directories("${POLYCODE_BASE}Core/lib")
link_directories("${POLYCODE_BASE}Core/Dependencies/lib")
link_directories("${POLYCODE_BASE}Modules/lib")
link_directories("${POLYCODE_BASE}Modules/Dependencies/lib")

## Compiling & linking executable ##
add_executable(sopp ${sopp_SRCS})
target_link_libraries(sopp ${sopp_LIBS})

