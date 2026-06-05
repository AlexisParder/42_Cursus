/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 13:23:28 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/05 15:17:59 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default")
{
	_grade = 150;
	std::cout << "[Default Bureaucrat] " << _name << " was created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "[Bureaucrat] " << _name << " was created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] " << _name << " was deleted!" << std::endl;
}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::promote(void)
{
	int oldGrade = _grade;
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << "Promote " << _name << ", old grade: " << oldGrade << ", new grade: " << _grade << std::endl;
}

void Bureaucrat::demote(void)
{
	int oldGrade = _grade;
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << "Demote " << _name << ", old grade: " << oldGrade << ", new grade: " << _grade << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".";
    return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The rank is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The rank is too low!");
}

void Bureaucrat::signForm(Form &other)
{
	try
	{
		other.beSigned(*this);
		if (other.getSigned())
			std::cout << _name << " signed " << other.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << other.getName() << " because " << e.what() << std::endl;
	}
}