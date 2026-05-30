/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:11:37 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "--- Animal tests ---" << std::endl;
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "\n--- Types ---" << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    std::cout << "\n--- Sounds ---" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n--- Delete ---" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- WrongAnimal tests ---" << std::endl;
    const WrongAnimal *wrong = new WrongCat();
    
    std::cout << "\n--- WrongAnimal Types ---" << std::endl;
    std::cout << wrong->getType() << std::endl;

    std::cout << "\n--- WrongAnimal Sounds ---" << std::endl;
    wrong->makeSound();

    std::cout << "\n--- WrongAnimal Delete ---" << std::endl;
    delete wrong;

    return (0);
}
