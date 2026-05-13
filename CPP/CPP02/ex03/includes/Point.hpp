/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 09:55:46 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/13 11:14:49 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point(void);
		Fixed getX(void) const;
		Fixed getY(void) const;
};