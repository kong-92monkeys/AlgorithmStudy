#include <iostream>
#include "Stopwatch.h"
#include "BinarySearchTree.h"

void test()
{
	BinarySearchTree bst;

	bst.put(10);
	bst.put(2);
	bst.put(5);
	bst.put(20);
	bst.put(30);
	bst.put(1);
	bst.put(6);

	std::cout << bst.contains(2) << std::endl;
	std::cout << bst.contains(5) << std::endl;
	std::cout << bst.contains(30) << std::endl << std::endl;

	bst.remove(30);

	std::cout << bst.contains(2) << std::endl;
	std::cout << bst.contains(5) << std::endl;
	std::cout << bst.contains(30) << std::endl << std::endl;

	bst.remove(5);

	std::cout << bst.contains(2) << std::endl;
	std::cout << bst.contains(5) << std::endl;
	std::cout << bst.contains(30) << std::endl << std::endl;

	bst.remove(2);

	std::cout << bst.contains(2) << std::endl;
	std::cout << bst.contains(5) << std::endl;
	std::cout << bst.contains(30) << std::endl << std::endl;
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