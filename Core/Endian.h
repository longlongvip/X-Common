#pragma once

#include "ByteUtil.h"

constexpr int LITTLE_ENDIAN = 1234;
constexpr int BIG_ENDIAN    = 4321;
constexpr int ENDIAN_NESS   = LITTLE_ENDIAN;

bool check_local_if_le();
bool check_local_if_le()
{
    // 检测本地设备是小端还是大端
    int val=1;
    int8 *p = reinterpret_cast<int8*>(&val);
    return *p == 1;
}

#if ENDIAN_NESS == LITTLE_ENDIAN
#   define x_htobe16(x) x_byte_swap16(x)
#   define x_htole16(x) (x)
#   define x_be16toh(x) x_byte_swap16(x)
#   define x_le16toh(x) (x)

#   define x_htobe32(x) x_byte_swap32(x)
#   define x_htole32(x) (x)
#   define x_be32toh(x) x_byte_swap32(x)
#   define x_le32toh(x) (x)

#   define x_htobe64(x) x_byte_swap64(x)
#   define x_htole64(x) (x)
#   define x_be64toh(x) x_byte_swap64(x)
#   define x_le64toh(x) (x)

#else
#   define x_htobe16(x) (x)
#   define x_htole16(x) x_byte_swap16(x)
#   define x_be16toh(x) (x)
#   define x_le16toh(x) x_byte_swap16(x)

#   define x_htobe32(x) (x)
#   define x_htole32(x) x_byte_swap32(x)
#   define x_be32toh(x) (x)
#   define x_le32toh(x) x_byte_swap32(x)

#   define x_htobe64(x) (x)
#   define x_htole64(x) x_byte_swap64(x)
#   define x_be64toh(x) (x)
#   define x_le64toh(x) x_byte_swap64(x)
#endif
