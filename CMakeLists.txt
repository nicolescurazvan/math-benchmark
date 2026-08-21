cmake_minimum_required(VERSION 4.0)
project(benchmark)

add_compile_options(-O3)
add_executable(benchmark src/main.cpp src/prime.cpp src/prime2.cpp
        src/euler.cpp)

target_include_directories(benchmark PUBLIC include)


