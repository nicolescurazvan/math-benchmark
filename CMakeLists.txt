cmake_minimum_required(VERSION 4.0)
project(benchmark)

add_executable(benchmark src/main.cpp)

target_include_directories(benchmark PUBLIC include)

target_compile_features(benchmark PUBLIC -O3)
