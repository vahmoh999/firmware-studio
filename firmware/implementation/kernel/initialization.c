#include <firmware/microcontroller/rp2350/io_bank0.h>
#include <firmware/microcontroller/rp2350/pads_bank0.h>
#include <firmware/microcontroller/rp2350/sio.h>

extern uint8_t data_start[];
extern uint8_t data_end[];
extern uint8_t data_load[];
extern uint8_t bss_start[];
extern uint8_t bss_end[];

[[noreturn]]
void initialize(void) {
    for (uint8_t *source = data_load, *destination = data_start; destination < data_end;) {
        *destination++ = *source++;
    }
    for (uint8_t *destination = bss_start; destination < bss_end;) {
        *destination++ = 0;
    }
    io_bank0_gpio_ctrl_funcsel_set(14, IO_BANK0_GPIO_CTRL_FUNCSEL_SIO);
    pads_bank0_gpio_iso_set(14, false);
    sio()->gpio_out_set = 1U << 14;
    sio()->gpio_oe_set = 1U << 14;
    while (true) {
        for (volatile uint32_t i = 0; i < 1000000; i++) {
        }
        sio()->gpio_oe_xor = 1U << 14;
    }
}
