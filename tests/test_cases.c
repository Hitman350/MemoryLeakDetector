#include <stdio.h>
#include <stdlib.h>
#include "memory_tracker.h"

void test_memory_leak() {
    printf("\nRunning test: Memory Leak Detection...\n");
    int *leaked_ptr = (int*)malloc(50 * sizeof(int));  // Intentional leak
    (void)leaked_ptr;
}

void test_double_free() {
    printf("\nRunning test: Double Free Detection...\n");
    int *ptr = (int*)malloc(10 * sizeof(int));
    free(ptr);
    free(ptr); // Intentional double free
}

void test_use_after_free() {
    printf("\nRunning test: Use After Free Detection...\n");
    int *ptr = (int*)malloc(10 * sizeof(int));
    free(ptr);
    printf("Accessing freed memory: %d\n", *ptr);  // Should trigger an error
}

int main() {
    test_memory_leak();
    test_double_free();
    test_use_after_free();

    print_memory_leaks(); // Ensure leaks are detected at the end
    return 0;
}
