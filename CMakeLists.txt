cmake_minimum_required(VERSION 3.22)
project(progRgr)

set(CMAKE_CXX_STANDARD 14)

add_executable(progRgr main.cpp gronsfeld.cpp gronsfeld.h interface.cpp interface.h polybiusSquare.cpp polybiusSquare.h)
