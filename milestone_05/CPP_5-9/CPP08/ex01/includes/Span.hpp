/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:41:55 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/10 10:54:01 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int _size;
		std::vector<int> _arr;
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);
		void addNumber(int n);
		int shortestSpan(void);
		int longestSpan(void);
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end);
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	if (_arr.size() + (end - begin) > _size)
		throw std::length_error("maximum capacity reached!");
	_arr.insert(_arr.end(), begin, end);
}