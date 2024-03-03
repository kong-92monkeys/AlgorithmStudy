#include "InsertionSort.h"
#include <list>

void InsertionSort::sort(std::vector<int> &values) noexcept
{
	const size_t valueCount{ values.size() };

	std::list<int> sorted;
	sorted.emplace_back(values[0]);

	for (size_t uIter{ 1U }; uIter < valueCount; ++uIter)
	{
		const int value{ values[uIter] };

		auto sIt{ sorted.begin() };
		for (; sIt != sorted.end(); ++sIt)
		{
			if ((*sIt) > value)
				break;
		}

		sorted.insert(sIt, value);
	}

	values.clear();
	values.insert(values.end(), sorted.begin(), sorted.end());
}