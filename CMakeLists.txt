cmake_minimum_required(VERSION 3.5.2)
project(RISCV)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-O2")

add_executable(code main.cpp memory.hpp registor.hpp MA.hpp IF.hpp WB.hpp enum.hpp EX.hpp ID.hpp buffer.hpp)
