#include "BinarySearch.h"
#include <algorithm>

std::optional<size_t> BinarySearch::search(const int key, const std::vector<int> &values) noexcept
{
	size_t start{ };
	size_t end{ values.size() };
	size_t divison{};

	while (true)
	{
		divison = ((end + start) >> 1U);

		const int centerValue{ values[divison] };
		if (key == centerValue)
			return divison;

		const size_t sectionLength{ end - start };
		if (sectionLength < 2U)
			break;

		if (key < centerValue)
			end = divison;
		else
			start = (divison + 1U);
	}

	return std::nullopt;
}