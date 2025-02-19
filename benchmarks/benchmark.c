#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "memory_tracker.h"

#define ALLOC_COUNT 1000000

void benchmark_memory_tracking() {
    printf("\nRunning Benchmark: Memory Tracking Performance...\n");
    
    clock_t start = clock();
    for (int i = 0; i < ALLOC_COUNT; i++) {
        int *ptr = (int*)malloc(sizeof(int));
        free(ptr);
    }
    clock_t end = clock();

    printf("Time taken: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    benchmark_memory_tracking();
    print_memory_leaks();
    return 0;
}
