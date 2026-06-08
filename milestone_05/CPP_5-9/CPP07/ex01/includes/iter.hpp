/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:35:14 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/08 15:00:42 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template <typename T, typename F>
void iter(T *arr, const size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
		func(arr[i]);
}
