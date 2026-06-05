/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:37:46 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/05 15:21:39 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default"), _gradeToSign(150), _gradeToExec(150)
{
	_isSigned = false;
	std::cout << "[Default AForm] " << _name << " was created!" << std::endl;
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
	_isSigned = false;
	std::cout << "[AForm] " << _name << " was created!" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other.getSigned();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "[AForm] " << _name << " was deleted!" << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("this rank is too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("this rank is too low!");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("The form is not signed!");
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

const std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSigned(void) const
{
	return(_isSigned);
}

int AForm::getGradeToSign(void) const
{
	return(_gradeToSign);
}

int AForm::getGradeToExec(void) const
{
	return(_gradeToExec);
}

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
	out << "AForm Information\nName: " << other.getName() << "\nIs signed: " << other.getSigned() << "\nGrade to sign: " << other.getGradeToSign() << "\nGrade to exec: " << other.getGradeToExec() << std::endl;
	return (out);
}