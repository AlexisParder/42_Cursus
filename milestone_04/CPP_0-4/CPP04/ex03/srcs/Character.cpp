/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 10:37:22 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:57:33 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Colors.hpp"

Character::Character(std::string const &name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << BLUE << "Character " << _name << " has been created!" << RESET << std::endl;
}

Character::Character(const Character &other)
{
	for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
	*this = other;
	std::cout << GREEN << "Character " << _name << " has been copied!" << RESET << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	std::cout << MAGENTA << "Character " << _name << " has been assigned!" << RESET << std::endl;
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	std::cout << RED << "Character " << _name << " has been destroyed!" << RESET << std::endl;
}

std::string const &Character::getName() const
{
	return (_name);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << _name << "'s inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cerr << "Error: invalid index, must be between 0 and 3" << std::endl;
		return ;
	}
	std::cout << _name << " unequipped slot " << idx << std::endl;
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cerr << "Error: invalid index, must be between 0 and 3" << std::endl;
		return ;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
}