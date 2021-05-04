project(game_engine)

cmake_minimum_required(VERSION 3.16)
set(game_source_path ${source_path}/game_engine)

include_directories(${game_source_path})
file(GLOB_RECURSE SOURCES ${game_source_path} "*.cpp")
message(STATUS ${SOURCES})
add_executable(game_engine ${game_source_path}/main.cpp ${SOURCES})
SET(EXECUTABLE_OUTPUT_PATH ${binary_path})

target_link_libraries(game_engine player common yaml-cpp event net pthread mysqlcppconn8-static)