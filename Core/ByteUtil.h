﻿#pragma once

#include <string>

#include "Type.h"

#define x_byte_swap16(x) static_cast<uint16>((((x) >> 8) & 0xff) | (((x) & 0xff) << 8))

#define x_byte_swap32(x) static_cast<uint32>((((x) & 0xff000000u) >> 24) \
   | (((x) & 0x00ff0000u) >> 8)	\
   | (((x) & 0x0000ff00u) << 8) \
   | (((x) & 0x000000ffu) << 24))

#define x_byte_swap64(x) static_cast<uint64>((((x) & 0xff00000000000000ull) >> 56)	\
   | (((x) & 0x00ff000000000000ull) >> 40)	\
   | (((x) & 0x0000ff0000000000ull) >> 24)	\
   | (((x) & 0x000000ff00000000ull) >> 8)	\
   | (((x) & 0x00000000ff000000ull) << 8)	\
   | (((x) & 0x0000000000ff0000ull) << 24)	\
   | (((x) & 0x000000000000ff00ull) << 40)	\
   | (((x) & 0x00000000000000ffull) << 56))


std::string x_readable_bytes(u64 n)
{

}

// 将字节流逐个序列化为16进制FF格式，空格分开，<num_per_line>换行，可用于debug显示
static std::string x_bytes_to_hex(const uint8 *buf, std::size_t len, std::size_t num_per_line=8, bool with_ascii=true)
{

}