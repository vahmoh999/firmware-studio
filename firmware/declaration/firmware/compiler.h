#ifndef FIRMWARE_COMPILER_H
#define FIRMWARE_COMPILER_H

#ifdef __GNUC__

#define FIRMWARE_ALWAYS_INLINE __attribute__((always_inline))
#define FIRMWARE_SECTION(NAME) __attribute__((section(NAME)))
#define FIRMWARE_USED __attribute__((used))

#else

#define FIRMWARE_ALWAYS_INLINE
#define FIRMWARE_SECTION(NAME)
#define FIRMWARE_USED

#endif

#endif
