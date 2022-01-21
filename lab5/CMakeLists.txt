cmake_minimum_required(VERSION 3.21)
project(oop5)

set(CMAKE_CXX_STANDARD 14)

add_executable(oop5 main.cpp TIterator.h figure.h point.h point.cpp rectangle.h rectangle.cpp TVector.cpp TVector.h TVectorItem.cpp TVectorItem.h)
