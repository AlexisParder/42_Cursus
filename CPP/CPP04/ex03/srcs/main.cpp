/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 12:05:30 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    std::cout << "--- Basic test from subject ---" << std::endl;
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

    std::cout << "\n--- Full inventory test ---" << std::endl;
    ICharacter *alice = new Character("alice");
    AMateria *a0 = src->createMateria("ice");
    AMateria *a1 = src->createMateria("cure");
    AMateria *a2 = src->createMateria("ice");
    AMateria *a3 = src->createMateria("cure");
    AMateria *a4 = src->createMateria("ice"); // ne sera pas équipée
    alice->equip(a0);
    alice->equip(a1);
    alice->equip(a2);
    alice->equip(a3);
    alice->equip(a4); // inventaire plein
    delete a4;        // on delete car non équipée

    alice->use(0, *bob);
    alice->use(1, *bob);
    alice->use(2, *bob);
    alice->use(3, *bob);

    std::cout << "\n--- Unequip test ---" << std::endl;
    AMateria *dropped = a0; // on sauvegarde avant unequip
    alice->unequip(0);
    alice->use(0, *bob);    // rien ne se passe
    delete dropped;         // on delete la materia droppée

    std::cout << "\n--- Unknown materia test ---" << std::endl;
    AMateria *unknown = src->createMateria("fire");
    if (!unknown)
        std::cout << "Unknown materia type!" << std::endl;

    std::cout << "\n--- Deep copy test ---" << std::endl;
    Character orig("original");
    orig.equip(src->createMateria("ice"));
    Character copy(orig);
    copy.use(0, *bob);

    std::cout << "\n--- Delete ---" << std::endl;
    delete bob;
    delete me;
    delete alice;
    delete src;

    return (0);
}
