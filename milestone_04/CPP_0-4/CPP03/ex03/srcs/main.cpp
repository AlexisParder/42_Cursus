/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:38:02 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/28 11:41:04 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamond("Diamond");
    
    diamond.attack("enemy");
    
    diamond.takeDamage(20);
    
    diamond.beRepaired(10);
    
    diamond.guardGate();
    diamond.highFivesGuys();

    diamond.whoAmI();
    
    return (0);
}