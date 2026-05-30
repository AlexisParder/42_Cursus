/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/30 08:27:13 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Colors.hpp"

int main(void)
{
    std::cout << YELLOW << "--- Array of animals ---" << RESET << std::endl;
    const int size = 10;
    Animal *animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << YELLOW << "\n--- Sounds ---" << RESET << std::endl;
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    std::cout << YELLOW << "\n--- Delete array ---" << RESET << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << YELLOW << "\n--- Deep copy test ---" << RESET << std::endl;
    Dog a;
    Dog b(a);
    std::cout << "a address: " << &a << std::endl;
    std::cout << "b address: " << &b << std::endl;

    std::cout << YELLOW << "\n--- Copy assignment test ---" << RESET << std::endl;
    Dog c;
    c = a;

    std::cout << YELLOW << "\n--- Cat deep copy ---" << RESET << std::endl;
    Cat ca;
    Cat cb(ca);
    Cat cc;
    cc = ca;
    return (0);
}
