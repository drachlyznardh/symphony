
cmake_minimum_required(VERSION 2.8)

project(SymphonyOfPewPew CXX)

include(utils.cmake)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -pedantic")

## Options ##
option(POLYCODE_BASE "Set URL for Polycode" OFF)

set(sopp_ROOT ${CMAKE_SOURCE_DIR})
add_subdirectory(src)
list(APPEND sopp_SRCS ${src_SRCS})
list(APPEND sopp_LIBS ${src_LIBS})
list(REMOVE_DUPLICATES sopp_SRCS)
list(REMOVE_DUPLICATES sopp_LIBS)

if (NOT POLYCODE_BASE)
	message (FATAL_ERROR
		"This project depends on Polycode\n"
		"Run cmake with -DPOLYCODE_BASE=<URL> to specify location\n"
		"Please specify the location of Polycode Core\n"
		"Should look like Polycode/Release/<platftorm>/Framework/"
	)
endif ()

message("Using ${POLYCODE_BASE} as base for Polycode")

include_directories("${POLYCODE_BASE}Core/include")
include_directories("${POLYCODE_BASE}Core/Dependencies/include")
include_directories("${POLYCODE_BASE}Core/Dependencies/include/AL")
include_directories("${POLYCODE_BASE}Modules/include")
include_directories("${POLYCODE_BASE}Modules/Dependencies/include")
include_directories("${POLYCODE_BASE}Modules/Dependencies/include/bullet")

add_executable(sopp ${sopp_SRCS})
target_link_libraries(sopp ${sopp_LIBS})

