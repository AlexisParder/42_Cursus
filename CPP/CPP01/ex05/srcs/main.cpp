/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 10:44:59 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/11 12:48:52 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	{
		Harl harl;
		harl.complain("DEBUG");
	}
	{
		Harl harl;
		harl.complain("INFO");
	}
	{
		Harl harl;
		harl.complain("WARNING");
	}
	{
		Harl harl;
		harl.complain("ERROR");
	}
	{
		Harl harl;
		harl.complain("INVALID");
	}
	return (0);
}