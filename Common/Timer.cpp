#include "Timer.h"

Timer::Timer(): elapsed_(0)
{
	QueryPerformanceFrequency(&freq_);
}

void Timer::Start()
{
	QueryPerformanceCounter(&begin_time_);
}

void Timer::Stop()
{
	LARGE_INTEGER end_time; 
	QueryPerformanceCounter(&end_time);
	elapsed_ += (end_time.QuadPart - begin_time_.QuadPart) * MicroSecondsPerSecond / freq_.QuadPart;
}

void Timer::ReStart()
{
	elapsed_ = 0;
	Start();
}

long long Timer::GetMicroSeconds()
{ 
	LARGE_INTEGER now_time;
	QueryPerformanceCounter(&now_time);
	return (now_time.QuadPart - begin_time_.QuadPart) * MicroSecondsPerSecond / freq_.QuadPart; 
}
long long Timer::GetMilliSeconds()
{ 
	return GetMicroSeconds() / MicroSecondsPerMilliSeconds;
}

long long Timer::GetSeconds()
{ 
	return GetMicroSeconds() / MicroSecondsPerSecond;
}
