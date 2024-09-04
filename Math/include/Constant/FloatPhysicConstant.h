#pragma once

namespace Math
{
	namespace Physics 
	{
		// https://physics.nist.gov/cuu/Constants/Table/allascii.txt
		constexpr float CommonLightSpeed = 300000000.0f;               // 光速
		constexpr float LightSpeed       = 299792458.0f;               // 光速
		constexpr float G                = 6.67384E-11f;               // 万有引力常数
		constexpr float g                = 9.80665f;                   // 地球重力加速度
		constexpr float AU               = 149597870895.265908536440f; // 日地平均距离
		constexpr float LightYear        = 9460730472580800.0f;        // 光年
		constexpr float Parsec           = 3.08567758149137E16f;       // 秒差距
		constexpr float H0               = 73520.0f;                   // 哈勃常数
		constexpr float HT               = 0.0f;                       // 哈勃时间
		constexpr float HL               = 0.0f;                       // 哈勃长度
		constexpr float HV               = 0.0f;                       // 哈勃体积
		
		constexpr float e                  = 1.602176634E-19f; // 基本电荷
		constexpr float eV                 = 1.602176634E-19f; // 电子伏特
		constexpr float Permittivity       = 8.854187817E-12f; // 真空电容率
		constexpr float VacuumPermeability = 1.256637061E-6f;  // 真空磁导率

		constexpr float k  = 1.380649E-23f;          // 玻尔兹曼常数
		constexpr float NA = 6.02214076E23f;         // 阿伏伽德罗常数
		constexpr float F  = 96485.3321233100184f;   // 法拉第常数
		constexpr float R  = 8.31446261815324f;      // 气体常数

		constexpr float h     = 6.62607015E-34f; // 普朗克常数
		constexpr float rh    = 1.05457180E-34f; // 约化普朗克常数
		constexpr float hl    = 1.616229E-35f;   // 普朗克长度
		constexpr double ht   = 5.39116E-44f;    // 普朗克时间
		constexpr float dirac = 0.0f;
		constexpr float BohrR = 5.2917721067E-11f;   // 波尔半径
		constexpr float alpha = 0.0072973525664f;    // 精细结构常数


	}
}
