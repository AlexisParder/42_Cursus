/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:48:58 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:53:05 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Colors.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_learned[i] = NULL;
	std::cout << BLUE << "MateriaSource has been created!" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
        _learned[i] = NULL;
	*this = other;
	std::cout << GREEN << "MateriaSource has been copied!" << RESET << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_learned[i])
				delete _learned[i];
			if (other._learned[i])
				_learned[i] = other._learned[i]->clone();
			else
				_learned[i] = NULL;
		}
	}
	std::cout << MAGENTA << "MateriaSource has been assigned!" << RESET << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_learned[i])
			delete _learned[i];
	}
	std::cout << RED << "MateriaSource has been destroyed!" << RESET << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_learned[i])
		{
			_learned[i] = m;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_learned[i] && _learned[i]->getType() == type)
			return (_learned[i]->clone());
	}
	return (NULL);
}