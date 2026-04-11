/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:34:17 by achauvie          #+#    #+#             */
/*   Updated: 2026/04/11 19:07:24 by achauvie         ###   ########.fr       */
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
		if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}