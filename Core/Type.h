#pragma once
#include <cstdint>

#include "Config.h"
#include "Keyword.h"
#include "Compiler.h"
#include "CPU.h"

#if x_has_feature(c_atomic) && !defined(__STDC_NO_ATOMICS__)
#   include <stdatomic.h>
#endif

// 基本
using uchar = unsigned char;

using int8 = signed char;
using uint8 = unsigned char;
using byte = unsigned char;

using int16 = short;
using uint16 = unsigned short;

using int32 = int;
using uint32 = unsigned int;

// wide char
#ifdef X_CONFIG_TYPE_HAVE_WCHAR
    using x_wchar_t = wchar_t;
#elif defined(X_CONFIG_OS_WINDOWS)
#   if defined(X_WCHAR_T_DEFINED) || defined(X_NATIVE_WCHAR_T_DEFINED)
    using x_wchar_t = wchar_t;
#   else
    using x_wchar_t = uint16;
#   endif
#elif defined(X_WCHAR_TYPE)
    using  x_wchar_t = X_WCHAR_TYPE;
#elif defined(X_WCHAR_WIDTH) && (X_WCHAR_WIDTH == 2)
    using x_wchar_t = int16; 
#elif defined(X_WCHAR_WIDTH) && (X_WCHAR_WIDTH == 4)
    using x_wchar_t = int32;
#else
    using x_wchar_t = int32;
#endif

// int64
#if defined(X_COMPILER_IS_MSVC)
    using int64 = long long;
    using uint64 = unsigned long long;
#elif (defined(__LONG_WIDTH__) && __LONG_WIDTH__ == 8) || (defined(__SIZEOF_LONG__) && __SIZEOF_LONG__ == 8)
    using int64 = signed long;
    using uint64 =  unsigned long;
#else
    using int64 = signed long long;
    using int64 =  unsigned long long;
#endif

// static_cast
#define x_static_cast(t, v) static_cast<t>(v)

// dynamic_cast
#define x_dynamic_cast(t, v) dynamic_cast<t>(v)

// const_cast
#define x_const_cast(t, v) const_cast<t>(v)

// reinterpret_cast
#define x_reinterpret_cast(t, v) reinterpret_cast<t>(v)
