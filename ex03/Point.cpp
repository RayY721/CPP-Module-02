/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:39:19 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/12 20:59:43 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
}

Point::Point( const float x, const float y ) : _x(x), _y(y)
{
}

Point::Point( const Point& other ) : _x(other._x), _y(other._y)
{
}

Point& Point::operator=( const Point& other )
{
	(void)other;
	return *this;
}

Point::~Point( void )
{
}

Fixed const& Point::getX( void ) const
{
	return (_x);
}

Fixed const& Point::getY( void ) const
{
	return (_y);
}