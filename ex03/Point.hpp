/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:34:51 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/12 20:54:21 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{

    private:
        Fixed const	_x;
        Fixed const	_y;

    public:
		Point( void );
		Point( const float x, const float y );
		Point( const Point& other );
		Point& operator=( const Point& other );
		~Point( void );

		const Fixed& getX( void ) const;
		const Fixed& getY( void ) const;
		// equivalent to Fixed const& getX( void ) const;
};

#endif