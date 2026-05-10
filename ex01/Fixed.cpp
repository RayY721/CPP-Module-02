/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:37:36 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/10 21:54:39 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _rawBits(n << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;

}

Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed( const Fixed& other )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other._rawBits;
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
	return ((float)_rawBits / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const
{
	return (_rawBits >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
