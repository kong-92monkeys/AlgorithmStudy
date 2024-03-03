#pragma once

#include <vector>

class MergeSort
{
public:
	static void sort(std::vector<int> &values) noexcept;

private:
	static void __sortRecursive(const size_t startIdx, const size_t endIdx, std::vector<int> &values) noexcept;
	static void __merge(const size_t startIdx, const size_t halfIdx, const size_t endIdx, std::vector<int> &values) noexcept;
};