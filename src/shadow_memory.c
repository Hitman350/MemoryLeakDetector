#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shadow_memory.h"

#define SHADOW_SIZE 1024
char shadow_memory[SHADOW_SIZE];

void init_shadow_memory() {
    memset(shadow_memory, 0, SHADOW_SIZE);
}

void mark_memory(void *ptr, size_t size, int state) {
    size_t index = ((size_t)ptr) % SHADOW_SIZE;
    for (size_t i = 0; i < size; i++) {
        shadow_memory[index + i] = state;
    }
}

int check_memory_use(void *ptr) {
    size_t index = ((size_t)ptr) % SHADOW_SIZE;
    return shadow_memory[index];
}
