#pragma once

#include <optional>
#include <cstdint>
#include <vector>

class KMP
{
public:
	[[nodiscard]]
	static std::vector<size_t> search(
		const char *const str, const size_t strLength,
		const char *const key, const size_t keyLength) noexcept;

private:
	static std::vector<size_t> __makePiValuesOf(const char *const key, const size_t keyLength) noexcept;
};