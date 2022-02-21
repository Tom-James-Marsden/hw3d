#include "BumTimer.h"

using namespace std::chrono;

BumTimer::BumTimer()
{
	last = steady_clock::now();
}

float BumTimer::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float BumTimer::Peek() const
{
	return duration<float>(steady_clock::now() - last).count();
}
