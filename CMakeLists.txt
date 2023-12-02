cmake_minimum_required(VERSION 3.26)
project(AlgorithmsAndDataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmsAndDataStructures LinkedListIntID.c
        LinkedListIntID.h
        StackIntArray.c
        StackIntArray.h
        main.c
        QueueIntArray.c
        QueueIntArray.h)
