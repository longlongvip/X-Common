#pragma once

#include "Compiler.h"
#include "BaseType.h"

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

    using s64 = long long;
    using u64 = unsigned long long;

#define int64_min LLONG_MIN
#define int64_max LLONG_MAX
#define uint64_min 0x0000000000000000
#define uint64_max ULLONG_MAX
#define s64_min LLONG_MIN
#define s64_max LLONG_MAX
#define u64_min 0x0000000000000000
#define u64_max ULLONG_MAX

#elif (defined(__LONG_WIDTH__) && __LONG_WIDTH__ == 8) || (defined(__SIZEOF_LONG__) && __SIZEOF_LONG__ == 8)
    using int64 = signed long;
    using uint64 =  unsigned long;

    using s64 = singned long;
    using u64 = unsigned long;

    #define int64_min LLONG_MIN
    #define int64_max LLONG_MAX
    #define uint64_min 0x0000000000000000
    #define uint64_max ULLONG_MAX
    #define s64_min LLONG_MIN
    #define s64_max LLONG_MAX
    #define u64_min 0x0000000000000000
    #define u64_max ULLONG_MAX
#else
    using int64 = signed long long;
    using int64 =  unsigned long long;

    using s64 = signed long long;
    using u64 = unsigned long long;

    #define int64_min LLONG_MIN
    #define int64_max LLONG_MAX
    #define uint64_min 0x0000000000000000
    #define uint64_max ULLONG_MAX
    #define s64_min LLONG_MIN
    #define s64_max LLONG_MAX
    #define u64_min 0x0000000000000000
    #define u64_max ULLONG_MAX
#endif
