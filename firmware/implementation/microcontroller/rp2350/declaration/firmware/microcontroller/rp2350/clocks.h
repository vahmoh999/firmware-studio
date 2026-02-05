#ifndef FIRMWARE_MICROCONTROLLER_RP2350_CLOCKS_H
#define FIRMWARE_MICROCONTROLLER_RP2350_CLOCKS_H

#include <stdint.h>

#include <firmware/compiler.h>

typedef enum : uint8_t {
    CLOCKS_CLK_REF_CTRL_SRC_ROSC_CLKSRC_PH,
    CLOCKS_CLK_REF_CTRL_SRC_CLKSRC_CLK_REF_AUX,
    CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC,
    CLOCKS_CLK_REF_CTRL_SRC_LPOSC_CLKSRC,
} clocks_clk_ref_ctrl_src_t;

typedef struct {
    uint32_t ctrl;
    uint32_t div;
    uint32_t selected;
} clocks_clk_gpout_t;

typedef struct {
    uint32_t ctrl;
    uint32_t div;
    uint32_t selected;
} clocks_clk_ref_t;

typedef struct {
    uint32_t ctrl;
    uint32_t div;
    uint32_t selected;
} clocks_clk_sys_t;

typedef struct {
    uint32_t ctrl;
    uint32_t div;
    uint32_t selected;
} clocks_clk_peri_t;

typedef struct {
    clocks_clk_gpout_t clk_gpout[4];
    clocks_clk_ref_t clk_ref;
    clocks_clk_sys_t clk_sys;
    clocks_clk_peri_t clk_peri;
} clocks_t;

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
static inline volatile clocks_t *clocks(void) {
    return (volatile clocks_t *)0x40010000;
}

FIRMWARE_ALWAYS_INLINE
static inline void clocks_clk_ref_ctrl_src_write(clocks_clk_ref_ctrl_src_t src) {
    uint32_t value = clocks()->clk_ref.ctrl;
    value &= ~0x3u;
    value |= src & 0x3u;
    clocks()->clk_ref.ctrl = value;
}

FIRMWARE_ALWAYS_INLINE
static inline void clocks_clk_peri_ctrl_enable_write(bool enable) {
    if (enable) {
        clocks()->clk_peri.ctrl |= 1U << 11;
    } else {
        clocks()->clk_peri.ctrl &= ~(1U << 11);
    }
}

#endif
