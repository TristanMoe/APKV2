cmake_minimum_required(VERSION 3.17)
project(L05)

set(CMAKE_CXX_STANDARD 17)

add_executable(L05 main.cpp source/SensorPrinter.cpp headers/SensorPrinter.h headers/MedianCombiner.h)