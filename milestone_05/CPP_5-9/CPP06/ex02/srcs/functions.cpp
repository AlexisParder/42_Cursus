/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:16:52 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/09 08:59:46 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

Base *generate(void)
{
	int res = std::rand() % 3;

	if (res == 0)
		return new A();
	else if (res == 1)
		return new B();
	else
		return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
    	std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
    	std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
    	std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch(std::exception &e) 
	{
		(void)e;
	}

	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch(std::exception &e) 
	{
		(void)e;
	}

	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(std::exception &e) 
	{
		(void)e;
	}
}