/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 11:37:32 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/05 09:24:52 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExec;
	public:
		AForm(const std::string &name, const int gradeToSign, const int gradeToExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm(void);
		void beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		const std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;
		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &other);