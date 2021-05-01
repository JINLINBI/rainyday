project(rainyday)
cmake_minimum_required(VERSION 3.16)
# debug或者release

set(CMAKE_BUILD_TYPE DEBUG)

# c编译选项
set(CMAKE_C_FLAGS "-O0 -g -std=c17")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
set(CMAKE_C_FLAGS_RELEASE "-O3 -g")

# c++编译选项
set(CMAKE_CXX_FLAGS "-O0 -g -std=c++20")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g")

set(project_path ${CMAKE_CURRENT_SOURCE_DIR})
set(source_path ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(binary_path ${CMAKE_CURRENT_SOURCE_DIR}/bin)


include_directories(${source_path}/common)

link_directories((${sourc_path}/common))

# 设置程序输出路径
SET(EXECUTABLE_OUTPUT_PATH ${binary_path})
add_subdirectory(${source_path}/common)
add_subdirectory(${source_path}/game_engine)