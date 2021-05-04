project(rainyday)
cmake_minimum_required(VERSION 3.16)
# debug或者release

# set(CMAKE_BUILD_TYPE DEBUG)

# c编译选项
set(CMAKE_C_FLAGS "-O0 -std=c17")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g")
set(CMAKE_C_FLAGS_RELEASE "-O3")

# c++编译选项
set(CMAKE_CXX_FLAGS "-O0 -std=c++20")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(project_path ${CMAKE_CURRENT_SOURCE_DIR})
set(source_path ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(binary_path ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(third_path ${CMAKE_CURRENT_SOURCE_DIR}/3rd)


include_directories(${third_path}/libevent-2.1.12-stable/include)
include_directories(${third_path}/yaml-cpp-yaml-cpp-0.6.3/include/)
include_directories(${third_path}/protobuf-3.15.8/)
include_directories(${third_path}/mysql-connector-c++-8.0.24-linux-glibc2.12-x86-64bit/include/jdbc)
include_directories(${source_path}/common)
include_directories(${source_path}/player)
include_directories(${source_path}/net)

link_directories(${third_path}/archive)
link_directories(${third_path}/mysql-connector-c++-8.0.24-linux-glibc2.12-x86-64bit/lib64)

message("Release mode:${CMAKE_BUILD_TYPE}")

# 设置程序输出路径
add_subdirectory(${source_path}/common)
add_subdirectory(${source_path}/net)
add_subdirectory(${source_path}/player)
add_subdirectory(${source_path}/game_engine)
