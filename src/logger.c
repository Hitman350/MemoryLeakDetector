#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger.h"

FILE *log_file = NULL;

void init_logger() {
    log_file = fopen("logs/memory_log.txt", "w");
    if (!log_file) {
        printf("Error: Could not open log file!\n");
        exit(1);
    }
    fprintf(log_file, "Memory Leak Detector Log\n");
    fprintf(log_file, "========================\n\n");
}

void log_memory_allocation(const char *msg) {
    if (!log_file) init_logger();
    
    time_t now;
    time(&now);
    fprintf(log_file, "[%s] ALLOCATION: %s\n", ctime(&now), msg);
    fflush(log_file);
}

void log_memory_deallocation(const char *msg) {
    if (!log_file) init_logger();
    
    time_t now;
    time(&now);
    fprintf(log_file, "[%s] DEALLOCATION: %s\n", ctime(&now), msg);
    fflush(log_file);
}

void log_memory_leak(const char *msg) {
    if (!log_file) init_logger();
    
    time_t now;
    time(&now);
    fprintf(log_file, "[%s] MEMORY LEAK DETECTED: %s\n", ctime(&now), msg);
    fflush(log_file);
}

void close_logger() {
    if (log_file) {
        fprintf(log_file, "\nEnd of Log.\n");
        fclose(log_file);
    }
}
