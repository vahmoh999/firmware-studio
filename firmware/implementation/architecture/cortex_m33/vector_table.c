#include <stdint.h>

#include <firmware/compiler.h>

#include "exception.h"

extern const uintptr_t stack_pointer;

FIRMWARE_SECTION(".vector_table")
FIRMWARE_USED
static const uintptr_t vector_table[] = {
    (uintptr_t)&stack_pointer,
    (uintptr_t)exception_handle_reset,
    (uintptr_t)exception_handle_unhandled,
    (uintptr_t)exception_handle_unhandled,
    (uintptr_t)exception_handle_unhandled,
    (uintptr_t)exception_handle_unhandled,
    (uintptr_t)exception_handle_unhandled,
    0,
    0,
    0,
    0,
    (uintptr_t)exception_handle_unhandled,
    (uintptr_t)exception_handle_unhandled,
    0,
    (uintptr_t)exception_handle_pendsv,
    (uintptr_t)exception_handle_systick,
};
