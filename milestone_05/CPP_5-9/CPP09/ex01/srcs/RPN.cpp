/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:27:24 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/15 12:25:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_arr = other._arr;
	return (*this);	
}

RPN::~RPN(void) {}

bool isValidStr(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isspace(str[i]) && !std::isdigit(str[i]) && !std::strchr("+-/*", str[i]))
			return false;
		if (str[i + 1] && std::isdigit(str[i]) && std::isdigit(str[i + 1]))
			return false;
	}
	return true;
}

void RPN::processCalc(const std::string &expr)
{
	if (!isValidStr(expr))
		throw std::invalid_argument("Error: invalid expression.\nAllowed characters: digits (0-9), spaces, and the operators '/', '*', '-', '+'.");

	for (size_t i = 0; i < expr.size(); i++)
	{
		if (std::isspace(expr[i]))
			continue;
		if (std::strchr("+-/*", expr[i]))
		{
			if (_arr.empty() || _arr.size() < 2)
				throw std::invalid_argument("Error: An operator was encountered when there are not two operands on the stack.");
			long b = _arr.top(); 
			_arr.pop();
			long a = _arr.top(); 
			_arr.pop();
			long res = 0;
			switch (expr[i])
			{
				case '+':
					res = a + b; 
					break;
				case '-':
					res = a - b; 
					break;
				case '*':
					res = a * b; 
					break;
				case '/':
					if (b == 0)
						throw std::runtime_error("Error: division by zero.");
					res = a / b; 
					break;
			}
			_arr.push(res);
		}
		else if (std::isdigit(expr[i]))
			_arr.push(expr[i] - '0');
		else
			throw std::invalid_argument("Error: invalid expression.\nAllowed characters: digits (0-9), spaces, and the operators '/', '*', '-', '+'.");
	}
	
	if (_arr.size() != 1)
		throw std::invalid_argument("Error: The stack does not contain a single final result.");
	std::cout << _arr.top() << std::endl;
}