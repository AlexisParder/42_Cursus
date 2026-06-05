/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:13:28 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/05 09:18:51 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern was created!" << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern was deleted!" << std::endl;
}

AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *createPresidential(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	struct FormType
	{
		std::string name;
		AForm* (*create)(const std::string &target);
	};

	FormType arr[3];
	arr[0].name = "robotomy request";
	arr[0].create = &createRobotomy;
	arr[1].name = "shrubbery creation";
	arr[1].create = &createShrubbery;
	arr[2].name = "presidential pardon";
	arr[2].create = &createPresidential;

	for (int i = 0; i < 3; i++)
	{
		if (arr[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return arr[i].create(target);
		}
	}
	std::cerr << "Intern cannot create form '" << formName << "'" << std::endl; 
	return NULL;
}