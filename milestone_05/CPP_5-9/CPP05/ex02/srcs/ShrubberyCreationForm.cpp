/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:59:49 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/05 15:23:35 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137), _target("Default target")
{
	std::cout << "[Default ShrubberyCreationForm] " << _target << " was created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm(target, 145, 137), _target(target)
{
	std::cout << "[ShrubberyCreationForm] " << _target << " was created!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	(void)other;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "[ShrubberyCreationForm] " << _target << " was deleted!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	std::string outFilename = _target + "_shrubbery";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: cannot open outfile" << std::endl;
		return ;
	}
	for (int i = 0; i < 2; i++)
	{
		outFile << "    *        *    " << std::endl;
		outFile << "   ***      ***   " << std::endl;
		outFile << "  *****    *****  " << std::endl;
		outFile << " *******  ******* " << std::endl;
		outFile << "    |        |    " << std::endl;
	}
	outFile.close();
}