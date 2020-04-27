cmake_minimum_required(VERSION 3.16)
project(NYCTreeInfo)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++17 -Wall -Wextra")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR} "../bin")

file(GLOB_RECURSE NYCTreeInfo_SOURCES "src/*.cpp")
file(GLOB_RECURSE NYCTreeInfo_HEADERS "src/*.h")

set (NYCTreeInfo_INCLUDE_DIRS "")
foreach (_headerFile ${NYCTreeInfo_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND NYCTreeInfo_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES NYCTreeInfo_INCLUDE_DIRS)

add_executable (NYCTreeInfoExe ${NYCTreeInfo_SOURCES} src/all.h)

# Add all.h as a precompiled header
target_precompile_headers(NYCTreeInfoExe PRIVATE src/all.h)