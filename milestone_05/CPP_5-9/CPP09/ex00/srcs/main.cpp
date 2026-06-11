/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 08:59:56 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/11 10:25:17 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Invalid cmd, format:\n./btc <input_file>" << std::endl;
		return 1;
	}
	BitcoinExchange btc;

	try
	{
		btc.chargeCSV("./data.csv");
		btc.processInput(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}