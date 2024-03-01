#include "BoyerMoore.h"

std::vector<size_t> BoyerMoore::search(
	const char *const str, const size_t strLength,
	const char *const key, const size_t keyLength) noexcept
{
	std::vector<size_t> retVal;

	size_t strCursor{ keyLength - 1U };
	while (strCursor < strLength)
	{
		size_t keyCursor{ };
		for (; keyCursor < keyLength; ++keyCursor)
		{
			const char curStrChar{ str[strCursor - keyCursor] };
			const char curKeyChar{ key[(keyLength - 1U) - keyCursor] };
			if (curStrChar != curKeyChar)
				break;
		}

		size_t skipAmount{ };
		if (keyCursor == keyLength)
		{
			retVal.emplace_back((strCursor + 1U) - keyLength);
			skipAmount = keyLength;
		}
		else
		{
			const char lastStrChar{ str[strCursor] };
			for (skipAmount = (keyCursor + 1U); skipAmount < keyLength; ++skipAmount)
			{
				const char curKeyChar{ key[(keyLength - 1U) - skipAmount] };
				if (lastStrChar == curKeyChar)
					break;
			}
		}

		strCursor += skipAmount;
	}

	return retVal;
}