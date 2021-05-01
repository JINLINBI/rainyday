project(common)

cmake_minimum_required(VERSION 3.16)

include_directories(${source_path}/common)
file(GLOB_RECURSE SOURCES ${source_path}/common "*.cpp")
add_library(common ${SOURCES})