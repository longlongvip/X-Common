#pragma once

#include "../Core.h"
#include "../MinMax.h"
#include "../Utils.h"

namespace Math
{
    struct Vec2
    {
        float x;
        float y;

        Vec2() : x(0.0f), y(0.0f) { }
        Vec2(float x_, float y_) : x(x_), y(y_) { }
        explicit Vec2(float v) : x(v), y(v) { }
        Vec2(const Vec2& vec) : x(vec.x), y(vec.y) { }

        Vec2 &operator-()
        {
            x = -x;
            y = -y;
            return *this;
        }

        Vec2 &operator+=(const Vec2 &v)
        {
            x += v.x;
            y += v.y;
            return *this;
        }

        Vec2 &operator-=(const Vec2 &v)
        {
            x -= v.x;
            y -= v.y;
            return *this;
        }

        Vec2 &operator*=(float s)
        {
            x *= s;
            y *= s;
            return *this;
        }

        Vec2 &operator/=(float s)
        {
            x /= s;
            y /= s;
            return *this;
        }

        Vec2 &operator*=(const Vec2 &v)
        {
            x *= v.x;
            y *= v.y;
            return *this;
        }

        Vec2 &operator/=(const Vec2 &v)
        {
            x /= v.x;
            y /= v.y;
            return *this;
        }

        /* 获得 Vec2 特定的组件 */
        float &operator[](const int idx)
        {
            if(idx == 0)
            {
                return x;
            }
            return y;
        }

        /* 获得 Vec2 特定的组件 */
        float operator[](const int idx) const
        {
            if(idx == 0)
            {
                return x;
            }
            return y;
        }

        /* 清 0 */
        void zero()
        {
            x = 0.0f;
            y = 0.0f;
        }

        /* 绕 (0, 0) 旋转 */
        void rotate(float deg)
        {
            float rad = deg_to_rad(deg);
            float c = cos(rad);
            float s = sin(rad);
            float tx = x * c - y * s;
            float ty = x * s + y * c;
            x = tx;
            y = ty;
        }

        /* 绕 (x, y) 旋转 */
        void rotate(float x_, float y_, float deg)
        {
            float rad = deg_to_rad(deg);
            float c = cos(rad);
            float s = sin(rad);
            float tx = x * c - y * s;
            float ty = x * s + y * c;
            x = tx + x_;
            y = ty + y_;
        }

        /* Vec2 标准化 */
        void normalize()
        {
            float vec_len = sqrtf(x * x + y * y);
            x /= vec_len;
            y /= vec_len;
        }
    };

    /* 获取 Vec2 的标准化结果 */
    Vec2 safeNormalize(const Vec2& vec)
    {
        float vec_len = len(vec);
        return { vec.x / vec_len, vec.y / vec_len };
    }

    /* 获取 Vec2 的左-法向量 */
    Vec2 leftNormal(const Vec2& vec)
    {
        return { -vec.y, vec.x };
    }

    /* 获取 Vec2 的右-法向量 */
    Vec2 rightNormal(const Vec2& vec)
    {
        return { vec.y, -vec.x };
    }

    /* 获取该 Vec2 与另一个 Vec2 分量相加的结果 */
    Vec2 operator+(const Vec2& lhs, const Vec2& rhs)
    {
        return { lhs.x + rhs.x, lhs.y + rhs.y };
    }

    /* 获取 Vec2 每个分量加上一个值的结果 */
    Vec2 operator+(const Vec2& vec, float v)
    {
        return { vec.x + v, vec.y + v };
    }

    /* 获取 Vec2 每个分量相反的结果 */
    Vec2 operator-(const Vec2& vec)
    {
        return { -vec.x, -vec.y };
    }

    /* 获取该 Vec2 与另一个 Vec2 分量相减的结果 */
    Vec2 operator-(const Vec2& lhs, const Vec2& rhs)
    {
        return { lhs.x - rhs.x, lhs.y - rhs.y };
    }

    /* 获取 Vec2 每个分量减去一个值的结果 */
    Vec2 operator-(const Vec2& vec, float v)
    {
        return { vec.x - v, vec.y - v };
    }

    /* 获取 Vec2 每个分量乘以一个值的结果 */
    Vec2 operator*(const Vec2& vec, float v)
    {
        return { vec.x * v, vec.y * v };
    }

    /* 获取 一个值 乘以 Vec2 每个分量的结果 */
    Vec2 operator*(float v, const Vec2 &vec)
    {
        return {vec.x * v, vec.y * v };
    }

    /* 获取 Vec2 每个分量除以一个值的结果 */
    Vec2 operator/(const Vec2& vec, float v)
    {
        return { vec.x / v, vec.y / v };
    }

    /* 获取该 Vec2 与另一个 Vec2 分量相乘的结果 */
    Vec2 operator*(const Vec2& lhs, const Vec2& rhs)
    {
        return { lhs.x * rhs.x, lhs.y * rhs.y };
    }

    /* 获取该 Vec2 与另一个 Vec2 分量相除的结果 */
    Vec2 operator/(const Vec2& lhs, const Vec2& rhs)
    {
        return { lhs.x / rhs.x, lhs.y / rhs.y };
    }

    /* 计算此 Vec2 与另一个 Vec2 的点积 */
    float dot(const Vec2& lhs, const Vec2& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    /* 计算此 Vec2 与另一个 Vec2 的叉乘 */
    float cross(const Vec2& lhs, const Vec2& rhs)
    {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    /* 判断此 Vec2 与另一个 Vec2 是否相等 */
    bool operator==(const Vec2& lhs, const Vec2& rhs)
    {
        return Compare::equal(lhs.x, rhs.x) && Compare::equal(lhs.y, rhs.y);
    }

    /* 判断此 Vec2 与另一个 Vec2 是否不等 */
    bool operator!=(const Vec2& lhs, const Vec2& rhs)
    {
        return Compare::unequal(lhs.x, rhs.x) || Compare::unequal(lhs.y, rhs.y);
    }

    /* Vec2 的长度/模 的平方 */
    float len2(const Vec2& vec)
    {
        return vec.x *  vec.x +  vec.y *  vec.y;
    }

    /* Vec2 的长度/模 */
    float len(const Vec2& vec)
    {
        return sqrt( vec.x *  vec.x +  vec.y *  vec.y);
    }

    /* 获取 Vec2 组件的最大值 */
    float getMax(const Vec2& vec)
    {
        return Compare::max(vec.x, vec.y);
    }

    /* 获取 Vec2 分量的最大绝对值 */
    float getAbsMax(const Vec2& vec)
    {
        return Compare::max(std::abs(vec.x), std::abs(vec.y));
    }

    /* 获取 Vec2 组件的最小值 */
    float getMin(const Vec2& vec)
    {
        return Compare::min(vec.x, vec.y);
    }

    /* 获取 Vec2 组件的绝对值 */
    Vec2 abs(const Vec2& vec)
    {
        return { std::abs(vec.x), std::abs(vec.y) };
    }

    /* 绕 (0, 0) 旋转 */
    Vec2 rotate(const Vec2& vec, const float deg)
    {
        float rad = deg_to_rad(deg);
        float c = cos(rad);
        float s = sin(rad);
        float tx = vec.x * c - vec.y * s;
        float ty = vec.x * s + vec.y * c;
        return { tx, ty };
    }

    /* 绕 (x, y) 旋转 */
    Vec2 rotate(const Vec2& vec, float x, float y, float deg)
    {
        float rad = deg_to_rad(deg);
        float c = cos(rad);
        float s = sin(rad);
        float tx = vec.x * c - vec.y * s;
        float ty = vec.x * s + vec.y * c;
        return { tx + x, ty + y };
    }

    /* Vec2 字符串化 */
    std::string to_string(const Vec2& vec)
    {
        // Todo
    }

    /* 全局 Vec2 常量 (0, 0) */
    extern const Vec2 Zero = { 0.0f, 0.0f };
    extern const Vec2 One = { 1.0f, 1.0f };
    extern const Vec2 Unit45Deg = { sqrtf(0.5f), sqrtf(0.5f) };
    extern const Vec2 Left = { -1.0f, 0.0f };
    extern const Vec2 Up = { 0.0f, 1.0f };
    extern const Vec2 Right = { 1.0f, 0.0f };
    extern const Vec2 Down = { 0.0f, -1.0f };
}
