/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 21:31:39 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/10 22:03:16 by kuyu             ###   ########.fr       */
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

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_rawBits = other._rawBits;
	return (*this);
}

bool Fixed::operator>( const Fixed& other ) const
{
	return (this->_rawBits > other._rawBits);
}

bool Fixed::operator<( const Fixed& other ) const
{
	return (this->_rawBits < other._rawBits);
}

bool Fixed::operator>=( const Fixed& other ) const
{
	return (this->_rawBits >= other._rawBits);
}

bool Fixed::operator<=( const Fixed& other ) const
{
	return (this->_rawBits <= other._rawBits);
}

bool Fixed::operator==( const Fixed& other ) const
{
	return (this->_rawBits == other._rawBits);
}

bool Fixed::operator!=( const Fixed& other ) const
{
	return (this->_rawBits != other._rawBits);
}

Fixed Fixed::operator+( const Fixed& other ) const
{
	Fixed result;

	result._rawBits = this->_rawBits + other._rawBits;

	return (result);
}

Fixed Fixed::operator-( const Fixed& other ) const
{
	Fixed result;

	result._rawBits = this->_rawBits - other._rawBits;

	return (result);
}

Fixed Fixed::operator*( const Fixed& other ) const
{
	Fixed result;

	result._rawBits = (this->_rawBits * other._rawBits) >> 	_fractionalBits;

	return (result);
}

Fixed Fixed::operator/( const Fixed& other ) const
{
	Fixed result;

	if (other._rawBits == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		result._rawBits = 0;
		return (result);
	}

	result._rawBits = (this->_rawBits << _fractionalBits) / other._rawBits;

	return (result);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
