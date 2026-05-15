/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 11:48:58 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 12:09:54 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_learned[i] = NULL;
	std::cout << "MateriaSource has been created!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; i++)
        _learned[i] = NULL;
	*this = other;
	std::cout << "MateriaSource has been copied!" << std::endl;
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
	std::cout << "MateriaSource has been assigned!" << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_learned[i])
			delete _learned[i];
	}
	std::cout << "MateriaSource has been destroyed!" << std::endl;
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