project(player)

cmake_minimum_required(VERSION 3.16)

file(GLOB_RECURSE SOURCES ${source_path}/player "*.cpp")
add_library(player ${SOURCES})