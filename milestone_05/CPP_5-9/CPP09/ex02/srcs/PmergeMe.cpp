/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:02:47 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/16 19:49:15 by achauvie         ###   ########.fr       */
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

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n)
{
	std::vector<size_t> jacobsthal;
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	while (jacobsthal.back() < n)
		jacobsthal.push_back(jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2]);

	std::vector<size_t> order;
	std::vector<bool> inserted;
	for (size_t i = 0; i < n; i++)
		inserted.push_back(false);

	for (size_t k = 2; k < jacobsthal.size(); k++)
	{
		size_t high;
		if (jacobsthal[k] < n)
			high = jacobsthal[k];
		else
			high = n;
		size_t low = jacobsthal[k - 1] + 1;
 
		for (size_t idx = high; idx >= low; idx--)
		{
			size_t i = idx - 1;
			if (i < n && !inserted[i])
			{
				order.push_back(i);
				inserted[i] = true;
			}
		}
	}

	for (size_t i = 0; i < n; i++)
	{
		if (!inserted[i])
			order.push_back(i);
	}
	return order;
}

std::vector<long> PmergeMe::mergeInsertVec(std::vector<long> container)
{
	if (container.size() <= 1)
		return container;

	long leftovers = -1;
	bool hasLeftovers = false;
	if (container.size() % 2 != 0)
	{
		leftovers = container.back();
		hasLeftovers = true;
		container.pop_back();
	}

	std::vector<std::pair<long, long> > pairs;
	for (size_t i = 0; i < container.size(); i += 2)
	{
		if (container[i] >= container[i + 1])
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
		else
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
	}

	std::vector<long> bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].first);
	bigs = mergeInsertVec(bigs);

	std::vector<std::pair<long, long> > sortedPairs;
	std::vector<bool> used;
	for (size_t i = 0; i < pairs.size(); i++)
		used.push_back(false);

	for (size_t i = 0; i < bigs.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].first == bigs[i])
			{
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	std::vector<long> chain;
	std::vector<long> pend;
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		chain.push_back(sortedPairs[i].first);
		pend.push_back(sortedPairs[i].second);
	}

	chain.insert(chain.begin(), pend[0]);
	size_t pendSize = pend.size() - 1;
	if (pendSize > 0)
	{
		std::vector<size_t> order = jacobsthalOrder(pendSize);
		for (size_t k = 0; k < order.size(); k++)
		{
			size_t pendIdx = order[k] + 1;
			long val = pend[pendIdx];
			long partnerBig = sortedPairs[pendIdx].first;

			std::vector<long>::iterator limit = std::find(chain.begin(), chain.end(), partnerBig);
			std::vector<long>::iterator pos = std::lower_bound(chain.begin(), limit, val);
			chain.insert(pos, val);
		}
	}

	if (hasLeftovers)
	{
		std::vector<long>::iterator pos = std::lower_bound(chain.begin(), chain.end(), leftovers);
		chain.insert(pos, leftovers);
	}
	return chain;
}

std::deque<long> PmergeMe::mergeInsertDeq(std::deque<long> container)
{
	if (container.size() <= 1)
		return container;

	long leftovers = -1;
	bool hasLeftovers = false;
	if (container.size() % 2 != 0)
	{
		leftovers = container.back();
		hasLeftovers = true;
		container.pop_back();
	}

	std::deque<std::pair<long, long> > pairs;
	for (size_t i = 0; i < container.size(); i += 2)
	{
		if (container[i] >= container[i + 1])
			pairs.push_back(std::make_pair(container[i], container[i + 1]));
		else
			pairs.push_back(std::make_pair(container[i + 1], container[i]));
	}

	std::deque<long> bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].first);

	bigs = mergeInsertDeq(bigs);

	std::deque<std::pair<long, long> > sortedPairs;
	std::deque<bool> used;
	for (size_t i = 0; i < pairs.size(); i++)
		used.push_back(false);

	for (size_t i = 0; i < bigs.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].first == bigs[i])
			{
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	std::deque<long> chain;
	std::deque<long> pend;
	for (size_t i = 0; i < sortedPairs.size(); i++)
	{
		chain.push_back(sortedPairs[i].first);
		pend.push_back(sortedPairs[i].second);
	}

	chain.push_front(pend[0]);
	size_t pendSize = pend.size() - 1;
	if (pendSize > 0)
	{
		std::vector<size_t> order = jacobsthalOrder(pendSize);
		for (size_t k = 0; k < order.size(); k++)
		{
			size_t pendIdx = order[k] + 1;
			long val = pend[pendIdx];
			long partnerBig = sortedPairs[pendIdx].first;

			std::deque<long>::iterator limit = std::find(chain.begin(), chain.end(), partnerBig);
			std::deque<long>::iterator pos = std::lower_bound(chain.begin(), limit, val);
			chain.insert(pos, val);
		}
	}

	if (hasLeftovers)
	{
		std::deque<long>::iterator pos = std::lower_bound(chain.begin(), chain.end(), leftovers);
		chain.insert(pos, leftovers);
	}

	return chain;
}


void PmergeMe::runProcess(void)
{
	std:: cout << "Before:";
	for (size_t i = 0; i < _arrVec.size(); i++)
		std::cout << " " << _arrVec[i];
	std::cout << std::endl;

	clock_t startVec = clock();
	_arrVec = mergeInsertVec(_arrVec);
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	clock_t startDeq = clock();
	_arrDeq = mergeInsertDeq(_arrDeq);
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	std:: cout << "After:";
	for (size_t i = 0; i < _arrVec.size(); i++)
		std::cout << " " << _arrVec[i];
	std::cout << std::endl;
	
	std::cout << "Time to process a range of " << _arrVec.size() << " elements with std::vector : " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _arrDeq.size() << " elements with std::deque : " << timeDeq << " us" << std::endl;
}