/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:13:38 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/08 11:45:59 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

void convertPseudoLiterals(const std::string &str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nan" || str == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void convertChar(const std::string &str)
{
	std::cout << "char: '" << str[1] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(str[1]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(str[1]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(str[1]) << std::endl;
}

void convertFloat(const std::string &str)
{
	float strInFloat = static_cast<float>(std::atof(str.c_str()));

	if (std::isprint(static_cast<char>(strInFloat)))
		std::cout << "char: '" << static_cast<char>(strInFloat) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
		
	if (strInFloat > static_cast<float>(INT_MAX) || strInFloat < static_cast<float>(INT_MIN))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(strInFloat) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << strInFloat << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(strInFloat) << std::endl;
}

void convertDouble(const std::string &str)
{
	double strInDouble = std::atof(str.c_str());

	if (std::isprint(static_cast<char>(strInDouble)))
		std::cout << "char: '" << static_cast<char>(strInDouble) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
		
	if (strInDouble > static_cast<double>(INT_MAX) || strInDouble < static_cast<double>(INT_MIN))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(strInDouble) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(strInDouble) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << strInDouble << std::endl;
}

void convertInt(const std::string &str)
{
	long strInLong = std::atol(str.c_str());

	if (std::isprint(static_cast<char>(strInLong)))
		std::cout << "char: '" << static_cast<char>(strInLong) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
		
	if (strInLong > INT_MAX || strInLong < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << strInLong << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(strInLong) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(strInLong) << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		convertPseudoLiterals(str);
	else if (str.size() == 3 && str[0] == '\'' && str[2] == '\'')
		convertChar(str);
	else if (str.find('.') != std::string::npos && str[str.size() - 1] == 'f')
		convertFloat(str);
	else if (str.find('.') != std::string::npos && str[str.size() - 1] != 'f' )
		convertDouble(str);
	else	
		convertInt(str);
}