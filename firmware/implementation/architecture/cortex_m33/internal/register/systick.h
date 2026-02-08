#ifndef FIRMWARE_ARCHITECTURE_SYSTICK_H
#define FIRMWARE_ARCHITECTURE_SYSTICK_H

#include <stdint.h>

#include <firmware/compiler.h>

typedef struct {
    uint32_t syst_csr;
    uint32_t syst_rvr;
    uint32_t syst_cvr;
} systick_t;

[[nodiscard]]
FIRMWARE_ALWAYS_INLINE
static inline volatile systick_t *systick(void) {
    return (volatile systick_t *)0xE000E010;
}

FIRMWARE_ALWAYS_INLINE
static inline void systick_syst_csr_enable_write(bool enable) {
    if (enable) {
        systick()->syst_csr |= 1U;
    } else {
        systick()->syst_csr &= ~1U;
    }
}

FIRMWARE_ALWAYS_INLINE
static inline void systick_syst_csr_tickint_write(bool tickint) {
    if (tickint) {
        systick()->syst_csr |= 1U << 1;
    } else {
        systick()->syst_csr &= ~(1U << 1);
    }
}

FIRMWARE_ALWAYS_INLINE
static inline void systick_syst_csr_clksource_write(bool clksource) {
    if (clksource) {
        systick()->syst_csr |= 1U << 2;
    } else {
        systick()->syst_csr &= ~(1U << 2);
    }
}

FIRMWARE_ALWAYS_INLINE
static inline void systick_syst_rvr_write(uint32_t value) {
    systick()->syst_rvr = value;
}

FIRMWARE_ALWAYS_INLINE
static inline void systick_syst_cvr_write(uint32_t value) {
    systick()->syst_cvr = value;
}

#endif
