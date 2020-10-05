cmake_minimum_required(VERSION 3.17)
project(L06_Exceptions)

set(CMAKE_CXX_STANDARD 17)

add_executable(L06_Exceptions main.cpp headers/LogFile.h source/LogFile.cpp headers/MyVector.h "headers/LogFileException.h")