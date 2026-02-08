#ifndef FIRMWARE_ARCHITECTURE_SCHEDULER_H
#define FIRMWARE_ARCHITECTURE_SCHEDULER_H

#include <firmware/kernel/type/task.h>

void architecture_scheduler_start(task_t tasks[], uint8_t tasks_number);

#endif
