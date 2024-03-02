#include <iostream>
#include "Stopwatch.h"
#include "Queue.h"

void test()
{
	Queue queue;

	queue.enqueue(1);
	queue.enqueue(3);
	queue.enqueue(5);
	queue.enqueue(7);

	std::cout << queue.dequeue() << std::endl;
	std::cout << queue.dequeue() << std::endl;
	std::cout << queue.dequeue() << std::endl;
	std::cout << queue.dequeue() << std::endl;
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