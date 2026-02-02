#ifndef FIRMWARE_MICROCONTROLLER_RP2350_PADS_BANK0_H
#define FIRMWARE_MICROCONTROLLER_RP2350_PADS_BANK0_H

#include <stdint.h>

#include <firmware/compiler.h>

typedef struct {
    uint32_t voltage_select;
    uint32_t gpio[48];
} pads_bank0_t;

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
FIRMWARE_USED
static inline volatile pads_bank0_t *pads_bank0(void) {
    return (volatile pads_bank0_t *)0x40038000;
}

FIRMWARE_ALWAYS_INLINE
FIRMWARE_USED
static inline void pads_bank0_gpio_iso_set(uint8_t id, bool iso) {
    if (iso) {
        pads_bank0()->gpio[id] |= 1U << 8;
    } else {
        pads_bank0()->gpio[id] &= ~(1U << 8);
    }
}

#endif
