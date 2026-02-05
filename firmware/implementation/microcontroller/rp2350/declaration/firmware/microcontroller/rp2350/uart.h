#ifndef FIRMWARE_MICROCONTROLLER_RP2350_UART_H
#define FIRMWARE_MICROCONTROLLER_RP2350_UART_H

#include <stdint.h>

typedef enum : uint8_t {
    UART_ID_0 = 0,
    UART_ID_1 = 1,
} uart_id_t;

typedef enum : uint8_t {
    UART_UARTLCR_H_WLEN_5 = 0,
    UART_UARTLCR_H_WLEN_6 = 1,
    UART_UARTLCR_H_WLEN_7 = 2,
    UART_UARTLCR_H_WLEN_8 = 3,
} uart_uartlcr_h_wlen_t;

typedef struct {
    uint32_t uartdr;
    uint32_t uartrsr;
    uint32_t reserved_0[4];
    uint32_t uartfr;
    uint32_t reserved_1;
    uint32_t uartilpr;
    uint32_t uartibrd;
    uint32_t uartfbrd;
    uint32_t uartlcr_h;
    uint32_t uartcr;
} uart_t;

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
static inline volatile uart_t *uart(uart_id_t id) {
    if (id == UART_ID_0) {
        return (volatile uart_t *)0x40070000;
    }
    return (volatile uart_t *)0x40078000;
}

FIRMWARE_ALWAYS_INLINE
static inline void uart_uartdr_write(uart_id_t id, uint8_t value) {
    uart(id)->uartdr = value;
}

FIRMWARE_ALWAYS_INLINE
static inline void uart_uartibrd_write(uart_id_t id, uint16_t value) {
    uart(id)->uartibrd = value;
}

FIRMWARE_ALWAYS_INLINE
static inline void uart_uartfbrd_write(uart_id_t id, uint8_t value) {
    uart(id)->uartfbrd = value & 0x3FU;
}

FIRMWARE_ALWAYS_INLINE
static inline void uart_uartlcr_h_wlen_write(uart_id_t id, uart_uartlcr_h_wlen_t wlen) {
    uint32_t value = uart(id)->uartlcr_h;
    value &= ~(0x3U << 5);
    value |= (wlen & 0x3U) << 5;
    uart(id)->uartlcr_h = value;
}

FIRMWARE_ALWAYS_INLINE
static inline void uart_uartcr_uarten_write(uart_id_t id, bool uarten) {
    if (uarten) {
        uart(id)->uartcr |= 1U;
    } else {
        uart(id)->uartcr &= ~1U;
    }
}

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
static inline bool uart_uartfr_txff_read(uart_id_t id) {
    return (uart(id)->uartfr & (1U << 5)) != 0;
}

#endif
