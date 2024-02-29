#include "CountingSort.h"

void CountingSort::sort(const int maxValue, std::vector<int> &values) noexcept
{
	std::vector<int> countAccums;
	countAccums.resize(maxValue + 1);

	for (const int value : values)
		++(countAccums[value]);

	for (int it{ }; it < maxValue; ++it)
		countAccums[it + 1] += countAccums[it];

	std::vector<int> sortedValues;
	sortedValues.resize(values.size());

	for (const int value : values)
	{
		auto &idx{ countAccums[value] };
		--idx;

		sortedValues[idx] = value;
	}

	values.swap(sortedValues);
}
