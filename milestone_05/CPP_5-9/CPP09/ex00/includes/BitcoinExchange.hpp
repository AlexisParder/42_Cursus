/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 09:01:32 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/11 10:25:13 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <exception>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _arr;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();
		void chargeCSV(const std::string &file);
		void processInput(const std::string &file);
};
