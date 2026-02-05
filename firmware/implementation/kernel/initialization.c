#include <firmware/microcontroller/rp2350/clocks.h>
#include <firmware/microcontroller/rp2350/io_bank0.h>
#include <firmware/microcontroller/rp2350/pads_bank0.h>
#include <firmware/microcontroller/rp2350/resets.h>
#include <firmware/microcontroller/rp2350/sio.h>
#include <firmware/microcontroller/rp2350/uart.h>
#include <firmware/microcontroller/rp2350/xosc.h>

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
    xosc_ctrl_enable_write(true);
    clocks_clk_ref_ctrl_src_write(CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC);
    clocks_clk_peri_ctrl_enable_write(true);
    resets_reset_uart0_write(false);
    pads_bank0_gpio_iso_write(0, false);
    pads_bank0_gpio_iso_write(14, false);
    io_bank0_gpio_ctrl_funcsel_write(0, IO_BANK0_GPIO_CTRL_FUNCSEL_UART);
    io_bank0_gpio_ctrl_funcsel_write(14, IO_BANK0_GPIO_CTRL_FUNCSEL_SIO);
    uart_uartibrd_write(0, 6);
    uart_uartfbrd_write(0, 33);
    uart_uartlcr_h_wlen_write(0, UART_UARTLCR_H_WLEN_8);
    uart_uartcr_uarten_write(0, true);
    sio_gpio_out_set_write(1U << 14);
    sio_gpio_oe_set_write(1U << 14);
    while (true) {
        for (volatile uint32_t i = 0; i < 1000000; i++) {
        }
        while (uart_uartfr_txff_read(0)) {
        }
        uart_uartdr_write(0, 'H');
        while (uart_uartfr_txff_read(0)) {
        }
        uart_uartdr_write(0, 'i');
        while (uart_uartfr_txff_read(0)) {
        }
        uart_uartdr_write(0, '\r');
        while (uart_uartfr_txff_read(0)) {
        }
        uart_uartdr_write(0, '\n');
        sio_gpio_oe_xor_write(1U << 14);
    }
}
