#pragma once

#if defined(X_COMPILER_IS_MSVC)
#   define X_ASSEMBLER_IS_MASM
#elif defined(X_COMPILER_IS_GCC)||defined(X_COMPILER_IS_CLANG)
#   define X_ASSEMBLER_IS_GAS
#endif
