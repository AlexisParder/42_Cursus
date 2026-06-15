/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 09:03:21 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/15 13:21:21 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_arr = other._arr;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}

void BitcoinExchange::chargeCSV(const std::string &file)
{
	std::ifstream inFile(file.c_str());
	if (!inFile.is_open())
		throw std::runtime_error("cannot open csv file!");

	std::string line;
	std::getline(inFile, line);
	while (std::getline(inFile, line))
	{
		std::size_t	pos = line.find(',');
		if (pos != std::string::npos)
		{
			if (pos > 0)
			{
				std::string date = line.substr(0, pos);
				float price = std::atof(line.substr(pos + 1).c_str());
				_arr[date] = price;
			}
		}
	}
	
	inFile.close();
}

std::string trim(const std::string &str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");

	if (start == std::string::npos)
		return "";
    return str.substr(start, end - start + 1);
}

bool isValidDate(const std::string &date)
{
	bool valid = true;
	
	if (date.size() != 10)
		valid = false;
	if (valid && (date[4] != '-' || date[7] != '-'))
		valid = false;
	for (int i = 0; valid && i < 10; i++)
	{
		if (i != 4 && i != 7)
		{
			if (!std::isdigit(date[i]))
				valid = false;
		}
	}
	if (valid)
	{
		int year = std::atoi(date.substr(0, 4).c_str());
		int month = std::atoi(date.substr(5, 2).c_str());
		int day = std::atoi(date.substr(8, 2).c_str());

		int maxDaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			maxDaysInMonth[1] = 29;

		if (month < 1 || month > 12)
			valid = false;

		if (valid)
		{
			if (day < 1 || day > maxDaysInMonth[month - 1])
				valid = false;
		}
	}	
	return (valid);
}

void BitcoinExchange::processInput(const std::string &file)
{
	std::ifstream inFile(file.c_str());
	if (!inFile.is_open())
		throw std::runtime_error("cannot open file!");

	std::string line;
	std::getline(inFile, line);
	while (std::getline(inFile, line))
	{
		std::size_t	pos = line.find('|');
		if (pos == std::string::npos || pos == 0 || pos + 1 >= line.size() || line[pos - 1] != ' ' || line[pos + 1] != ' ')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		else
		{
			if (pos > 0)
			{
				std::string date = trim(line.substr(0, pos));
				float price = std::atof(line.substr(pos + 1).c_str());
				
				if (price < 0)
				{
					std::cerr << "Error: not a positive number." << std::endl;
					continue;
				}
				else if (price > 1000)
				{
					std::cerr << "Error: too large a number." << std::endl;
					continue;
				}
				if (!isValidDate(date))
				{
					std::cerr << "Error: bad input => " << date << std::endl;
					continue;
				}
					
				std::map<std::string, float>::iterator it = _arr.lower_bound(date);
				if (it == _arr.end() || it->first != date)
				{
					if (it == _arr.begin())
					{
						std::cerr << "Error: bad input => " << date << std::endl;
						continue;
					}
					--it;
				}
				if (it != _arr.end())
				{
					float res = it->second * price;
    				std::cout << date << " => " << price << " = " << res << std::endl;
				}
			}
		}
	}
	
	inFile.close();
}