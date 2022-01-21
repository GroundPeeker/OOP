cmake_minimum_required(VERSION 3.21)
project(oop2)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop2 main.cpp TVector.cpp TVector.h figure.h point.h point.cpp rectangle.h rectangle.cpp TVectorItem.h TVectorItem.cpp)
