#include "KMP.h"

std::vector<size_t> KMP::search(
	const char *const str, const size_t strLength,
	const char *const key, const size_t keyLength) noexcept
{
	const auto piValues{ __makePiValuesOf(key, keyLength) };
	std::vector<size_t> retVal;

	size_t matchingLen{ };
	for (size_t strIt{ }; strIt < strLength; ++strIt)
	{
		while (matchingLen && (key[matchingLen] != str[strIt]))
			matchingLen = piValues[matchingLen - 1U];

		if (key[matchingLen] == str[strIt])
		{
			++matchingLen;
			if (matchingLen == keyLength)
			{
				retVal.emplace_back((strIt - keyLength) + 1U);
				matchingLen = piValues[matchingLen - 1U];
			}
		}
	}

	return retVal;
}

std::vector<size_t> KMP::__makePiValuesOf(const char *const key, const size_t keyLength) noexcept
{
	std::vector<size_t> piValues;
	piValues.resize(keyLength);

	size_t matchingLen{ };
	for (size_t keyIt{ 1U }; keyIt < keyLength; ++keyIt)
	{
		while (matchingLen && (key[matchingLen] != key[keyIt]))
			matchingLen = piValues[matchingLen - 1U];

		if (key[matchingLen] == key[keyIt])
		{
			++matchingLen;
			piValues[keyIt] = matchingLen;
		}
	}

	return piValues;
}