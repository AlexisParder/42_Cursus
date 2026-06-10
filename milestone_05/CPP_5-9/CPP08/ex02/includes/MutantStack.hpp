/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 10:55:09 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/10 11:31:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};
		MutantStack(const MutantStack &other)
		{
			*this = other;
		};
		MutantStack &operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		};
		~MutantStack(void) {};
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin()
		{
			return this->c.begin();
		};
		iterator end()
		{
			return this->c.end();
		};
};