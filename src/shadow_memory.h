#ifndef SHADOW_MEMORY_H
#define SHADOW_MEMORY_H

void initialize_shadow_memory();
void mark_memory_allocated(void *ptr, size_t size);
void mark_memory_freed(void *ptr);
int is_memory_freed(void *ptr);

#endif
