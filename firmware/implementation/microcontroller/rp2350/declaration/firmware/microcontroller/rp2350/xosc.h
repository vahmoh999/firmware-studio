#ifndef FIRMWARE_MICROCONTROLLER_RP2350_XOSC_H
#define FIRMWARE_MICROCONTROLLER_RP2350_XOSC_H

#include <stdint.h>

#include <firmware/compiler.h>

typedef struct {
    uint32_t ctrl;
} xosc_t;

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
static inline volatile xosc_t *xosc(void) {
    return (volatile xosc_t *)0x40048000;
}

FIRMWARE_ALWAYS_INLINE
static inline void xosc_ctrl_enable_write(bool enable) {
    uint32_t value = xosc()->ctrl & ~(0xFFFU << 12);
    if (enable) {
        value |= 0xFAB << 12;
    } else {
        value |= 0xD1E << 12;
    }
    xosc()->ctrl = value;
}

#endif
