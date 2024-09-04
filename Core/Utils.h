#pragma once

#include "CPU.h"
#include "Compiler.h"

// abs
#define x_abs(x) ((x) > 0 ? (x) : -(x))

// max
#define x_max(x, y) (((x) > (y))? (x) : (y))

// min
#define x_min(x, y) (((x) < (y))? (x) : (y))

// max3
#define x_max3(x, y, z) (((x) > (y))? (((x) > (z))? (x) : (z)) : (((y) > (z))? (y) : (z)))

// min3
#define x_min3(x, y, z) (((x) < (y))? (((x) < (z))? (x) : (z)) : (((y) < (z))? (y) : (z)))

// the number of entries in the array
#define x_array_size(x) ((sizeof((x)) / sizeof((x)[0])))

// is_pow2: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, ...
#define x_is_pow2(x) (!((x) & ((x) - 1)) && (x))

// align2
#define x_align2(x) (((x) + 1) >> 1 << 1)

// align4
#define x_align4(x) (((x) + 3) >> 2 << 2)

// align8
#define x_align8(x) (((x) + 7) >> 3 << 3)

// align
#define x_align(x, b) (((size_t)(x) + ((size_t)(b) - 1)) & ~((size_t)(b) - 1))

// align u32
#define x_align_u32(x, b) (((uint32)(x) + ((uint32)(b) - 1)) & ~((uint32)(b) - 1))

// align u64
#define x_align_u64(x, b) (((uint64)(x) + ((uint64)(b) - 1)) & ~((uint64)(b) - 1))

// align by pow2
#define x_align_pow2(x) (((x) > 1)? (x_ispow2(x)? (x) : ((size_t)1 << (32 - x_bits_cl0_u32_be((uint32)(x))))) : 1)

// align by cpu bytes
#if X_CPU_BIT64
#   define x_align_cpu(x) x_align8(x)
#else
#   define x_align_cpu(x) x_align4(x)
#endif

 // offsetof
#if defined(X_COMPILER_IS_GCC) && X_COMPILER_VERSION_BE(4, 1)
#   define x_offsetof(s, m) (size_t)__builtin_offsetof(s, m)
#else
#   define x_offsetof(s, m) (size_t)&(((s const*)0)->m)
#endif

// container of
#define x_container_of(s, m, p) ((s*)(((byte*)(p)) - x_offsetof(s, m)))

// memsizeof
#define x_memsizeof(s, m) sizeof(((s const*)0)->m)

// memtailof
#define x_memtailof(s, m) (x_offsetof(s, m) + x_memsizeof(s, m))

// memdiffof: lm - rm
#define x_memdiffof(s, lm, rm) (x_memtailof(s, lm) - x_memtailof(s, rm))

// check the offset and size of member for struct or union
#define x_memberof_eq(ls, lm, rs, rm)  ((x_offsetof(ls, lm) == x_offsetof(rs, rm)) && (x_memsizeof(ls, lm) == x_memsizeof(rs, rm)))

// pointer to bool
#define x_p2b(x) ((int)(size_t)(x))

// pointer to u8
#define x_p2u8(x) ((uint8)(size_t)(x))

// pointer to u16
#define x_p2u16(x) ((uint16)(size_t)(x))

// pointer to u32
#define x_p2u32(x) ((uint32)(size_t)(x))

// pointer to u64
#define x_p2u64(x) ((uint64)(size_t)(x))

// pointer to s8
#define x_p2s8(x) ((int8)(x_pointer)(x))

// pointer to s16
#define x_p2s16(x) ((int16)(x_pointer)(x))

// pointer to s32
#define x_p2s32(x) ((int32)(x_pointer)(x))

// pointer to s64
#define x_p2s64(x) ((int64)(x_pointer)(x))

// bool to pointer
#define x_b2p(x) ((x_pointer)(size_t)(x))

// unsigned integer to pointer
#define x_u2p(x) ((x_pointer)(size_t)(x))

// integer to pointer
#define x_i2p(x) ((x_pointer)(x_pointer)(x))

// swap
#define x_swap(t, l, r) do { t __p = (r); (r) = (l); (l) = __p; } while (0)

// 整数 char 转整数 参数 字符
#define c2i(x) ((x) - '0')
