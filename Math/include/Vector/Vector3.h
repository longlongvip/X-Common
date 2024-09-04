#pragma once

#include "../Core.h"
#include "../MinMax.h"
#include "../Utils.h"

namespace Math
{
	struct Vec3
	{
		float x;
        float y;
        float z;

		Vec3() : x(0.0f), y(0.0f), z(0.0f) { }
		Vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_) { }
		explicit Vec3(float v) : x(v), y(v), z(v) { }
		Vec3(const Vec3& vec) : x(vec.x), y(vec.y), z(vec.z) { }

		Vec3 &operator-()
		{
			x = -x;
			y = -y;
			z = -z;
			return *this;
		}

		Vec3 &operator+=(const Vec3 &v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			return *this;
		}

		Vec3 &operator-=(const Vec3 &v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			return *this;
		}

		Vec3 &operator*=(float s)
		{
			x *= s;
			y *= s;
			z *= s;
			return *this;
		}

		Vec3 &operator/=(float s)
		{
			x /= s;
			y /= s;
			z /= s;
			return *this;
		}

		Vec3 &operator*=(const Vec3 &v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			return *this;
		}

		Vec3 &operator/=(const Vec3 &v)
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;
			return *this;
		}

		/* 获得 Vec3 特定的组件 */
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
            return z;
		}

		/* 获得 Vec3 特定的组件 */
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
            return z;
		}
        
		/* 绕 x 轴 (1, 0, 0) 旋转 */
		void rotateX(const float deg)
		{
			float rad = deg_to_rad(deg);
			float c = cos(rad);
			float s = sin(rad);
			float ty = y * c - z * s;
			float tz = y * s + z * c;
			y = ty;
			z = tz;
		}
        
		/* 绕 y 轴 (0, 1, 0) 旋转 */
		void rotateY(const float deg)
		{
			float rad = deg_to_rad(deg);
			float c = cos(rad);
			float s = sin(rad);
			float tx = x * c - z * s;
			float tz = x * s + z * c;
			x = tx;
            z = tz;
		}
        
		/* 绕 z 轴 (0,0,1) 旋转 */
		void rotatedZ(const float deg)
		{
			float rad = deg_to_rad(deg);
			float c = cos(rad);
			float s = sin(rad);
			float tx = x * c - y * s;
			float ty = x * s + y * c;
			x = tx;
			y = ty;
		}
        
        /* Vec3 标准化 */
        void normalize()
        {
            float vec_len = sqrtf(x * x + y * y + z * z);
            x /= vec_len;
            y /= vec_len;
            z /= vec_len;
        }
	};

    /* 获取 Vec3 的标准化结果 */
    Vec3 safeNormalize(const Vec3& vec)
    {
        float vec_len = len(vec);
        return { vec.x / vec_len, vec.y / vec_len, vec.z / vec_len };
    }

    /* 获取该 Vec3 与另一个 Vec3 分量相加的结果 */
    Vec3 operator+(const Vec3& lhs, const Vec3& rhs)
    {
        return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
    }

    /* 获取 Vec3 每个分量加上一个值的结果 */
    Vec3 operator+(const Vec3& vec, float v)
    {
        return { vec.x + v, vec.y + v, vec.z + v };
    }

    /* 获取 Vec3 每个分量相反的结果 */
    Vec3 operator-(const Vec3& vec)
    {
        return { -vec.x, -vec.y, -vec.z };
    }

    /* 获取该 Vec3 与另一个 Vec3 分量相减的结果 */
    Vec3 operator-(const Vec3& lhs, const Vec3& rhs)
    {
        return { lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
    }

    /* 获取 Vec3 每个分量减去一个值的结果 */
    Vec3 operator-(const Vec3& vec, float v)
    {
        return { vec.x - v, vec.y - v, vec.z - v };
    }

    /* 获取 Vec3 每个分量乘以一个值的结果 */
    Vec3 operator*(const Vec3& vec, float v)
    {
        return { vec.x * v, vec.y * v, vec.z * v };
    }

    /* 获取 一个值 乘以 Vec3 每个分量的结果 */
    Vec3 operator*(float v, const Vec3 &vec)
    {
        return {vec.x * v, vec.y * v, vec.z * v };
    }

    /* 获取 Vec3 每个分量除以一个值的结果 */
    Vec3 operator/(const Vec3& vec, float v)
    {
        return { vec.x / v, vec.y / v, vec.z / v };
    }

    /* 获取该 Vec3 与另一个 Vec3 分量相乘的结果 */
    Vec3 operator*(const Vec3& lhs, const Vec3& rhs)
    {
        return { lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
    }

    /* 获取该 Vec3 与另一个 Vec3 分量相除的结果 */
    Vec3 operator/(const Vec3& lhs, const Vec3& rhs)
    {
        return { lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z };
    }

    /* 计算此 Vec3 与另一个 Vec3 的点积 */
    float dot(const Vec3& lhs, const Vec3& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
    }

    /* 计算此 Vec3 与另一个 Vec3 的叉乘 */
    Vec3 cross(const Vec3& lhs, const Vec3& rhs)
    {
        float tx = lhs.y * rhs.z - lhs.z * rhs.y;
        float ty = lhs.z * rhs.x - lhs.z * rhs.z;
        float tz = lhs.x * rhs.y - lhs.y * rhs.x;
        return { tx, ty, tz };
    }

    /* 判断此 Vec3 与另一个 Vec3 是否相等 */
    bool operator==(const Vec3& lhs, const Vec3& rhs)
    {
        return Compare::equal(lhs.x, rhs.x) && Compare::equal(lhs.y, rhs.y) && Compare::equal(lhs.z, rhs.z);
    }

    /* 判断此 Vec3 与另一个 Vec3 是否不等 */
    bool operator!=(const Vec3& lhs, const Vec3& rhs)
    {
        return Compare::unequal(lhs.x, rhs.x) || Compare::unequal(lhs.y, rhs.y) || Compare::unequal(lhs.z, rhs.z);
    }

    /* Vec3 的长度/模 的平方 */
    float len2(const Vec3& vec)
    {
        return vec.x *  vec.x +  vec.y *  vec.y +  vec.z *  vec.z;
    }

    /* Vec3 的长度/模值 */
    float len(const Vec3& vec)
    {
        return sqrt( vec.x *  vec.x +  vec.y *  vec.y +  vec.z *  vec.z);
    }

    /* 获取 Vec3 组件的最大值 */
    float getMax(const Vec3& vec)
    {
        return Compare::max3(vec.x, vec.y, vec.z);
    }

    /* 获取 Vec3 分量的最大绝对值 */
    float getAbsMax(const Vec3& vec)
    {
        return Compare::max3(std::abs(vec.x), std::abs(vec.y), std::abs(vec.z));
    }

    /* 获取 Vec3 组件的最小值 */
    float getMin(const Vec3& vec)
    {
        return Compare::min3(vec.x, vec.y, vec.z);
    }

    /* 获取 Vec3 组件的绝对值 */
    Vec3 abs(const Vec3& vec)
    {
        return { std::abs(vec.x), std::abs(vec.y), std::abs(vec.z) };
    }

    /* 绕 x 轴 (1, 0, 0) 旋转 */
    Vec3 rotateX(const float deg)
    {
        float rad = deg_to_rad(deg);
        float c = cos(rad);
        float s = sin(rad);
        float ty = y * c - z * s;
        float tz = y * s + z * c;
        return { x, ty, tz };
    }

    /* 绕 y 轴 (0, 1, 0) 旋转 */
    Vec3 rotateY(const float deg)
    {
        float rad = deg_to_rad(deg);
        float c = cos(rad);
        float s = sin(rad);
        float tx = x * c - z * s;
        float tz = x * s + z * c;
        return { tx, y, tz };
    }

    /* 绕 z 轴 (0, 0, 1) 旋转 */
    Vec3 rotateZ(const float deg)
    {
        float rad = deg_to_rad(deg);
        float c = cos(rad);
        float s = sin(rad);
        float tx = x * c - y * s;
        float ty = x * s + y * c;
        return { tx, ty, z };
    }

    /* Vec3 字符串化 */
    std::string to_string(const Vec3& vec)
    {
        // Todo
    }

    /* 全局 Vec3 常量 (0, 0) */
    extern const Vec3 Zero = { 0.0f, 0.0f, 0.0f };
    extern const Vec3 One =  { 1.0f, 1.0f, 1.0f };;
    extern const Vec3 Unit45Deg = { sqrtf(0.5f), sqrtf(0.5f), sqrtf(0.5f) };
    extern const Vec3 Left = { 0.0f, -1.0f, 0.0f };
    extern const Vec3 Up = { 0.0f, 0.0f, 1.0f };
    extern const Vec3 Right = { 0.0f, 1.0f, 0.0f };
    extern const Vec3 Down = { 0.0f, 0.0f, -1.0f };
    extern const Vec3 Front = { 1.0f, 0.0f, 0.0f };
    extern const Vec3 Back = { -1.0f, 0.0f, 0.0f };
}
