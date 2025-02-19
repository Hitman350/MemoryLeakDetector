#include <stdio.h>
#include <stdlib.h>
#include "security_checks.h"
#include "shadow_memory.h"

void check_use_after_free(void *ptr) {
    if (is_memory_freed(ptr)) {
        printf("Warning: Use-after-free detected at address %p\n", ptr);
    }
}

void check_double_free(void *ptr) {
    if (is_memory_freed(ptr)) {
        printf("Warning: Double free detected at address %p\n", ptr);
    }
}
