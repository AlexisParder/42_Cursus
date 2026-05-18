/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:38:02 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/14 10:25:32 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap diamond("Diamond");
    
    std::cout << "--- Attack ---" << std::endl;
    diamond.attack("enemy");
    
    std::cout << "--- Take Damage ---" << std::endl;
    diamond.takeDamage(20);
    
    std::cout << "--- Repair ---" << std::endl;
    diamond.beRepaired(10);
    
    std::cout << "--- Special abilities ---" << std::endl;
    diamond.guardGate();
    diamond.highFivesGuys();
    
    std::cout << "--- Who am I? ---" << std::endl;
    diamond.whoAmI();
    
    return (0);
}