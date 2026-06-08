/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 11:12:19 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/08 11:39:28 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		{
			std::cout << "--- DEFAULT CHAR ---"	<< std::endl;
			ScalarConverter::convert("'a'");
		}
		{
			std::cout << "\n--- DEFAULT INT ---"	<< std::endl;
			ScalarConverter::convert("42");
		}
		{
			std::cout << "\n--- DEFAULT FLOAT ---"	<< std::endl;
			ScalarConverter::convert("4.2f");
		}
		{
			std::cout << "\n--- DEFAULT DOUBLE ---"	<< std::endl;
			ScalarConverter::convert("-4.2");
		}
		return 0;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}