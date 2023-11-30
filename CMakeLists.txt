cmake_minimum_required(VERSION 3.26)
project(AlgorithmsAndDataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmsAndDataStructures LinkedList.c
        LinkedList.h
        StackIntArray.c
        StackIntArray.h
        main.c
        QueueIntArray.c
        QueueIntArray.h)
