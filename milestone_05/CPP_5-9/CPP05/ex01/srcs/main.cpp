/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:23:40 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/04 13:54:55 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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
	{
		std::cout << "\n--- Valid Form ---" << std::endl;
		try
		{
			Form form1("Form 1", 2, 3);
			std::cout << form1 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	{
		std::cout << "\n--- Success Signed Form ---" << std::endl;
		try 
		{
			Bureaucrat tom("Tom", 2);
			Form form2("Form 2", 3, 4);
			std::cout << "Before: " << std::endl;
			std::cout << form2 << std::endl;
			tom.signForm(form2);
			std::cout << "After: " << std::endl;
			std::cout << form2 << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Error Low grade Signed Form ---" << std::endl;
		try 
		{
			Bureaucrat carlos("Carlos", 128);
			Form form3("Form 3", 10, 15);
			carlos.signForm(form3);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Error Invalid Grade Form ---" << std::endl;
		try 
		{
			Bureaucrat patrick("Carlos", 6);
			Form form4("Form 4", 0, 5);
			patrick.signForm(form4);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}