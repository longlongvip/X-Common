#pragma once
#include <climits>
// 基本
using uchar = unsigned char;

using int8 = signed char;
using uint8 = unsigned char;
using byte = unsigned char;

using int16 = short;
using uint16 = unsigned short;

using int32 = int;
using uint32 = unsigned int;


using s8 = signed char;
using u8 = unsigned char;
using s16 = short;
using u16 = unsigned short;
using s32 = int;
using u32 = unsigned int;

using wchar = wchar_t;

// static_cast
#define x_static_cast(t, v) static_cast<t>(v)

// dynamic_cast
#define x_dynamic_cast(t, v) dynamic_cast<t>(v)

// const_cast
#define x_const_cast(t, v) const_cast<t>(v)

// reinterpret_cast
#define x_reinterpret_cast(t, v) reinterpret_cast<t>(v)

// size_t 转 int
#define x_size_t_to_int(v) static_cast<int>(v)

#define uchar_max UCHAR_MAX
#define uchar_min 0x0

#define int8_max SCHAR_MAX
#define int8_min SCHAR_MIN
#define uint8_max UCHAR_MAX
#define uint8_min 0x00

#define int16_min SHRT_MIN
#define int16_max SHRT_MAX
#define uint16_min 0x0000
#define uint16_max USHRT_MAX

#define int32_min INT_MIN
#define int32_max INT_MAX
#define uint32_min 0x00000000
#define uint32_max UINT_MAX
