/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:23:40 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/05 09:29:00 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
	// Shrubbery
	{
		std::cout << "--- Error Shrubbery (No Signed) ---" << std::endl;
		try
		{
			Bureaucrat alex("Alex", 42);
			ShrubberyCreationForm form("home");
			alex.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Error Shrubbery (Low Grade) ---" << std::endl;
		try
		{
			Bureaucrat tom("Tom", 145);
			ShrubberyCreationForm form("home");
			form.beSigned(tom);
			tom.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Success Shrubbery ---" << std::endl;
		try
		{
			Bureaucrat tiben("Tiben", 137);
			ShrubberyCreationForm form("home");
			form.beSigned(tiben);
			tiben.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// Robotomy
	{
		std::cout << "\n--- Error Robotomy (No Signed) ---" << std::endl;
		try
		{
			Bureaucrat alex("Alex", 42);
			RobotomyRequestForm form("Bender");
			alex.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Error Robotomy (Low Grade) ---" << std::endl;
		try
		{
			Bureaucrat tom("Tom", 72);
			RobotomyRequestForm form("Bender");
			form.beSigned(tom);
			tom.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Success Robotomy ---" << std::endl;
		try
		{
			Bureaucrat tiben("Tiben", 45);
			RobotomyRequestForm form("Bender");
			form.beSigned(tiben);
			tiben.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// Presidential
	{
		std::cout << "\n--- Error Presidential (No Signed) ---" << std::endl;
		try
		{
			Bureaucrat alex("Alex", 42);
			PresidentialPardonForm form("Arthur Dent");
			alex.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Error Presidential (Low Grade) ---" << std::endl;
		try
		{
			Bureaucrat tom("Tom", 25);
			PresidentialPardonForm form("Arthur Dent");
			form.beSigned(tom);
			tom.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n--- Success Presidential ---" << std::endl;
		try
		{
			Bureaucrat tiben("Tiben", 5);
			PresidentialPardonForm form("Arthur Dent");
			form.beSigned(tiben);
			tiben.executeForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	// make form
	{
		std::cout << "\n--- Shrubbery Form ---" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "home");
		delete rrf;
	}
	{
		std::cout << "\n--- Robotomy Form ---" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}
	{
		std::cout << "\n--- Presidential Form ---" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		delete rrf;
	}
	{
		std::cout << "\n--- Invalid Form ---" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("invalid form", "Alex");
		delete rrf;
	}
	return 0;
}