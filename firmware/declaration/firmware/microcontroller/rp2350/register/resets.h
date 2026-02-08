#ifndef FIRMWARE_MICROCONTROLLER_RP2350_RESETS_H
#define FIRMWARE_MICROCONTROLLER_RP2350_RESETS_H

#include <stdint.h>

#include <firmware/compiler.h>

typedef struct {
    uint32_t reset;
} resets_t;

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
static inline volatile resets_t *resets(void) {
    return (volatile resets_t *)(0x40020000);
}

FIRMWARE_ALWAYS_INLINE
static inline void resets_reset_uart0_write(bool uart0) {
    if (uart0) {
        resets()->reset |= 1U << 26;
    } else {
        resets()->reset &= ~(1U << 26);
    }
}

#endif
