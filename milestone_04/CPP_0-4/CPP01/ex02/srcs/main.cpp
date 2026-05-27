/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:46:51 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/27 09:46:33 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPtr = &str;
	std::string &stringRef = str;

	std::cout << &str << " / " << stringPtr << " / " << &stringRef << std::endl;
	std::cout << str << " / " << *stringPtr << " / " << stringRef << std::endl;
	return (0);
}
