#pragma once

#include <chrono>

class Stopwatch
{
public:
	void start() noexcept;
	void end() noexcept;

	[[nodiscard]]
	constexpr double getElapsedTime() const noexcept;

private:
	std::chrono::time_point<std::chrono::steady_clock> __startVal;
	std::chrono::time_point<std::chrono::steady_clock> __endVal;
};

constexpr double Stopwatch::getElapsedTime() const noexcept
{
	const auto diff{ std::chrono::duration_cast<std::chrono::nanoseconds>(__endVal - __startVal) };
	return (diff.count() * 1e-6);
}