#include "SelectionSort.h"
#include <optional>

void SelectionSort::sort(std::vector<int> &values) noexcept
{
	const size_t numValues{ values.size() };
	for (size_t testIdx{ }; testIdx < (numValues - 1U); ++testIdx)
	{
		size_t minIdx{ testIdx };
		for (size_t it{ testIdx + 1U }; it < numValues; ++it)
		{
			const auto minVal	{ values[minIdx] };
			const auto itVal	{ values[it] };
			
			if (minVal > itVal)
				minIdx = it;
		}

		if (testIdx != minIdx)
			std::swap(values[testIdx], values[minIdx]);
	}
}
