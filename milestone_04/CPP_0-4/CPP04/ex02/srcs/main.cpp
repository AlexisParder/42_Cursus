/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 11:59:23 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const int size = 10;
    Animal *animals[size];

    std::cout << "\n--- Creating animals ---" << std::endl;
    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Sounds ---" << std::endl;
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Delete ---" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    return (0);
}
