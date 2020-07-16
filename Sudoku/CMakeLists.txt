cmake_minimum_required(VERSION 3.16)
project(Sudoku)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sudoku main.cpp sudoku_field_treatment.h sudoku_field_treatment.cpp sudoku_filed.h sudoku_filed.cpp)