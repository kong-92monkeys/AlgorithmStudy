#include "Stopwatch.h"

void Stopwatch::start() noexcept
{
	__startVal = std::chrono::steady_clock::now();
}

void Stopwatch::end() noexcept
{
	__endVal = std::chrono::steady_clock::now();
}