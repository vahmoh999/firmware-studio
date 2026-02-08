#ifndef FIRMWARE_KERNEL_TYPE_H
#define FIRMWARE_KERNEL_TYPE_H

#include <stddef.h>
#include <stdint.h>

typedef void (*task_entry_t)(void);

typedef struct {
    task_entry_t entry;
    uintptr_t *stack_base;
    uintptr_t *stack_pointer;
    size_t stack_size;
} task_t;

#endif
