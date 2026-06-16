/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:02:34 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/16 19:49:19 by achauvie         ###   ########.fr       */
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
		std::vector<size_t> jacobsthalOrder(size_t n);
		std::vector<long> mergeInsertVec(std::vector<long> container);
		std::deque<long> mergeInsertDeq(std::deque<long> container);

	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe(void);
		void parseArgs(int ac, char **av);
		void runProcess(void);
};