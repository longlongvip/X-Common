#pragma once

#include <windows.h>

class Timer
{
public:
	Timer();

	void Start();
	void Stop();
	void ReStart();

	long long GetMicroSeconds();
	long long GetMilliSeconds();
	long long GetSeconds();

	static const int MicroSecondsPerMilliSeconds = 1000;
	static const int MicroSecondsPerSecond = 1000 * 1000;

private:
	LARGE_INTEGER freq_;
	LARGE_INTEGER begin_time_;
	long long elapsed_;
};