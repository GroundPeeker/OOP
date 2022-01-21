cmake_minimum_required(VERSION 3.20)
project(oop1)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop1 main.cpp figure.h point.h point.cpp rectangle.cpp rectangle.h trapezoid.cpp trapezoid.h rhombus.cpp rhombus.h)
