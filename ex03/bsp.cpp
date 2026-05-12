/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:22:19 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/12 21:23:31 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed bsp_helper( Point const a, Point const b, Point const point)
{
	return ((b.getX() - a.getX()) * (point.getY() - a.getY())
	 - (b.getY() - a.getY()) * (point.getX() - a.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed ab = bsp_helper(a, b, point);
	Fixed bc = bsp_helper(b, c, point);
	Fixed ca = bsp_helper(c, a, point);
	Fixed zero(0);

	bool has_neg = (ab < zero) || (bc < zero) || (ca < zero);
	bool has_pos = (ab > zero) || (bc > zero) || (ca > zero);

	if (ab == zero || bc == zero || ca == zero)
		return (false);
	if (has_neg && has_pos)
		return (false);
	return (true);
}
