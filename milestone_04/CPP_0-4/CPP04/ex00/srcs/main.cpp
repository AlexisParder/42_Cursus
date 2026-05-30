/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:22:23 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int main(void)
{
    std::cout << YELLOW << "--- Animal tests ---" << RESET << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << YELLOW << "\n--- Types ---" << RESET << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    std::cout << YELLOW << "\n--- Sounds ---" << RESET << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << YELLOW << "\n--- Delete ---" << RESET << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << YELLOW << "\n--- WrongAnimal tests ---" << RESET << std::endl;
    const WrongAnimal *wrong = new WrongCat();
    
    std::cout << YELLOW << "\n--- WrongAnimal Types ---" << RESET << std::endl;
    std::cout << wrong->getType() << std::endl;

    std::cout << YELLOW << "\n--- WrongAnimal Sounds ---" << RESET << std::endl;
    wrong->makeSound();

    std::cout << YELLOW << "\n--- WrongAnimal Delete ---" << RESET << std::endl;
    delete wrong;

    return (0);
}
