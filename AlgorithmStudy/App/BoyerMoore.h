#pragma once

#include <vector>

class BoyerMoore
{
public:
	[[nodiscard]]
	static std::vector<size_t> search(
		const char *const str, const size_t strLength,
		const char *const key, const size_t keyLength) noexcept;
};