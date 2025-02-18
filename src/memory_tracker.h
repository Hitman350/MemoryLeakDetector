#ifndef MEMORY_TRACKER_H  // Prevent multiple inclusions
#define MEMORY_TRACKER_H

#include <stdio.h>
#include <stdlib.h>

// Structure to track allocated memory
typedef struct MemBlock {
    size_t size;
    void* address;
    const char* file;
    int line;
    struct MemBlock* next;
} MemBlock;

// Function prototypes
void* track_malloc(size_t size, const char* file, int line);
void track_free(void* ptr);
void print_memory_leaks();

#define malloc(size) track_malloc(size, __FILE__, __LINE__)
#define free(ptr) track_free(ptr)

#endif 
