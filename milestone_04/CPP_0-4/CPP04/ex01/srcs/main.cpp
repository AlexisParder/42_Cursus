/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/15 11:57:13 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    std::cout << "--- Array of animals ---" << std::endl;
    const int size = 10;
    Animal *animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Sounds ---" << std::endl;
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Delete array ---" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n--- Deep copy test ---" << std::endl;
    Dog a;
    Dog b(a);
    std::cout << "a address: " << &a << std::endl;
    std::cout << "b address: " << &b << std::endl;

    std::cout << "\n--- Copy assignment test ---" << std::endl;
    Dog c;
    c = a;

    std::cout << "\n--- Cat deep copy ---" << std::endl;
    Cat ca;
    Cat cb(ca);
    Cat cc;
    cc = ca;
    return (0);
}
