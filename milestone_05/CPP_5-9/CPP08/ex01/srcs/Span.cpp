/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:42:03 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/10 10:53:58 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	_size = 0;
}

Span::Span(unsigned int n)
{
	_size = n;
}

Span::Span(const Span &other)
{
	_size = other._size;
	_arr = other._arr;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_size = other._size;
		_arr = other._arr;
	}
	return (*this);
}

Span::~Span(void) {}

void Span::addNumber(int n)
{
	if (_arr.size() >= _size)
		throw std::length_error("maximum capacity reached!");
	_arr.push_back(n);
}

int Span::shortestSpan(void)
{
	if (_arr.empty() || _arr.size() < 2)
		throw std::length_error("Container must contain at least 2 elements!");
	std::sort(_arr.begin(), _arr.end());
	int tmp;
	for (unsigned int i = 0; i < _arr.size() - 1; i++)
	{
		if (i == 0)
			tmp = _arr[i + 1] - _arr[i];
		else
		{
			if (_arr[i + 1] - _arr[i] < tmp)
				tmp = _arr[i + 1] - _arr[i];
		}
	}
	return tmp;
}

int Span::longestSpan(void)
{
	if (_arr.empty() || _arr.size() < 2)
		throw std::length_error("Container must contain at least 2 elements!");
	int longest = *std::max_element(_arr.begin(), _arr.end()) - *std::min_element(_arr.begin(), _arr.end());
	return longest;
}