#include "Stack.h"

Stack::~Stack() noexcept
{
	while (!(isEmpty()))
		pop();
}

void Stack::push(const int value) noexcept
{
	Node *const topNode{ new Node };
	topNode->prev = __top;
	topNode->value = value;
	
	__top = topNode;
}

int Stack::pop() noexcept
{
	const int retVal{ __top->value };

	Node *const deletedNode{ __top };
	__top = __top->prev;

	delete deletedNode;
	return retVal;
}