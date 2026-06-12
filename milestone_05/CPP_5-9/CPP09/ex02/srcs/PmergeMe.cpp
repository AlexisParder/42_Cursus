/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:02:47 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/12 11:24:57 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_arrDeq = other._arrDeq;
		_arrVec = other._arrVec;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) {}

void PmergeMe::parseArgs(int ac, char **av)
{
	for (size_t i = 1; i < static_cast<size_t>(ac); i++)
	{
		for (size_t j = 0; j < std::strlen(av[i]); j++)
		{
			if (!std::isspace(av[i][j]) && !std::isdigit(av[i][j]))
				throw std::invalid_argument("Error: Invalid arg:\nAllowed only positive integers!");
		}
		long arg = std::atol(av[i]);
		if (arg <= 0 || arg > INT_MAX)
			throw std::invalid_argument("Error: Invalid arg: must be a positive integer <= INT_MAX!");
		_arrVec.push_back(arg);
		_arrDeq.push_back(arg);
	}
	
}

template <typename T>
T mergeInsert(T container)
{
	T big, small;
	long leftovers = -1;
	bool hasLeftovers = false;

	if (container.size() <= 1)
    	return container;

	if (container.size() % 2 != 0)
	{
		leftovers = container.back();
		hasLeftovers = true;
		container.pop_back();
	}

	for (size_t i = 0; i < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
		{
			big.push_back(container[i]);
			small.push_back(container[i + 1]);
		}
		else
		{
			big.push_back(container[i + 1]);
			small.push_back(container[i]);
		}
	}
	container = mergeInsert(big);

	for (size_t i = 0; i < small.size(); i++)
	{
		typename T::iterator pos = std::lower_bound(container.begin(), container.end(), small[i]);
		container.insert(pos, small[i]);
	}
	if (hasLeftovers)
	{
		typename T::iterator pos = std::lower_bound(container.begin(), container.end(), leftovers);
		container.insert(pos, leftovers);
	}
	return container;
}

void PmergeMe::runProcess(void)
{
	std:: cout << "Before:";
	for (size_t i = 0; i < _arrVec.size(); i++)
		std::cout << " " << _arrVec[i];
	std::cout << std::endl;

	clock_t startVec = clock();
	_arrVec = mergeInsert(_arrVec);
	clock_t endVec = clock();
	double timeVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	clock_t startDeq = clock();
	_arrDeq = mergeInsert(_arrDeq);
	clock_t endDeq = clock();
	double timeDeq = (double)(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	std:: cout << "After:";
	for (size_t i = 0; i < _arrVec.size(); i++)
		std::cout << " " << _arrVec[i];
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << _arrVec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _arrVec.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
}