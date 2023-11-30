cmake_minimum_required(VERSION 3.26)
project(AlgorithmsAndDataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmsAndDataStructures LinkedList.c
        LinkedList.h
        StackArray.c
        StackArray.h
        main.c
        Queue.c
        Queue.h)
