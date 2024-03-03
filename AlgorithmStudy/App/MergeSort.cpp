#include "MergeSort.h"
#include <stack>

void MergeSort::sort(std::vector<int> &values) noexcept
{
	__sortRecursive(0U, values.size(), values);
}

void MergeSort::__sortRecursive(const size_t startIdx, const size_t endIdx, std::vector<int> &values) noexcept
{
	const size_t sectionLen{ endIdx - startIdx };
	if (sectionLen > 2)
	{
		const size_t halfIdx{ (endIdx + startIdx) >> 1U };
		__sortRecursive(startIdx, halfIdx, values);
		__sortRecursive(halfIdx + 1U, endIdx, values);
		__merge(startIdx, halfIdx, endIdx, values);
	}
	else if (sectionLen == 2)
	{
		auto &lhs{ values[startIdx] };
		auto &rhs{ values[startIdx + 1U] };
		if (lhs > rhs)
			std::swap(lhs, rhs);
	}
}

void MergeSort::__merge(const size_t startIdx, const size_t halfIdx, const size_t endIdx, std::vector<int> &values) noexcept
{
	std::vector<int> sorted;

	size_t lCursor{ startIdx };
	size_t rCursor{ halfIdx };
	while ((lCursor < halfIdx) || (rCursor < endIdx))
	{
		if (lCursor < halfIdx)
		{
			const int lVal{ values[lCursor] };

			if (rCursor < endIdx)
			{
				const int rVal{ values[rCursor] };

				if (lVal < rVal)
				{
					sorted.emplace_back(lVal);
					++lCursor;
				}
				else
				{
					sorted.emplace_back(rVal);
					++rCursor;
				}
			}
			else
			{
				sorted.emplace_back(lVal);
				++lCursor;
			}
		}
		else if (rCursor < endIdx)
		{
			const int rVal{ values[rCursor] };
			sorted.emplace_back(rVal);
			++rCursor;
		}
	}

	for (size_t copyIt{ startIdx }; copyIt < endIdx; ++copyIt)
		values[copyIt] = sorted[copyIt];
}