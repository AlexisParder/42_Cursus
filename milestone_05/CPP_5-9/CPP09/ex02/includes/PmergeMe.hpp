/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 15:02:34 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/12 11:25:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
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
