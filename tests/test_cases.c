#include <stdio.h>
#include <stdlib.h>
#include "memory_tracker.h"

void run_tests() {
    printf("Running Tests...\n");

    // Memory allocation test
    int *test1 = (int*)malloc(10 * sizeof(int));
    if (test1) printf("Test 1 Passed: Memory allocated\n");

    // Memory leak test (intentional)
    int *test2 = (int*)malloc(50 * sizeof(int));
    (void)test2; // Suppressing unused variable warning

    // Proper deallocation
    free(test1);
    printf("Test 2 Passed: Memory freed properly\n");
}

int main() {
    run_tests();
    print_memory_leaks();  // Check for leaks
    return 0;
}
