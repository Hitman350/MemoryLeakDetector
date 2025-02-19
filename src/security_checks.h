#ifndef SECURITY_CHECKS_H
#define SECURITY_CHECKS_H

void check_use_after_free(void *ptr);
void check_double_free(void *ptr);

#endif
