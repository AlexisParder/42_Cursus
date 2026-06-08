/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:16:52 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/08 13:39:58 by achauvie         ###   ########.fr       */
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
	else
		std::cout << "Invalid type!" << std::endl;
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p) != NULL)
    	std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p) != NULL)
    	std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p) != NULL)
    	std::cout << "C" << std::endl;
	else
		std::cout << "Invalid type!" << std::endl;
}