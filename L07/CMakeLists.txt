cmake_minimum_required(VERSION 3.17)
project(L07)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(L07 main.cpp headers/File.h source/File.cpp headers/CopyableClass.h source/CString.cpp source/Examples.cpp)