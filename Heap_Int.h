#include <stdio.h>

typedef struct Heap_Int Heap_Int;
struct Heap_Int
{
    int* array;
    size_t size;
};

void TestHeap_Int();