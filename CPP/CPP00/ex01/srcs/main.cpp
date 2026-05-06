/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:34:17 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/06 15:19:55 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

int main(void)
{
	PhoneBook phonebook;
	std::string	input;

	std::cout << "Commands: ADD | SEARCH | EXIT" << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (std::cin.eof())
        {
            std::cout << std::endl;
            break;
        }
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}