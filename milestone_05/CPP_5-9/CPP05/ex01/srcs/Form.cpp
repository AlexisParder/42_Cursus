/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:37:46 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/04 13:50:23 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	_isSigned = false;
	std::cout << "[Form] " << _name << " was created!" << std::endl;
}

Form::Form(const Form &other) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), _gradeToExec(other.getGradeToExec())
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other.getSigned();
	return (*this);
}

Form::~Form()
{
	std::cout << "[Form] " << _name << " was deleted!" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("this rank is too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("this rank is too low!");
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSigned(void) const
{
	return(_isSigned);
}

int Form::getGradeToSign(void) const
{
	return(_gradeToSign);
}

int Form::getGradeToExec(void) const
{
	return(_gradeToExec);
}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
	out << "Form Information\nName: " << other.getName() << "\nIs signed: " << other.getSigned() << "\nGrade to sign: " << other.getGradeToSign() << "\nGrade to exec: " << other.getGradeToExec() << std::endl;
	return (out);
}