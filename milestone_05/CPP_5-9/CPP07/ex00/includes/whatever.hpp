/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:23:55 by achauvie          #+#    #+#             */
/*   Updated: 2026/06/08 14:32:05 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
};

template <typename T>
T min(const T &a, const T &b)
{
	if (a < b)
		return a;
	return b;
};

template <typename T>
T max(const T &a, const T &b)
{
	if (a > b)
		return a;
	return b;
};