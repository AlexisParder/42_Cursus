/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 09:55:15 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/13 14:21:31 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed crossProduct(Point const a, Point const b, Point const p)
{
    return ((b.getX() - a.getX()) * (p.getY() - a.getY())
          - (b.getY() - a.getY()) * (p.getX() - a.getX()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1 = crossProduct(a, b, point);
    Fixed d2 = crossProduct(b, c, point);
    Fixed d3 = crossProduct(c, a, point);

	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return (false);
		
	bool allPos = (d1 > Fixed(0)) && (d2 > Fixed(0)) && (d3 > Fixed(0));
    bool allNeg = (d1 < Fixed(0)) && (d2 < Fixed(0)) && (d3 < Fixed(0));
    return (allPos || allNeg);
}