#include <iostream>
#include "Stopwatch.h"
#include "LinkedList.h"

void test()
{
	LinkedList list;

	list.insert(0, 1);
	list.insert(0, 2);
	list.insert(0, 3);
	list.insert(0, 4);

	list.insert(1, 10);
	list.insert(1, 20);
	list.insert(1, 30);
	list.insert(1, 40);

	list.remove(2);

	std::cout << list.get(0) << std::endl;
	std::cout << list.get(1) << std::endl;
	std::cout << list.get(2) << std::endl;
	std::cout << list.get(3) << std::endl;
	std::cout << list.get(4) << std::endl;
	std::cout << list.get(5) << std::endl;
	std::cout << list.get(6) << std::endl;
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