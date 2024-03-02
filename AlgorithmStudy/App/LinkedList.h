#pragma once

class LinkedList
{
public:
	~LinkedList() noexcept;

	[[nodiscard]]
	constexpr bool isEmpty() const noexcept;

	void insert(const size_t position, const int value) noexcept;
	void remove(const size_t position) noexcept;

	[[nodiscard]]
	int get(const size_t position) noexcept;

private:
	struct Node
	{
	public:
		int item{ };
		Node *pNext{ };
	};

	Node *__pHead{ };
};

constexpr bool LinkedList::isEmpty() const noexcept
{
	return !__pHead;
}