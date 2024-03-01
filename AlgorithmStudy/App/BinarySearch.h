#pragma once

#include <vector>
#include <optional>

class BinarySearch
{
public:
	[[nodiscard]]
	static std::optional<size_t> search(const int key, const std::vector<int> &values) noexcept;
};