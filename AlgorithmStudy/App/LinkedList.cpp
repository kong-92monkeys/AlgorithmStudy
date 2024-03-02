#include "LinkedList.h"

LinkedList::~LinkedList() noexcept
{
	while (__pHead)
	{
		Node *const pDeletedNode{ __pHead };
		__pHead = __pHead->pNext;

		delete pDeletedNode;
	}
}

void LinkedList::insert(const size_t position, const int value) noexcept
{
	Node *const pNewNode{ new Node };
	pNewNode->item = value;

	if (position == 0U)
	{
		pNewNode->pNext = __pHead;
		__pHead = pNewNode;
	}
	else
	{
		Node *pPrevNode{ __pHead };

		for (size_t iter{ 1U }; iter < position; ++iter)
			pPrevNode = pPrevNode->pNext;

		Node *const pNextNode{ pPrevNode->pNext };

		pPrevNode->pNext = pNewNode;
		pNewNode->pNext = pNextNode;
	}
}

void LinkedList::remove(const size_t position) noexcept
{
	if (position == 0U)
	{
		Node *const pDeletedNode{ __pHead };
		__pHead = __pHead->pNext;
		delete pDeletedNode;
	}
	else
	{
		Node *pPrevNode{ __pHead };

		for (size_t iter{ 1U }; iter < position; ++iter)
			pPrevNode = pPrevNode->pNext;

		Node *const pDeletedNode{ pPrevNode->pNext };
		Node *const pNextNode{ pDeletedNode->pNext };

		pPrevNode->pNext = pNextNode;
		delete pDeletedNode;
	}
}

int LinkedList::get(const size_t position) noexcept
{
	Node *pRetVal{ __pHead };

	for (size_t iter{ }; iter < position; ++iter)
		pRetVal = pRetVal->pNext;

	return pRetVal->item;
}