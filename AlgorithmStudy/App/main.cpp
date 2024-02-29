#include <iostream>
#include "Stopwatch.h"
#include "CountingSort.h"
#include <random>

void test()
{
	static constexpr size_t NUM_VALUES{ 100000U };

	std::default_random_engine randEngine{ 0U };
	std::uniform_int_distribution intDist{ 0, 100 };

	std::vector<int> values;
	for (size_t it{ }; it < NUM_VALUES; ++it)
		values.emplace_back(intDist(randEngine));

	CountingSort::sort(100, values);
}

int main()
{
	Stopwatch stopwatch;
	stopwatch.start();
	
	test();
	
	stopwatch.end();
	std::cout << stopwatch.getElapsedTime() << "ms" << std::endl;

	return 0;
}