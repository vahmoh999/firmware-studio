#include <stdint.h>

#include <firmware/compiler.h>
#include <firmware/kernel/initialization.h>

extern const uintptr_t stack_pointer;

FIRMWARE_SECTION(".vector_table")
FIRMWARE_USED
static const uintptr_t vector_table[] = {
    (uintptr_t)&stack_pointer,
    (uintptr_t)initialize,
};
