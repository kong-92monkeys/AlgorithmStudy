#include "QuickSort.h"
#include <stack>

void QuickSort::sort(std::vector<int> &values) noexcept
{
	if (values.size() < 2U)
		return;

	std::stack<std::pair<size_t, size_t>> sections;
	sections.emplace(0U, values.size());

	while (!(sections.empty()))
	{
		const auto [startIdx, endIdx]{ sections.top() };
		sections.pop();

		const size_t sectionLen{ endIdx - startIdx };
		if (sectionLen < 2U)
			continue;

		if (sectionLen == 2U)
		{
			auto &lhs{ values[startIdx] };
			auto &rhs{ values[startIdx + 1U] };
			if (lhs > rhs)
				std::swap(lhs, rhs);

			continue;
		}

		const size_t pivotIdx{ startIdx };
		int &pivotVal{ values[pivotIdx] };
		
		size_t lIdx{ startIdx + 1U };
		size_t rIdx{ endIdx - 1U };

		while (lIdx <= rIdx)
		{
			int &lVal{ values[lIdx] };
			int &rVal{ values[rIdx] };

			bool lFound{ lVal > pivotVal };
			bool rFound{ rVal < pivotVal };

			if (lFound && rFound)
			{
				std::swap(lVal, rVal);
				continue;
			}

			if (!lFound)
				++lIdx;

			if (!rFound)
				--rIdx;
		}

		if (pivotIdx != rIdx)
		{
			std::swap(pivotVal, values[rIdx]);
			sections.emplace(startIdx, rIdx);
		}

		sections.emplace(rIdx + 1U, endIdx);
	}
}