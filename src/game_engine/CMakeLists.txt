project(game_engine)

cmake_minimum_required(VERSION 3.16)
set(game_source_path ${source_path}/game_engine)

include_directories(${source_path}/common)

add_executable(game_engine ${game_source_path}/main.cpp)
target_link_libraries(game_engine common)