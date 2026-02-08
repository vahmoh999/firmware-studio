#include "uart.h"

#include <firmware/microcontroller/rp2350/register/clocks.h>
#include <firmware/microcontroller/rp2350/register/io_bank0.h>
#include <firmware/microcontroller/rp2350/register/pads_bank0.h>
#include <firmware/microcontroller/rp2350/register/resets.h>
#include <firmware/microcontroller/rp2350/register/uart.h>
#include <firmware/microcontroller/rp2350/register/xosc.h>

[[noreturn]]
void uart_run() {
    xosc_ctrl_enable_write(true);
    clocks_clk_ref_ctrl_src_write(CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC);
    clocks_clk_peri_ctrl_enable_write(true);
    resets_reset_uart0_write(false);
    pads_bank0_gpio_iso_write(0, false);
    io_bank0_gpio_ctrl_funcsel_write(0, IO_BANK0_GPIO_CTRL_FUNCSEL_UART);
    uart_uartibrd_write(UART_ID_0, 6);
    uart_uartfbrd_write(UART_ID_0, 33);
    uart_uartlcr_h_wlen_write(UART_ID_0, UART_UARTLCR_H_WLEN_8);
    uart_uartcr_uarten_write(UART_ID_0, true);
    while (true) {
        for (volatile uint32_t i = 0; i < 100000; i++) {
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
    }
}
