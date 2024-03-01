#pragma once

#include <string>

class ExpressionCalculator
{
public:
	static int calculate(const std::string_view &expression) noexcept;

private:
	[[nodiscard]]
	static std::string __toPostfixExpression(const std::string_view &infixExpression) noexcept;
};