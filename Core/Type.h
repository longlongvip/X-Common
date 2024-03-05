#pragma once

#include "Config.h"
#include "Keyword.h"
#include "Compiler.h"
#include "CPU.h"

#if x_has_feature(c_atomic) && !defined(__STDC_NO_ATOMICS__)
#   include <stdatomic.h>
#endif

/** 基本 */
typedef unsigned char uchar;

typedef signed char int8;
typedef unsigned char uint8;
typedef unsigned char byte;

typedef signed short int16;
typedef unsigned short uint16;

typedef signed int   int32;
typedef unsigned int uint32;

typedef void x_void;
typedef void* x_pointer;
typedef void const* x_const_pointer;
typedef x_pointer x_handle;

/** null */
#ifdef __cplusplus
#   define x_null (0)
# else
#   define x_null (x_pointer)(0)
#endif

/** 无参数 */
#ifdef __cplusplus
#   define x_noarg
#else
#   define x_noarg x_void
#endif

// wchar
#ifdef X_CONFIG_TYPE_HAVE_WCHAR
typedef wchar_t                 wchar_t;
#elif defined(CONFIG_OS_WINDOWS)
#   if defined(_WCHAR_T_DEFINED) || defined(_NATIVE_WCHAR_T_DEFINED)
typedef wchar_t                 wchar_t;
#   else
typedef uint16             wchar_t;
#   endif
#elif defined(__WCHAR_TYPE__)
typedef __WCHAR_TYPE__              wchar_t;
#elif defined(__WCHAR_WIDTH__) && (__WCHAR_WIDTH__ == 2)
typedef int16                  wchar_t;
#elif defined(__WCHAR_WIDTH__) && (__WCHAR_WIDTH__ == 4)
typedef int32                  wchar_t;
#else
//typedef int32                  wchar_t;
#endif

/** int64 */
#if defined(X_COMPILER_IS_MSVC)
typedef __int64           int64;
typedef unsigned __int64  uint64;
#elif (defined(__LONG_WIDTH__) && __LONG_WIDTH__ == 8) || (defined(__SIZEOF_LONG__) && __SIZEOF_LONG__ == 8)
typedef signed long   int64;
typedef unsigned long uint64;
#else
typedef signed long long   int64;
typedef unsigned long long uint64;
#endif

// hong and hize
typedef int64  x_hont;
typedef uint64 x_hize;

// long and size
#if defined(X_CONFIG_OS_WINDOWS) && X_CPU_BIT64
typedef int64  x_long;
typedef uint64 x_ulong;
#else
typedef signed long x_long;
typedef unsigned long x_ulong;
#endif
typedef x_ulong x_size_t;

// integer pointer
typedef x_long  x_ptrdiff;
typedef x_ulong x_uintptr;

// fixed
typedef int32 fixed6;
typedef int32 fixed16;
typedef int32 fixed30;
typedef fixed16  fixed;

struct x_version
{
    byte major;
    byte minor;
    byte alter;
    x_hize build;
};
