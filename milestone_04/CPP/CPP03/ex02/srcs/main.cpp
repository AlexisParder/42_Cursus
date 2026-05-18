/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:38:02 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/14 10:00:40 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap frag("Bob");
    frag.attack("enemy");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();
    return (0);
}