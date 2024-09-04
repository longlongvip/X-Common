#pragma once
#include <climits>

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

// 任务类型 转 size_t
#define x_to_size(v) static_cast<size_t>(v)

// 任何类型 转 int
#define x_to_int(v) static_cast<int>(v)

// 任何类型 转 float
#define x_to_float(v) static_cast<float>(v)

// 任何类型 转 double
#define x_to_double(v) static_cast<double>(v)

// 任何类型 转 bool
#define x_to_bool(v) static_cast<bool>(v)

// 任何类型 转 char
#define x_to_char(v) static_cast<char>(v)

// 任何类型 转 unsigned char
#define x_to_u8(v) static_cast<u8>(v)

#define uchar_max UCHAR_MAX
#define uchar_min 0x0

#define s8_max SCHAR_MAX
#define s8_min SCHAR_MIN
#define u8_max UCHAR_MAX
#define u8_min 0x00

#define s16_min SHRT_MIN
#define s16_max SHRT_MAX
#define u16_min 0x0000
#define u16_max USHRT_MAX

#define s32_min INT_MIN
#define s32_max INT_MAX
#define u32_min 0x00000000
#define u32_max UINT_MAX

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
