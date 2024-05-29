#pragma once

#include "Type.h"

using x_void = void;
using x_pointer = void*;
using x_const_pointer = const void*;
using x_handle = x_pointer;

// null
#ifdef __cplusplus
#   define x_null (0)
# else
#   define x_null (x_pointer)(0)
#endif

// 无参数
#ifdef __cplusplus
#   define x_noarg
#else
#   define x_noarg x_void
#endif

// integer pointer
using x_ptrdiff = int64;
using x_uintptr = uint64;

// fixed
using fixed6 = int32;
using fixed16 = int32;
using fixed30 = int32;
using fixed = fixed16;

struct x_version
{
    byte major;
    byte minor;
    byte alter;
    int64 build;
};
