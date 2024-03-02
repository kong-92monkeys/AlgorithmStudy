#include "Queue.h"

Queue::~Queue() noexcept
{
	while (!(isEmpty()))
		dequeue();
}

void Queue::enqueue(const int item) noexcept
{
	Node *const pNewNode{ new Node };
	pNewNode->item = item;

	if (isEmpty())
	{
		__pFront = pNewNode;
		__pRear = pNewNode;
	}
	else
	{
		__pRear->next = pNewNode;
		__pRear = pNewNode;
	}
}

int Queue::dequeue() noexcept
{
	const int retVal{ __pFront->item };
	
	Node *const pDeletedNode{ __pFront };
	__pFront = __pFront->next;

	delete pDeletedNode;
	return retVal;
}

int Queue::peek() noexcept
{
	return __pFront->item;
}