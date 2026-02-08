#include "initialization.h"

#include "scheduler.h"

extern uint8_t data_start[];
extern uint8_t data_end[];
extern uint8_t data_load[];
extern uint8_t bss_start[];
extern uint8_t bss_end[];

void initialization_initialize(void) {
    for (uint8_t *source = data_load, *destination = data_start; destination < data_end;) {
        *destination++ = *source++;
    }
    for (uint8_t *destination = bss_start; destination < bss_end;) {
        *destination++ = 0;
    }
    scheduler_start();
}
