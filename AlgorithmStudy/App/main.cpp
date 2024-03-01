#include <iostream>
#include "Stopwatch.h"
#include "Stack.h"

void test()
{
	Stack stack;

	stack.push(1);
	stack.push(3);
	stack.push(5);
	stack.push(7);

	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
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