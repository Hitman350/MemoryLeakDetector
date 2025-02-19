#include <stdio.h>
#include <stdlib.h>
#include "security_checks.h"

typedef struct FreedMemory {
    void *ptr;
    struct FreedMemory *next;
} FreedMemory;

FreedMemory *freed_list = NULL;

void check_double_free(void *ptr) {
    FreedMemory *curr = freed_list;
    while (curr) {
        if (curr->ptr == ptr) {
            printf("⚠️ Double-free detected at %p!\n", ptr);
            return;
        }
        curr = curr->next;
    }

    FreedMemory *new_entry = (FreedMemory *)malloc(sizeof(FreedMemory));
    new_entry->ptr = ptr;
    new_entry->next = freed_list;
    freed_list = new_entry;
}
