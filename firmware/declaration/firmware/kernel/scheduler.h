#ifndef FIRMWARE_KERNEL_SCHEDULER_H
#define FIRMWARE_KERNEL_SCHEDULER_H

#include <stdint.h>

void scheduler_start(void);

void scheduler_save_context(uintptr_t *stack_pointer);
uintptr_t *scheduler_restore_context(void);

#endif
