cmake_minimum_required(VERSION 3.15)
project(CycledPriorityQueue C)

set(CMAKE_C_STANDARD 99)

add_executable(CycledPriorityQueue cycled_priority_queue.c cycled_priority_queue.h main.c)