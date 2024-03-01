#include <iostream>
#include "Stopwatch.h"
#include "ExpressionCalculator.h"

void test()
{
	const auto converted{ ExpressionCalculator::calculate("( 1+2*(5-2)/2)") };
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