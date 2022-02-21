#pragma once
#include <chrono>
class BumTimer
{
public:
	BumTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};

