/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 09:22:35 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/11 10:31:57 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./ex04 filename s1 s2" << std::endl;
		return (1);
	}

	if (std::string(av[2]).empty())
	{
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}

	if (std::string(av[3]).empty())
	{
		std::cout << "Error: s2 cannot be empty" << std::endl;
		return (1);
	}
	
	std::ifstream inFile(av[1]);
	if (!inFile.is_open())
	{
		std::cout << "Error: cannot open infile" << std::endl;
		return (1);
	}

	std::string outFilename = std::string(av[1]) + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open())
	{
		std::cout << "Error: cannot open outfile" << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		std::size_t	pos = line.find(av[2]);
		while (pos != std::string::npos)
		{
			line = line.substr(0, pos) + av[3] + line.substr(pos + std::string(av[2]).size());
			pos = line.find(av[2], pos + std::string(av[3]).size());
		}
		outFile << line << "\n";
	}
	
	return (0);
}