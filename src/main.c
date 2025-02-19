#define ENABLE_MEMORY_TRACKING  // Enable the malloc/free macros
#include "memory_tracker.h"      // Include the tracking functions
#include <stdio.h>
#include <stdlib.h>

extern void print_memory_leaks();

int main() {
    printf("Program Started\n");

    int *arr1 = (int*)malloc(10 * sizeof(int));  // 40 bytes
    int *arr2 = (int*)malloc(20 * sizeof(int));  // 80 bytes
    int *arr3 = (int*)malloc(30 * sizeof(int));  // 120 bytes

    printf("Memory Allocated\n");

    // Use the allocated memory
    arr1[0] = 1;
    arr2[0] = 2;
    arr3[0] = 3;

    // Intentionally leaking arr1 and arr3
    free(arr2);  // Only freeing arr2

    printf("Checking for memory leaks...\n");
    print_memory_leaks();

    return 0;
}
