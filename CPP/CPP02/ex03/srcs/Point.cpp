/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 09:55:31 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/14 13:49:24 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{}

Point::Point(const float x, const float y) : _x(x), _y(y)
{}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}

Point::~Point(void)
{}

Fixed Point::getX(void) const
{
    return (_x);
}

Fixed Point::getY(void) const
{
    return (_y);
}