#ifndef FIRMWARE_ARCHITECTURE_EXCEPTION_H
#define FIRMWARE_ARCHITECTURE_EXCEPTION_H

#include <firmware/compiler.h>

void exception_handle_reset(void);

FIRMWARE_NAKED
void exception_handle_pendsv(void);

void exception_handle_systick(void);

[[noreturn]]
void exception_handle_unhandled(void);

#endif
