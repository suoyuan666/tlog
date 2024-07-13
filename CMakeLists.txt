cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)
set (CXX_STANDARD_REQUIRED on)

project(tlog
    VERSION 2024.07
    DESCRIPTION "RGB log information output of the terminal, and support writing to files"
)

option(TLOG_DEV_TEST "Set to on for development testing of tlog itself" OFF)

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" PATH_TO_CMAKELISTS_TXT)
if(EXISTS "${PATH_TO_CMAKELISTS_TXT}")
    message(FATAL_ERROR "Run CMake from a build subdirectory! \"mkdir build ; cd build ; cmake ..\" \
    Some junk files were created in this folder (CMakeCache.txt, CMakeFiles); you should delete those.")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -Werror -Weffc++ -Wextra -Wconversion -Wsign-conversion")
endif()

if(TLOG_DEV_TEST)
    message("TLOG_DEV_TEST set to ON")
    enable_testing()
    add_subdirectory(test)
endif()

message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
endif()
message(STATUS "CMAKE_EXE_LINKER_FLAGS: ${CMAKE_EXE_LINKER_FLAGS}")
message(STATUS "CMAKE_SHARED_LINKER_FLAGS: ${CMAKE_SHARED_LINKER_FLAGS}")

add_subdirectory(third_party/fmt)
add_subdirectory(src)