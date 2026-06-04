/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:23:40 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/04 11:35:37 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "--- Valid Bureaucrat ---" << std::endl;
		try
		{
			Bureaucrat alex("Alex", 42);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- High Grade ---" << std::endl;
		try 
		{
			Bureaucrat bob("Bob", 0);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Low Grade ---" << std::endl;
		try
		{
			Bureaucrat tiben("Tiben", 154);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n--- Promote Grade ---" << std::endl;
		try
		{
			Bureaucrat john("John", 5);
			while (1)
				john.promote();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n--- Demote Grade ---" << std::endl;
		try
		{
			Bureaucrat doe("Doe", 145);
			while (1)
				doe.demote();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "\n--- Valid Bureaucrat Operator ---" << std::endl;
		try
		{
			Bureaucrat alex("Alex", 42);
			std::cout << alex << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}