cmake_minimum_required(VERSION 3.15)
project(LogMe)

set(CMAKE_CXX_STANDARD 14)

add_executable(LogMe main.cpp log.cpp log.h)