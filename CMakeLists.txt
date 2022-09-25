cmake_minimum_required(VERSION 3.19)
project(Operating_Systems)

set(CMAKE_CXX_STANDARD 14)

include_directories(CPU_Scheduler/cmake-build-debug)

add_executable(Operating_Systems
        CPU_Scheduler/cmake-build-debug/Scheduler.h
        CPU_Scheduler/main.cpp)
