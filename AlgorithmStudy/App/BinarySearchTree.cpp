#include "BinarySearchTree.h"
#include <stack>

BinarySearchTree::~BinarySearchTree() noexcept
{
	if (!__pRoot)
		return;

	std::stack<Node *> nodeStack;
	nodeStack.emplace(__pRoot);

	while (!(nodeStack.empty()))
	{
		Node *const pNode{ nodeStack.top() };
		nodeStack.pop();

		if (pNode->pRight)
			nodeStack.emplace(pNode->pRight);

		if (pNode->pLeft)
			nodeStack.emplace(pNode->pLeft);

		delete pNode;
	}
}

bool BinarySearchTree::put(const int value)
{
	Node *pPrevNode{ };
	Node *pCurNode{ __pRoot };

	while (pCurNode)
	{
		if (pCurNode->value == value)
			return false;

		pPrevNode = pCurNode;

		if (pCurNode->value > value)
			pCurNode = pCurNode->pLeft;
		else
			pCurNode = pCurNode->pRight;
	}

	Node *const pNewNode{ new Node };
	pNewNode->value = value;

	if (!pPrevNode)
		__pRoot = pNewNode;
	else if (pPrevNode->value > value)
		pPrevNode->pLeft = pNewNode;
	else
		pPrevNode->pRight = pNewNode;
	
	return true;
}

bool BinarySearchTree::remove(const int value)
{
	Node *pPrevNode{ };
	Node *pCurNode{ __pRoot };

	while (pCurNode)
	{
		if (pCurNode->value == value)
			break;

		pPrevNode = pCurNode;

		if (pCurNode->value > value)
			pCurNode = pCurNode->pLeft;
		else
			pCurNode = pCurNode->pRight;
	}

	// 못찾음
	if (!pCurNode)
		return false;

	// 자식 노드가 2개
	if (pCurNode->pLeft && pCurNode->pRight)
	{
		Node *pSuccessorPrev{ pCurNode };
		Node *pSuccessor{ pCurNode->pRight };

		while (pSuccessor->pLeft)
			pSuccessor = pSuccessor->pLeft;

		if (pSuccessorPrev->pLeft == pSuccessor)
			pSuccessorPrev->pLeft = pSuccessor->pRight;
		else
			pSuccessorPrev->pRight = pSuccessor->pRight;

		pCurNode->value = pSuccessor->value;
		pCurNode = pSuccessor;
	}
	// 자식 노드가 1개 or 없음
	else
	{
		Node *const pChildNode{ pCurNode->pLeft ? pCurNode->pLeft : pCurNode->pRight };

		// pCurNode != 루트
		if (pPrevNode)
		{
			if (pPrevNode->pLeft == pCurNode)
				pPrevNode->pLeft = pChildNode;
			else
				pPrevNode->pRight = pChildNode;
		}
		// pCurNode == 루트
		else
			__pRoot = pChildNode;
	}

	delete pCurNode;
	return true;
}

bool BinarySearchTree::contains(const int value)
{
	Node *pCurNode{ __pRoot };
	while (pCurNode)
	{
		if (pCurNode->value == value)
			return true;

		if (pCurNode->value > value)
			pCurNode = pCurNode->pLeft;
		else
			pCurNode = pCurNode->pRight;
	}

	return false;
}