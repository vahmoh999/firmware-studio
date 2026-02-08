#include "sio.h"

#include <firmware/microcontroller/rp2350/register/io_bank0.h>
#include <firmware/microcontroller/rp2350/register/pads_bank0.h>
#include <firmware/microcontroller/rp2350/register/sio.h>

[[noreturn]]
void sio_run() {
    pads_bank0_gpio_iso_write(14, false);
    io_bank0_gpio_ctrl_funcsel_write(14, IO_BANK0_GPIO_CTRL_FUNCSEL_SIO);
    sio_gpio_out_set_write(1U << 14);
    sio_gpio_oe_set_write(1U << 14);
    while (true) {
        for (volatile uint32_t i = 0; i < 100000; i++) {
        }
        sio_gpio_oe_xor_write(1U << 14);
    }
}
