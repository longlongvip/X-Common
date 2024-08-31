#pragma once

#include "../Core.h"
#include "../MinMax.h"
#include "../Utils.h"

namespace Math
{
    struct Vec4
    {
        float x;
        float y;
        float z;
        float w;

        Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
        Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) { }
        explicit Vec4(float v) : x(v), y(v), z(v), w(v) { }
        explicit Vec4(const Vec4& vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) { }

        Vec4 &operator-()
        {
            x = -x;
            y = -y;
            z = -z;
            w = -w;
            return *this;
        }

        Vec4 &operator+=(const Vec4 &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            w += v.w;
            return *this;
        }

        Vec4 &operator-=(const Vec4 &v)
        {
            x -= v.x;
            y -= v.y;
            z -= v.z;
            w -= v.w;
            return *this;
        }

        Vec4 &operator*=(float s)
        {
            x *= s;
            y *= s;
            z *= s;
            w *= s;
            return *this;
        }

        Vec4 &operator/=(float s)
        {
            x /= s;
            y /= s;
            z /= s;
            w /= s;
            return *this;
        }

        Vec4 &operator*=(const Vec4 &v)
        {
            x *= v.x;
            y *= v.y;
            z *= v.z;
            w *= v.w;
            return *this;
        }

        Vec4 &operator/=(const Vec4 &v)
        {
            x /= v.x;
            y /= v.y;
            z /= v.z;
            w /= v.w;
            return *this;
        }

        /* 获得 Vec4 特定的组件 */
        float &operator[](const int idx)
        {
            if(idx == 0)
            {
                return x;
            }
            if(idx == 1)
            {
                return y;
            }
            if(idx == 2)
            {
                return z;
            }
            return w;
        }

        /* 获得 Vec4 特定的组件 */
        float operator[](const int idx) const
        {
            if(idx == 0)
            {
                return x;
            }
            if(idx == 1)
            {
                return y;
            }
            if(idx == 2)
            {
                return z;
            }
            if(idx == 3)
            {
                return w;
            }
        }

        /* Vec4 标准化 */
        void normalize()
        {
            float vec_len = sqrtf(x * x + y * y + z * z + w * w);
            x /= vec_len;
            y /= vec_len;
            z /= vec_len;
            w /= vec_len;
        }
    };

    /* 获取 Vec4 的标准化结果 */
    Vec4 safeNormalize(const Vec4& vec)
    {
        float vec_len = len(vec);
        return { vec.x / vec_len, vec.y / vec_len, vec.z / vec_len, vec.w / vec_len };
    }

    /* 获取该 Vec4 与另一个 Vec4 分量相加的结果 */
    Vec4 operator+(const Vec4& lhs, const Vec4& rhs)
    {
        return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w };
    }

    /* 获取 Vec4 每个分量加上一个值的结果 */
    Vec4 operator+(const Vec4& vec, float v)
    {
        return { vec.x + v, vec.y + v, vec.z + v, vec.w + v };
    }

    /* 获取 Vec4 每个分量相反的结果 */
    Vec4 operator-(const Vec4& vec)
    {
        return { -vec.x, -vec.y, -vec.z, -vec.w };
    }

    /* 获取该 Vec4 与另一个 Vec4 分量相减的结果 */
    Vec4 operator-(const Vec4& lhs, const Vec4& rhs)
    {
        return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w + rhs.w };
    }

    /* 获取 Vec4 每个分量减去一个值的结果 */
    Vec4 operator-(const Vec4& vec, float v)
    {
        return { vec.x - v, vec.y - v, vec.z - v, vec.w - v };
    }

    /* 获取 Vec4 每个分量乘以一个值的结果 */
    Vec4 operator*(const Vec4& vec, float v)
    {
        return { vec.x * v, vec.y * v, vec.z * v, vec.w * v };
    }

    /* 获取 一个值 乘以 Vec4 每个分量的结果 */
    Vec4 operator*(float v, const Vec4 &vec)
    {
        return {vec.x * v, vec.y * v, vec.z * v, vec.w * v };
    }

    /* 获取 Vec4 每个分量除以一个值的结果 */
    Vec4 operator/(const Vec4& vec, float v)
    {
        return { vec.x / v, vec.y / v, vec.z / v, vec.w / v };
    }

    /* 获取该 Vec4 与另一个 Vec4 分量相乘的结果 */
    Vec4 operator*(const Vec4& lhs, const Vec4& rhs)
    {
        return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w };
    }

    /* 获取该 Vec4 与另一个 Vec4 分量相除的结果 */
    Vec4 operator/(const Vec4& lhs, const Vec4& rhs)
    {
        return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z, lhs.w / rhs.w };
    }

    /* 计算此 Vec4 与另一个 Vec4 的点积 */
    float dot(const Vec4& lhs, const Vec4& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
    }

    /* 判断此 Vec4 与另一个 Vec4 是否相等 */
    bool operator==(const Vec4& lhs, const Vec4& rhs)
    {
        return Compare::equal(lhs.x, rhs.x) && Compare::equal(lhs.y, rhs.y) && Compare::equal(lhs.z, rhs.z) && Compare::equal(lhs.w, rhs.w);
    }

    /* 判断此 Vec4 与另一个 Vec4 是否不等 */
    bool operator!=(const Vec4& lhs, const Vec4& rhs)
    {
        return Compare::unequal(lhs.x, rhs.x) || Compare::unequal(lhs.y, rhs.y) || Compare::unequal(lhs.z, rhs.z) || Compare::unequal(lhs.w, rhs.w);
    }

    /* Vec4 的长度/模 的平方 */
    float len2(const Vec4& vec)
    {
        return vec.x *  vec.x +  vec.y *  vec.y + vec.z *  vec.z + vec.w * vec.w;
    }

    /* Vec4 的长度/模值 */
    float len(const Vec4& vec)
    {
        return sqrtf( vec.x *  vec.x +  vec.y * vec.y +  vec.z * vec.z + vec.w * vec.w);
    }

    /* 获取 Vec4 组件的最大值 */
    float getMax(const Vec4& vec)
    {
        return Compare::max4(vec.x, vec.y, vec.z, vec.w);
    }

    /* 获取 Vec4 分量的最大绝对值 */
    float getAbsMax(const Vec4& vec)
    {
        return Compare::max4(std::abs(vec.x), std::abs(vec.y), std::abs(vec.z), std::abs(vec.w));
    }

    /* 获取 Vec4 组件的最小值 */
    float getMin(const Vec4& vec)
    {
        return Compare::min4(vec.x, vec.y, vec.z, vec.w);
    }

    /* 获取 Vec4 组件的绝对值 */
    Vec4 abs(const Vec4& vec)
    {
        return { std::abs(vec.x), std::abs(vec.y), std::abs(vec.z), std::abs(vec.w) };
    }

    /* Vec4 字符串化 */
    std::string to_string(const Vec4& vec)
    {
        // Todo
    }

    /* 全局 Vec4 常量 (0, 0) */
    extern const Vec4 Zero = { 0.0f, 0.0f, 0.0f, 0.0f };
    extern const Vec4 One =  { 1.0f, 1.0f, 1.0f, 1.0f };
}
