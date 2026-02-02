#include <stdint.h>

#include <firmware/compiler.h>

FIRMWARE_SECTION(".image_def")
FIRMWARE_USED
constexpr static uint32_t image_def[] = {
    0xFFFFDED3,
    0x10210142,
    0x000001FF,
    0x00000000,
    0xAB123579,
};
