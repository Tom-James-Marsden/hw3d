#include "BumTimer.h"

using namespace std::chrono;

BumTimer::BumTimer() noexcept
{
	last = steady_clock::now();
}

float BumTimer::Mark() noexcept
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> frameTime = last - old;
	return frameTime.count();
}

float BumTimer::Peek() const noexcept
{
	return duration<float>(steady_clock::now() - last).count();
}
