/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:51:50 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Colors.hpp"

int main(void)
{
    std::cout << YELLOW << "--- Basic test from subject ---" << RESET << std::endl;
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << YELLOW << "\n--- Full inventory test ---" << RESET << std::endl;
    ICharacter *alice = new Character("alice");
    AMateria *a0 = src->createMateria("ice");
    AMateria *a1 = src->createMateria("cure");
    AMateria *a2 = src->createMateria("ice");
    AMateria *a3 = src->createMateria("cure");
    AMateria *a4 = src->createMateria("ice");
    alice->equip(a0);
    alice->equip(a1);
    alice->equip(a2);
    alice->equip(a3);
    alice->equip(a4);
    delete a4;

    alice->use(0, *bob);
    alice->use(1, *bob);
    alice->use(2, *bob);
    alice->use(3, *bob);

    std::cout << YELLOW << "\n--- Unequip test ---" << RESET << std::endl;
    AMateria *dropped = a0;
    alice->unequip(0);
    alice->use(0, *bob);
    delete dropped;

    std::cout << YELLOW << "\n--- Unknown materia test ---" << RESET << std::endl;
    AMateria *unknown = src->createMateria("fire");
    if (!unknown)
        std::cout << "Unknown materia type!" << std::endl;

    std::cout << YELLOW << "\n--- Deep copy test ---" << RESET << std::endl;
    Character orig("original");
    orig.equip(src->createMateria("ice"));
    Character copy(orig);
    copy.use(0, *bob);

    std::cout << YELLOW << "\n--- Delete ---" << RESET << std::endl;
    delete bob;
    delete me;
    delete alice;
    delete src;

    return (0);
}
