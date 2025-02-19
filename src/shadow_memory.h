#ifndef SHADOW_MEMORY_H
#define SHADOW_MEMORY_H

void init_shadow_memory();
void mark_memory(void *ptr, size_t size, int state);
int check_memory_use(void *ptr);

#endif
