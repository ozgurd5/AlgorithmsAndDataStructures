cmake_minimum_required(VERSION 3.26)
project(AlgorithmsAndDataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmsAndDataStructures LinkedList_IntID.c
        LinkedList_IntID.h
        Stack_Int.c
        Stack_Int.h
        main.c
        Queue_Int.c
        Queue_Int.h)
