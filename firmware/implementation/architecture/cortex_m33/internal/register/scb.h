#ifndef FIRMWARE_ARCHITECTURE_SCB_H
#define FIRMWARE_ARCHITECTURE_SCB_H

#include <stdint.h>

#include <firmware/compiler.h>

typedef struct {
    const uint32_t revidr;
    const uint32_t cpuid;
    uint32_t icsr;
} scb_t;

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
static inline volatile scb_t *scb(void) {
    return (volatile scb_t *)0xE000ECFC;
}

FIRMWARE_ALWAYS_INLINE
static inline void scb_icsr_pendsvset_write(void) {
    scb()->icsr = 1U << 28;
}

#endif
