#ifndef FIRMWARE_MICROCONTROLLER_RP2350_IO_BANK0_H
#define FIRMWARE_MICROCONTROLLER_RP2350_IO_BANK0_H

#include <stdint.h>

#include <firmware/compiler.h>

typedef enum : uint8_t {
    IO_BANK0_GPIO_CTRL_FUNCSEL_SIO = 5,
} io_bank0_gpio_ctrl_funcsel_t;

typedef struct {
    uint32_t status;
    uint32_t ctrl;
} io_bank0_gpio_t;

typedef struct {
    io_bank0_gpio_t gpio[48];
} io_bank0_t;

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
FIRMWARE_USED
static inline volatile io_bank0_t *io_bank0(void) {
    return (volatile io_bank0_t *)0x40028000;
}

FIRMWARE_ALWAYS_INLINE
FIRMWARE_USED
static inline void io_bank0_gpio_ctrl_funcsel_set(uint8_t id, io_bank0_gpio_ctrl_funcsel_t funcsel) {
    volatile io_bank0_gpio_t *gpio = &io_bank0()->gpio[id];
    gpio->ctrl = (gpio->ctrl & ~0x1F) | funcsel;
}

#endif
