#pragma once

class BinarySearchTree
{
public:
	~BinarySearchTree() noexcept;

	bool put(const int value);
	bool remove(const int value);
	bool contains(const int value);

	[[nodiscard]]
	constexpr bool isEmpty() const noexcept;

private:
	class Node
	{
	public:
		Node *pLeft{ };
		Node *pRight{ };
		int value;
	};

	Node *__pRoot{ };
};

constexpr bool BinarySearchTree::isEmpty() const noexcept
{
	return !__pRoot;
}