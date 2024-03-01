#include "ExpressionCalculator.h"
#include <stack>

int ExpressionCalculator::calculate(const std::string_view &expression) noexcept
{
	const auto postfixExpression{ __toPostfixExpression(expression) };

	std::stack<int> digitStack;
	for (const char token : postfixExpression)
	{
		if (isdigit(token))
			digitStack.emplace(token - '0');
		else
		{
			const int rhs{ digitStack.top() };
			digitStack.pop();

			const int lhs{ digitStack.top() };
			digitStack.pop();

			int result{ };
			switch (token)
			{
				case '+':
					result = (lhs + rhs);
					break;

				case '-':
					result = (lhs - rhs);
					break;

				case '*':
					result = (lhs * rhs);
					break;

				case '/':
					result = (lhs / rhs);
					break;
			}

			digitStack.emplace(result);
		}
	}

	return digitStack.top();
}

std::string ExpressionCalculator::__toPostfixExpression(const std::string_view &infixExpression) noexcept
{
	std::string retVal;
	std::stack<char> opStack;

	for (const char token : infixExpression)
	{
		if (isdigit(token))
			retVal.push_back(token);

		else if ((token == '(') || opStack.empty())
			opStack.emplace(token);

		else if ((token == '+') || (token == '-'))
		{
			while (true)
			{
				const char topOp{ opStack.top() };
				if (topOp == '(')
					break;

				opStack.pop();
				retVal.push_back(topOp);

				if (opStack.empty())
					break;
			}

			opStack.emplace(token);
		}
		else if ((token == '*') || (token == '/'))
		{
			while (true)
			{
				const char topOp{ opStack.top() };
				if ((topOp == '(') || (topOp == '+') || (topOp == '-'))
					break;

				opStack.pop();
				retVal.push_back(topOp);

				if (opStack.empty())
					break;
			}

			opStack.emplace(token);
		}
		// token == ')'
		else
		{
			while (!(opStack.empty()))
			{
				const char topOp{ opStack.top() };
				opStack.pop();

				if (topOp == '(')
					break;

				retVal.push_back(topOp);
			}
		}
	}

	while (!(opStack.empty()))
	{
		const char topOp{ opStack.top() };
		opStack.pop();

		retVal.push_back(topOp);
	}

	return retVal;
}