#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store memory allocation info
typedef struct MemBlock {
    void *ptr;
    size_t size;
    const char *file;
    int line;
    struct MemBlock *next;
} MemBlock;

// Head of the linked list to track allocations
static MemBlock *head = NULL;

// Function to track memory allocations
void* track_malloc(size_t size, const char* file, int line) {
    void *ptr = malloc(size);  // Actual memory allocation
    if (!ptr) return NULL;

    // Debug message for allocation
    printf("Allocated %zu bytes at %p (from %s:%d)\n", size, ptr, file, line);

    // Create a new tracking node
    MemBlock* newBlock = (MemBlock*)malloc(sizeof(MemBlock));
    if (!newBlock) {
        free(ptr);
        return NULL;
    }

    newBlock->ptr = ptr;
    newBlock->size = size;
    newBlock->file = file;
    newBlock->line = line;
    newBlock->next = head;
    head = newBlock;

    return ptr;
}

// Function to track memory deallocations
void track_free(void *ptr) {
    if (!ptr) return;

    MemBlock **current = &head;
    while (*current) {
        if ((*current)->ptr == ptr) {
            MemBlock *to_free = *current;
            *current = (*current)->next;
            
            printf("Freed %zu bytes at %p\n", to_free->size, ptr);

            free(to_free);  // Free only the tracking structure
            free(ptr);  // Free actual memory
            return;
        }
        current = &(*current)->next;
    }

    // If we reach here, it means ptr was not found in the list (possible double free)
    printf("[WARNING] Attempted to free untracked pointer: %p\n", ptr);
}

// Function to print detected memory leaks
void print_memory_leaks() {
    printf("\nCurrent Memory Tracking List:\n");

    MemBlock *current = head;
    if (!current) {
        printf("No memory leaks detected!\n");
        return;
    }

    // Print all tracked allocations
    while (current) {
        printf("  Tracking: %zu bytes at %p (allocated in %s:%d)\n",
               current->size, current->ptr, current->file, current->line);
        current = current->next;
    }

    // Show leaked memory
    printf("\nMemory leaks detected:\n");
    current = head;
    while (current) {
        printf("  Leaked %zu bytes at %p (allocated in %s:%d)\n",
               current->size, current->ptr, current->file, current->line);
        current = current->next;
    }
}

// Override standard malloc/free functions
#define malloc(size) track_malloc(size, __FILE__, __LINE__)
#define free(ptr) track_free(ptr)
