#include <stdio.h>
#include "memory_tracker.h"

void visualize_memory_leaks() {
    printf("\n============================\n");
    printf("Memory Leak Report\n");
    printf("============================\n");
    
    print_memory_leaks();
}
