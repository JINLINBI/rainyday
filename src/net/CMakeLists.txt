project(net)

cmake_minimum_required(VERSION 3.16)

include_directories(${source_path}/net)
file(GLOB_RECURSE SOURCES ${source_path}/net "*.cpp")
add_library(net ${SOURCES})
target_link_libraries(net event)