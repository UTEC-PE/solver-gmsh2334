cmake_minimum_required(VERSION 3.10)
project(solver-gmsh2334)

set(CMAKE_CXX_STANDARD 17)

add_executable(solver-gmsh2334 main.cpp cases.h node.h)