#ifndef FIRMWARE_MICROCONTROLLER_RP2350_SIO_H
#define FIRMWARE_MICROCONTROLLER_RP2350_SIO_H

#include <stdint.h>

#include <firmware/compiler.h>

typedef struct {
    const uint32_t cpuid;
    const uint32_t gpio_in;
    const uint32_t gpio_hi_in;
    uint32_t reserved;
    uint32_t gpio_out;
    uint32_t gpio_hi_out;
    uint32_t gpio_out_set;
    uint32_t gpio_hi_out_set;
    uint32_t gpio_out_clr;
    uint32_t gpio_hi_out_clr;
    uint32_t gpio_out_xor;
    uint32_t gpio_hi_out_xor;
    uint32_t gpio_oe;
    uint32_t gpio_hi_oe;
    uint32_t gpio_oe_set;
    uint32_t gpio_hi_oe_set;
    uint32_t gpio_oe_clr;
    uint32_t gpio_hi_oe_clr;
    uint32_t gpio_oe_xor;
    uint32_t gpio_hi_oe_xor;
} sio_t;

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
static inline volatile sio_t *sio(void) {
    return (volatile sio_t *)0xD0000000;
}

FIRMWARE_ALWAYS_INLINE
static inline void sio_gpio_out_set_write(uint32_t value) {
    sio()->gpio_out_set = value;
}

FIRMWARE_ALWAYS_INLINE
static inline void sio_gpio_oe_set_write(uint32_t value) {
    sio()->gpio_oe_set = value;
}

FIRMWARE_ALWAYS_INLINE
static inline void sio_gpio_oe_xor_write(uint32_t value) {
    sio()->gpio_oe_xor = value;
}

#endif
