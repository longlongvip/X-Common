#pragma once

#include "compiler.h"
#include "cpu.h"

#define x_volatile  volatile

#if defined(X_COMPILER_IS_SVC)
#   ifdef(_DEBUG)
#       define x_debug
#   endif
#   define x_func             __FUNCTION__
#   define x_file             __FILE__
#   define x_line             __LINE__
#   define x_date             __DATE__
#   define x_time             __TIME__
#   define x_asm              __asm
#   define x_inline           __inline
#   define x_inline_force     __forceinline
#   define x_cdecl            __cdecl
#   define x_stdcall          __stdcall
#   define x_fastcall         __fastcall
#   define x_thiscall         __thiscall
#   define x_packed__
#   define x_aligned(a)     __declspec(align(a))
#endif

#if (X_CPU_BIT_BYTE == 8)
#   define x_cpu_aligned   x_aligned(8)
#elif (X_CPU_BIT_BYTE == 4)
#   define x_cpu_aligned   x_aligned(4)
#elif (X_CPU_BIT_BYTE == 2)
#   define x_cpu_aligned   x_aligned(2)
#else
#   error unknown cpu bytes
#endif

/** like */
#   define x_likely(x)   (x)
#   define x_unlikely(x) (x)

#ifdef x_debug
#   define x_debug_decl  , char const* func_, size_t line_, char const* file_
#   define x_debug_vals  , x_func, x_line, x_file
#   define x_debug_args  , func_, line_, file_
#else
#   define x_debug_decl
#   define x_debug_vals
#   define x_debug_args
#endif

/** small */
#ifdef X_CONFIG_SMALL
#   define x_small
#endif

/** newline */
#ifdef X_CONFIG_OS_WINDOWS
#   define x_newline  "\r\n"
#else
#   define x_newline  "\n"
#endif

/** 该字符串仅适用于大型模式 */
#ifdef x_small
#   define x_large_string(x) x_null
#else
#   define x_large_string(x) x
#endif

/** 仅用于调试模式的字符串 */
#ifdef x_debug
#   define x_debug_string(x) x
#else
#   define x_debug_string(x) x_null
#endif

/** extern C */
#ifdef __cplusplus
#   define x_extern_c extern "C"
#   define x_extern_c_enter extern "C" {
#   define x_extern_c_leave }
#else
#   define x_extern_c
#   define x_extern_c_enter
#   define x_extern_c_leave
#endif

/** 导出动态链接库 */
#if defined(X_COMPILER_IS_SVC)
#   define x_export  __declspec(dllexport)
#elif defined(TB_COMPILER_IS_GCC) && ((__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_INOR__ >= 3))
#   define x_export  __attribute((visibility("default")))
#else
#   define x_export
#endif

// has feature
#ifdef has_feature
#   define x_has_feature(x) __has_feature(x)
#else
#   define x_has_feature(x) 0
#endif

// has include
#ifdef has_include
#   define x_has_include(x) __has_include(x)
#else
#   define x_has_include(x) 0
#endif

// has builtin
#ifdef has_builtin
#   define x_has_builtin(x) __has_builtin(x)
#else
#   define x_has_builtin(x) 0
#endif

// no_sanitize_address
#if x_has_feature(address_sanitizer) || defined(__SANITIZE_ADDRESS__)
#   define x_no_sanitize_address__                       __attribute((no_sanitize_address))
#else
#   define x_no_sanitize_address__
#endif

// thread local
#if x_has_feature(c_thread_local)
#   define x_thread_local__                              _Thread_local
#elif defined(TB_CONFIG_KEYWORD_HAVE_Thread_local)
#   define x_thread_local__                              _Thread_local
#elif defined(TB_CONFIG_KEYWORD_HAVE__thread)
#   define x_thread_local__                              __thread
#elif defined(TB_COMPILER_IS_SVC) || defined(TB_COMPILER_IS_BORLAND)
#   define x_thread_local__                              __declspec(thread)
#endif

/* c function overloadable
 *
 * @code
    static __tb_inline__ tb_void_t test(tb_int_t a) __tb_overloadable__
    {
        tb_trace_i("test1: %d", a);
    }
    static __tb_inline__ tb_void_t test(tb_int_t a, tb_int_t b) __tb_overloadable__
    {
        tb_trace_i("test2: %d %d", a, b);
    }
 * @endcode
 *
 * If the compiler does not support __tb_overloadable__, we can use the following code to implement function overload.
 *
 * @code
    #define test_n(a, b, ...) test_impl(a, b)
    #define test(a, args ...) test_n(a, ##args, 0, 0, 0)
    static __tb_inline__ tb_void_t test_impl(tb_int_t a, tb_int_t b)
    {
        tb_trace_i("test: %d %d", a, b);
    }

    test(1);
    test(1, 2);
 * @endcode
 */
#if defined(TB_COMPILER_IS_GCC) || defined(TB_COMPILER_IS_CLANG)
#   define x_overloadable__                              __attribute((overloadable))
#else
#   define x_overloadable__
#endif

/*! the type reference keyword for defining tb_xxxx_ref_t
 *
 * typedef x_typeref(xxxx);
 *
 *
 * suppress gcc 4.9 on c++ codes warning: 'x_yyyy_t' has a field 'x_yyyy_t::xxxx' whose type uses the anonymous namespace
 *
 * @code
 *
   typedef struct{}*    tb_xxxx_ref_t;

   typedef struct x_yyyy_t
   {
       tb_xxxx_ref_t    xxxx;

   }x_yyyy_t;

 *
 *
 * @endcode
 *
 */
#define x_typeref(object)                              struct x_##object##_dummy_t{tb_int_t dummy;} const* tb_##object##_ref_t

 // 宏
#define x_string(x)                                   #x
#define x_string_ex(x)                                x_string(x)

#define x_concat(a, b)                                a##b
#define x_concat_ex(a, b)                             x_concat(a, b)

#define x_concat3(a, b, c)                            a##b##c
#define x_concat3_ex(a, b, c)                         x_concat3(a, b, c)

#define x_concat4(a, b, c, d)                         a##b##c##d
#define x_concat4_ex(a, b, c, d)                      x_concat4(a, b, c, d)

#define x_concat5(a, b, c, d, e)                      a##b##c##d##e
#define x_concat5_ex(a, b, c, d, e)                   x_concat5(a, b, c, d, e)

#define x_concat6(a, b, c, d, e, f)                   a##b##c##d##e##f
#define x_concat6_ex(a, b, c, d, e, f)                x_concat6(a, b, c, d, e, f)

#define x_concat7(a, b, c, d, e, f, g)                a##b##c##d##e##f##g
#define x_concat7_ex(a, b, c, d, e, f, g)             x_concat7(a, b, c, d, e, f, g)

#define x_concat8(a, b, c, d, e, f, g, h)             a##b##c##d##e##f##g##h
#define x_concat8_ex(a, b, c, d, e, f, g, h)          x_concat8(a, b, c, d, e, f, g, h)

#define x_concat9(a, b, c, d, e, f, g, h, i)          a##b##c##d##e##f##g##h##i
#define x_concat9_ex(a, b, c, d, e, f, g, h, i)       x_concat9(a, b, c, d, e, f, g, h, i)

#define x_strcat(a, b)                                a b
#define x_strcat3(a, b, c)                            a b c
#define x_strcat4(a, b, c, d)                         a b c d
#define x_strcat5(a, b, c, d, e)                      a b c d e
#define x_strcat6(a, b, c, d, e, f)                   a b c d e f
#define x_strcat7(a, b, c, d, e, f, g)                a b c d e f g
#define x_strcat8(a, b, c, d, e, f, g, h)             a b c d e f g h
#define x_strcat9(a, b, c, d, e, f, g, h, i)          a b c d e f g h i
