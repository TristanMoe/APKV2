cmake_minimum_required(VERSION 3.17)
project(L02)

set(CMAKE_CXX_STANDARD 17)

add_executable(L02 main.cpp Headers/MyArray.h Headers/Person.h Source/Person.cpp)