#pragma once

/** 一些用于制作版本字符串的帮助宏 */
#define x_string(x) #x
#define x_string_ex(x) x_string(x)


#if defined(_MSC_VER)
#   define X_COMPILER_IS_MSVC
#   define X_COMPILER_VERSION_BT(major, minor)     (_MSC_VER > ((major) * 100 + (minor)))
#   define X_COMPILER_VERSION_BE(major, minor)     (_MSC_VER >= ((major) * 100 + (minor)))
#   define X_COMPILER_VERSION_EQ(major, minor)     (_MSC_VER == ((major) * 100 + (minor)))
#   define X_COMPILER_VERSION_LT(major, minor)     (_MSC_VER < ((major) * 100 + (minor)))
#   define X_COMPILER_VERSION_LE(major, minor)     (_MSC_VER <= ((major) * 100 + (minor)))
#       define X_COMPILER_STRING                   "visual c++"
#   if defined(X_FORCE_MSVC_4_2) && (_MSC_VER == 1020)
#       define X_COMPILER_VERSION_STRING           "visual c++ 4.2"
#   elif (_MSC_VER == 1100)
#       define X_COMPILER_VERSION_STRING           "visual c++ 5.0"
#   elif (_MSC_VER == 1200)
#       define X_COMPILER_VERSION_STRING           "visual c++ 6.0"
#   elif (_MSC_VER == 1300)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net (7.0)"
#   elif (_MSC_VER == 1310)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net 2003 (7.1)"
#   elif (_MSC_VER == 1400)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net 2005 (8.0)"
#   elif (_MSC_VER == 1500)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net 2008 (9.0)"
#   elif (_MSC_VER == 1600)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net 2010 (10.0)"
#   elif (_MSC_VER == 1700)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net 2012 (11.0)"
#   elif (_MSC_VER == 1800)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net 2013 (12.0)"
#   elif (_MSC_VER == 1900)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net 2015 (14.0)"
#   elif (_MSC_VER == 1910 || _MSC_VER == 1911)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net 2017 (14.1)"
#   elif (_MSC_VER == 1920)
#       define X_COMPILER_VERSION_STRING           "visual c++ .net 2019 (16.0)"
#   else
#       define X_COMPILER_VERSION_STRING           "unknown visual c++ compiler"
#   endif

// suppress warning
#   pragma warning(disable:4018)
#   pragma warning(disable:4197)
#   pragma warning(disable:4141)
#   pragma warning(disable:4996)
#   pragma warning(disable:4359)
#   pragma warning(disable:4838)

#else
#   define X_COMPILER_STRING                       "unknown compiler"
#   define X_COMPILER_VERSION_STRING               "unknown compiler version"
#   define X_COMPILER_IS_UNKNOWN
#endif
