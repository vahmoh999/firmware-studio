#include "scheduler.h"

#include <firmware/architecture/scheduler.h>
#include <firmware/service/sio.h>
#include <firmware/service/uart.h>

#include "type/task.h"

static uint8_t sio_stack[1024];
static uint8_t uart_stack[1024];

task_t tasks[] = {
    {
        .entry = sio_run,
        .stack_base = (uintptr_t *)sio_stack,
        .stack_size = sizeof(sio_stack),
    },
    {
        .entry = uart_run,
        .stack_base = (uintptr_t *)uart_stack,
        .stack_size = sizeof(uart_stack),
    },
};

constexpr uint8_t TASK_NUMBER = sizeof(tasks) / sizeof(tasks[0]);

uint8_t current_task = 0;

void scheduler_start(void) {
    architecture_scheduler_start(tasks, TASK_NUMBER);
}

void scheduler_save_context(uintptr_t *stack_pointer) {
    tasks[current_task].stack_pointer = stack_pointer;
}

uintptr_t *scheduler_restore_context(void) {
    current_task = (current_task + 1) % TASK_NUMBER;
    return tasks[current_task].stack_pointer;
}
