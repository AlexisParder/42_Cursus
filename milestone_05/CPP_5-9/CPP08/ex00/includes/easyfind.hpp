/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 09:15:05 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/10 09:38:23 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <stdexcept>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int search)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), search);
	if (iter == container.end())
		throw std::runtime_error("The value was not found!");
	return (iter);
}