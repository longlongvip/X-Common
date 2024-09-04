#pragma once

namespace Math 
{
/* 用于数值精度的魔法数字 */
constexpr float DELTA = 0.00001f;

// 归一化向量的长度（这些长度是最大值的一半 以确保归一化向量的点乘不会溢出）
constexpr float FLOAT_NORMAL_THRESH = 0.0001f;

// 数字精度的魔法数字
constexpr float THRESH_POINT_ON_PLANE =
    0.10f; /* 正面/背面/内部测试的平面厚度 */
constexpr float THRESH_POINT_ON_SIDE =
    0.20f; /* 多边形侧面的厚度，用于点内/外/内测试 */
constexpr float THRESH_POINTS_ARE_SAME = 0.00002f; /* 在此距离内的两点相同 */
constexpr float THRESH_POINTS_ARE_NEAR =
    0.015f; /* 如果两个点的距离在此范围内，那么这两个点就是近点，如果数学运算不精确，可以将这两个点合并起来
             */
constexpr float THRESH_NORMALS_ARE_SAME =
    0.00002f; /* 在此距离内的两个法线点是相同的 */
constexpr float THRESH_UVS_ARE_SAME =
    0.0009765625f; /* 如果两个 UV 值在 1.0f/1024f 的阈值范围内，则两个 UV 值相同
                    */
/* 过大会导致错误的 CSG 分类和灾难。 */
constexpr float THRESH_VECTORS_ARE_NEAR =
    0.0004f; /* 如果两个矢量的距离在这个范围内，那么它们就是近矢量，如果数学运算不精确，那么它们可以合并在一起。
              */
/* 纹理坐标不准确会导致照明问题。 */
constexpr float THRESH_SPLIT_POLY_WITH_PLANE = 0.25f; /* 平面将多边形一分为二 */
constexpr float THRESH_SPLIT_POLY_PRECISELY = 0.01f; /* 平面正好分割多边形 */
constexpr float THRESH_ZERO_NORM_SQUARED =
    0.0001f; /* 被视为 "零 "的单位正则的大小，平方  */

/* 如果 abs A 点乘 B; 大于或等于此值，则两个单位向量平行。这大致是余弦 1.0 度 */
constexpr float THRESH_NORMALS_ARE_PARALLEL = 0.999845f;
/* 如果 abs A 点乘 B 小于或等于此值，则两个单位向量垂直正交。这大致是余弦 89.0
 * 度 */
constexpr float THRESH_NORMALS_ARE_ORTHOGONAL = 0.017455f;

constexpr float THRESH_VECTOR_NORMALIZED =
    0.01f; /** 归一化矢量对平方幅度的允许误差 */
constexpr float THRESH_QUAT_NORMALIZED =
    0.01f; /** 归一化四元数对平方幅度的允许误差 */
} // namespace Math