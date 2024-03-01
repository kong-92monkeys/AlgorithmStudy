#pragma once

class Stack
{
public:
	~Stack() noexcept;

	void push(const int value) noexcept;
	int pop() noexcept;

	[[nodiscard]]
	constexpr bool isEmpty() const noexcept;

	[[nodiscard]]
	constexpr int peek() const noexcept;

private:
	struct Node
	{
	public:
		Node *prev{ };
		int value{ };
	};

	Node *__top{ };
};

constexpr bool Stack::isEmpty() const noexcept
{
	return !__top;
}

constexpr int Stack::peek() const noexcept
{
	return __top->value;
}