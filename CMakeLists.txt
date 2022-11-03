cmake_minimum_required(VERSION 3.23)
project(05_ilp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Werror -pedantic -pedantic-errors)

add_executable(bpred1 bpred1.cpp generate.cpp)
add_executable(bpred2 bpred2.cpp generate.cpp)
add_executable(bpred3 bpred3.cpp generate.cpp)
