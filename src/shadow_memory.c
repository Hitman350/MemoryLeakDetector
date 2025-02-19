#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shadow_memory.h"

#define SHADOW_SIZE 1024 * 1024  // 1MB Shadow Memory

static char shadow_memory[SHADOW_SIZE];

void initialize_shadow_memory() {
    memset(shadow_memory, 0, SHADOW_SIZE);
}

void mark_memory_allocated(void *ptr, size_t size) {
    size_t index = ((size_t)ptr) % SHADOW_SIZE;
    for (size_t i = 0; i < size; i++) {
        shadow_memory[index + i] = 1;
    }
}

void mark_memory_freed(void *ptr) {
    size_t index = ((size_t)ptr) % SHADOW_SIZE;
    shadow_memory[index] = 0;
}

int is_memory_freed(void *ptr) {
    size_t index = ((size_t)ptr) % SHADOW_SIZE;
    return shadow_memory[index] == 0;
}
