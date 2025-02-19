#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemBlock {
    void *ptr;
    size_t size;
    const char *file;
    int line;
    struct MemBlock *next;
} MemBlock;

MemBlock *head = NULL;

void* track_malloc(size_t size, const char* file, int line) {
    void *ptr = malloc(size);
    if (!ptr) return NULL;  // Check if malloc failed

    // Print debug message
    printf("[DEBUG] Allocating %zu bytes at %p (from %s:%d)\n", size, ptr, file, line);

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


void track_free(void *ptr) {
    if (!ptr) return;

    MemBlock **current = &head;
    while (*current) {
        if ((*current)->ptr == ptr) {
            MemBlock *to_free = *current;
            *current = (*current)->next;
            free(to_free);  // Free only the tracking structure
            break;
        }
        current = &(*current)->next;
    }

    free(ptr);  // Free actual memory
}

void print_memory_leaks() {
    if (!head) {
        printf("No memory leaks detected!\n");
        return;
    }

    printf("Memory leaks detected:\n");
    MemBlock *current = head;
    while (current) {
        printf("  Leaked %zu bytes at %p (allocated in %s:%d)\n",
               current->size, current->ptr, current->file, current->line);
        current = current->next;
    }
}

#define malloc(size) track_malloc(size, __FILE__, __LINE__)
#define free(ptr) track_free(ptr)
