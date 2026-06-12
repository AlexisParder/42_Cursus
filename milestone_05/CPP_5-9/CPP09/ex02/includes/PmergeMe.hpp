/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:02:34 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/12 13:56:04 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<long> _arrVec;
		std::deque<long> _arrDeq;
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe(void);
		void parseArgs(int ac, char **av);
		void runProcess(void);
};

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
		typename T::iterator limit = std::find(container.begin(), container.end(), big[i]);
		typename T::iterator pos = std::lower_bound(container.begin(), limit, small[i]);
		container.insert(pos, small[i]);
	}
	if (hasLeftovers)
	{
		typename T::iterator pos = std::lower_bound(container.begin(), container.end(), leftovers);
		container.insert(pos, leftovers);
	}
	return container;
}