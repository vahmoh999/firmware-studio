#include "exception.h"

#include <firmware/kernel/initialization.h>

#include "internal/register/scb.h"

void exception_handle_reset(void) {
    initialization_initialize();
}

FIRMWARE_NAKED
void exception_handle_pendsv(void) {
    __asm volatile(
        "mrs r0, psp \n"
        "stmdb r0!, {r4-r11, lr} \n"
        "bl scheduler_save_context \n"
        "bl scheduler_restore_context \n"
        "ldmia r0!, {r4-r11, lr} \n"
        "msr psp, r0 \n"
        "bx lr \n"
    );
}

void exception_handle_systick(void) {
    scb_icsr_pendsvset_write();
}

[[noreturn]]
void exception_handle_unhandled(void) {
    while (true) {
    }
}
