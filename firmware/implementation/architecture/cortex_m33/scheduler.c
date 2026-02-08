#include "scheduler.h"

#include "internal/register/systick.h"

constexpr uint32_t EXC_RETURN = 0xFFFFFFFD;
constexpr uint32_t XPSR_T = 0x01000000;

void architecture_scheduler_start(task_t tasks[], uint8_t tasks_number) {
    systick_syst_rvr_write(1000);
    systick_syst_cvr_write(0);
    systick_syst_csr_enable_write(true);
    systick_syst_csr_tickint_write(true);
    systick_syst_csr_clksource_write(true);
    for (uint8_t i = 0; i < tasks_number; i++) {
        uintptr_t *stack_pointer = (uintptr_t *)((uint8_t *)tasks[i].stack_base + tasks[i].stack_size);
        *(--stack_pointer) = XPSR_T;
        *(--stack_pointer) = (uintptr_t)tasks[i].entry;
        for (uint8_t j = 0; j < 6; j++) {
            *(--stack_pointer) = 0;
        }
        *(--stack_pointer) = EXC_RETURN;
        for (uint8_t j = 0; j < 8; j++) {
            *(--stack_pointer) = 0;
        }
        tasks[i].stack_pointer = stack_pointer;
    }
    __asm volatile(
        "msr psp, %0 \n"
        "mov r0, #2 \n"
        "msr control, r0 \n"
        "bx %1 \n"
        :: "r" (tasks[0].stack_base + tasks[0].stack_size), "r" (tasks[0].entry)
        : "r0"
    );
}
