#include <iostream>
#include "Stopwatch.h"
#include "QuickSort.h"
#include <random>

void test()
{
	std::vector<int> values{ 3, 4, 5, 6, 4, 5, 6 };

	/*static constexpr size_t NUM_VALUES{ 100000U };

	std::default_random_engine randEngine{ 0U };
	std::uniform_int_distribution intDist{ 0, 100 };

	for (size_t it{ }; it < NUM_VALUES; ++it)
		values.emplace_back(intDist(randEngine));*/

	QuickSort::sort(values);
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