#pragma once

class Queue
{
public:
	~Queue() noexcept;

	void enqueue(const int item) noexcept;
	int dequeue() noexcept;

	[[nodiscard]]
	int peek() noexcept;

	[[nodiscard]]
	constexpr bool isEmpty() const noexcept;

private:
	class Node
	{
	public:
		Node *next{ };
		int item;
	};

	Node *__pFront{ };
	Node *__pRear{ };
};

constexpr bool Queue::isEmpty() const noexcept
{
	return !__pFront;
}