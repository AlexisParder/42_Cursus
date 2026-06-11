/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:27:17 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/11 12:05:17 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int> _arr;
	public:
		RPN(void);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);
		void processCalc(const std::string &expr);
};