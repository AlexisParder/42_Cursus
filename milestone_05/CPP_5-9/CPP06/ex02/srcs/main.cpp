/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 13:12:38 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/08 13:39:59 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int main(void)
{
	std::srand(std::time(NULL) ^ clock());
	
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;
	
	return 0;
}