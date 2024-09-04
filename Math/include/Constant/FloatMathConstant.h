#pragma once

namespace Math 
{
	constexpr float Float_Max = 3.402823466e+38f; // float 最大值
	constexpr float Float_Eps = 1.192092896e-07f; // float 误差
	constexpr float Small_Float_Eps      = 0.0001f;   // float 小误差
	constexpr float Float_Non_Fractional = 8388608.f; // 所有大于或等于此值的单精度浮点数没有小数值

	constexpr float One_Two    = 0.50000000000000000000000000000000f;  // 1/2
	constexpr float One_Three  = 0.33333333333333333333333333333333f;  // 1/3
	constexpr float Two_Three  = 0.66666666666666666666666666666666f;  // 2/3
	constexpr float One_Four   = 0.25000000000000000000000000000000f;  // 1/4
	constexpr float Three_Four = 0.75000000000000000000000000000000f;  // 3/4
	constexpr float One_six    = 0.16666666666666666666666666666666f;  // 1/6

	constexpr float Sqrt2         = 1.4142135623730950488016887242097f;  // 根号2
	constexpr float Sqrt3         = 1.7320508075688772935274463415059f;  // 根号3
	constexpr float Sqrt5         = 2.2360679774997896964091736687312f;  // 根号5
	constexpr float One_Div_Sqrt2 = 0.70710678118654752440084436210485f; // 1/根号2
	constexpr float One_Div_Sqrt3 = 0.57735026918962576450914878050196f; // 1/根号3
	constexpr float One_Div_Sqrt5 = 0.44721359549995793928183473374625f; // 1/根号5
	constexpr float Half_Sqrt2    = 0.70710678118654752440084436210485f; // 1/2 根号2
	constexpr float Half_Sqrt3    = 0.86602540378443864676372317075294f; // 1/2 根号3

	constexpr float Pi          = 3.1415926535897932384626433832795f; // Pi
	constexpr float Pi2         = 9.8696044010893586188344909998761f; // Pi^2
	constexpr float Pi2_Div_Six = 1.6449340668482264364724151666460f; // Pi^2 / 6
	constexpr float Pi3         = 31.006276680299820175476315067101f; // Pi^3

	constexpr float Pi_Div_Two   = 1.570796326794896619231321691639751f; // Pi/2
	constexpr float Pi_Div_Three = 1.047197551196597746154214461093167f; // Pi/3
	constexpr float Pi_Div_Four  = 0.785398163397448309615660845819875f; // Pi/4
	constexpr float Pi_Div_six   = 0.523598775598298873077107230546583f; // Pi/6

	constexpr float Two_Pi            = 6.283185307179586476925286766559005f; // 2*Pi
	constexpr float Two_Div_Three_Pi  = 2.094395102393195492308428922186335f; // 2/3*Pi
	constexpr float Three_Div_Four_Pi = 2.356194490192344928846982537459627f; // 3/4*Pi
	constexpr float Four_Div_Three_Pi = 4.188790204786390984616857844372670f; // 4/3*Pi

	constexpr float One_Div_Pi     = 0.318309886183790671537767526745028f; // 1/Pi
	constexpr float One_Div_Two_Pi = 0.159154943091895335768883763372514f; // 1/2Pi
	constexpr float One_Div_Pi_Two = 0.636619772367581343075535053490057f; // 1/(Pi / 2)
	constexpr float Two_Div_Pi     = 0.636619772367581343075535053490057f; // 2/Pi

	constexpr float One_Div_Sqrt_Pi     = 0.564189583547756286948079451560772f; // 1/根号Pi
	constexpr float One_Div_Sqrt_Two_Pi = 0.398942280401432677939946059934381f; // 1/根号2Pi
	constexpr float One_Div_Sqrt_Pi_Two = 0.797884560802865355879892119868763f; // 1/根号(Pi/2)

	constexpr float Sqrt_Pi         = 1.772453850905516027298167483341145f; // 根号Pi
	constexpr float Sqrt_Pi_Div_Two = 1.253314137315500251207882642405522f; // 根号Pi/2
	constexpr float Sqrt_Two_Pi     = 2.506628274631000502415765284811045f; // 根号2Pi

	constexpr float Two_Div_Sqrt_Pi = 1.128379167095512573896158903121545f; // 2/根号(Pi)
	constexpr float Sqrt_Two_Div_Pi = 0.797884560802865355879892119868763f; // 根号(2/Pi)

	constexpr float Cbrt_Pi         = 1.464591887561523263020142527263790f; // Pi的立方根
	constexpr float Quarter_Pi      = 0.785398163397448309615660845819875f; // Pi的四次方根
	constexpr float One_Div_Cbrt_Pi = 0.682784063255295681467020833158164f; // 1/Pi的立方根

	constexpr float E               = 2.718281828459045235360287471352662f; // e
	constexpr float Log2_E          = 1.442695040888963407359924681001892f; // log2_e
	constexpr float Log10_E         = 0.434294481903251827651128918916605f; // log10_e
	constexpr float One_Div_Log10_E = 2.302585092994045684017991454684364f; // 1/log10_e
	constexpr float E_Pow_Pi        = 23.14069263277926900572908636794854f; // e^Pi
	constexpr float Sqrt_E          = 1.648721270700128146848650787814163f; // 根号e

	constexpr float Ln2      =  0.69314718055994530941723212145817f; // ln2
	constexpr float Ln10     =  2.30258509299404568401799145468436f; // ln10
	constexpr float Lnln2    = -0.36651292058166432701243915823266f; // lnln2
	constexpr float Sqrt_Ln4 =  1.17741002251547469101156932645969f; // 根号ln4

	constexpr float degree = 0.00174532925199432957692369076848f; // Pi/180
	constexpr float radian = 57.2957795130823208767981548141051f; // 180.0/Pi

	constexpr float Sin1     = 0.84147098480789650665250232163029f;  // sin1
	constexpr float Cos1     = 0.54030230586813971740093660744297f;  // cos1
	constexpr float Sin1Deg  = 0.01745240643728351281941897851632f;  // sin1°
	constexpr float Cos1Deg  = 0.99984769515639123915701155881392f;  // cos1°
	constexpr float Sinh1    = 1.175201193643801456882381850595600f; // sinh1
	constexpr float Cosh1    = 1.543080634815243778477905620757061f; // cosh1

	constexpr float Phi           = 1.618033988749894848204586834365638f; // 黄金分割比例
	constexpr float One_Div_Phi   = 0.618033988749894848204586834365638f; // 1.0/黄金分割比例
	constexpr float LnPhi         = 0.481211825059603447497758913424368f; // ln(phi)
	constexpr float One_Div_LnPhi = 2.078086921235027537601322606117795f; // 1/ln(phi)

	constexpr float Euler         = 0.577215664901532860606512090082402f; // 欧拉常数
	constexpr float One_Div_Euler = 1.732454714600633473583025315860829f; // 1.0/欧拉常数

	constexpr float Catalan       = 0.915965594177219015054603514932384f; // 卡塔兰常数
	

} // namespace Math
