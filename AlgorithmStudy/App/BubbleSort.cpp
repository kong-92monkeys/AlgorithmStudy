#include "BubbleSort.h"

void BubbleSort::sort(std::vector<int> &values) noexcept
{
	const size_t numValues{ values.size() };
	for (size_t end{ numValues - 1U }; end; --end)
	{
		for (size_t it{ }; it < end; ++it)
		{
			auto &lhs{ values[it] };
			auto &rhs{ values[it + 1U] };
			
			if (lhs > rhs)
				std::swap(lhs, rhs);
		}
	}
}