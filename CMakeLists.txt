cmake_minimum_required(VERSION 3.26)
project(AlgorithmsAndDataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(AlgorithmsAndDataStructures LinkedList_IntID.c
        LinkedList_IntID.h
        Stack_Int.c
        Stack_Int.h
        main.c
        Queue_Int.c
        Queue_Int.h
        HavelHakimi.c
        HavelHakimi.h
        Array_Int.c
        Array_Int.h
        BinarySearchTree.c
        BinarySearchTree.h
        Heap_Int.c
        Heap_Int.h
        BinaryTree.c
        BinaryTree.h
        SortingAlgorithms.c
        SortingAlgorithms.h)
