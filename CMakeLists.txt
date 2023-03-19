cmake_minimum_required(VERSION 3.21)
project(SolveHessian)

set(CMAKE_CXX_STANDARD 14)

add_executable(SolveHessian main.cpp optimisation.cpp optimisation.h)
