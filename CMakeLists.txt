cmake_minimum_required(VERSION 3.10.0)
project(nonogram-solver VERSION 0.1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic -Werror --std=c++23")
set (CMAKE_CXX_FLAGS_RELEASE "-g -O3 -DNDEBUG --std=c++23")

add_executable(nonogram-solver main.cpp)
add_library(nonogramsolver SHARED
  board.hpp
  solver.hpp
  solver.cpp
)
add_library(cnonogramsolver SHARED
  externc.cpp
  board.hpp
  solver.hpp
)