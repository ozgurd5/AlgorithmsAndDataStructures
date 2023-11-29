cmake_minimum_required(VERSION 3.26)
project(AlgorithmsAndDataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmsAndDataStructures LinkedList.c
        LinkedList.h
        Stack.c
        Stack.h
        main.c
        Queue.c
        Queue.h)
