#include <iostream>
#include "Stopwatch.h"
#include "BoyerMoore.h"

void test()
{
	const char str[]{ "this is test string. good test is accurate test." };
	const char key[]{ "test" };

	const auto result{ BoyerMoore::search(str, std::size(str) - 1U, key, std::size(key) - 1U) };
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