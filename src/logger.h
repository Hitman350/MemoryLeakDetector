#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

void init_logger();
void log_memory_allocation(const char *msg);
void log_memory_deallocation(const char *msg);
void log_memory_leak(const char *msg);
void close_logger();

#endif
