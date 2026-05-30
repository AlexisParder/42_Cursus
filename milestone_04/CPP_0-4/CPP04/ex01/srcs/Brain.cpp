/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 09:47:09 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:25:17 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Colors.hpp"

Brain::Brain(void)
{
	std::cout << BLUE << "Brain has been created!" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << GREEN << "Brain has been copied!" << RESET << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	std::cout << MAGENTA << "Brain has been assigned!" << RESET << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << RED << "Brain has been destroyed!" << RESET << std::endl;
}