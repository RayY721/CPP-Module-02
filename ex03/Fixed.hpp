/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:36:29 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/12 13:36:32 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float f );
		Fixed( const Fixed& other );
		~Fixed( void );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		Fixed& operator=( const Fixed& other );
		// Comparison operators
		bool operator>( const Fixed& other) const;
		bool operator<( const Fixed& other) const;
		bool operator>=( const Fixed& other) const;
		bool operator<=( const Fixed& other) const;
		bool operator==( const Fixed& other) const;
		bool operator!=( const Fixed& other) const;

		// Arithmetic operators
		// Fixed& operator+(const) const;
		Fixed operator+( const Fixed& other ) const;
		Fixed operator-( const Fixed& other ) const;
		Fixed operator*( const Fixed& other ) const;
		Fixed operator/( const Fixed& other ) const;

		// four static member functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
		
		// four increment/decrement operators
		Fixed& operator++( void );		// pre-increment
		Fixed operator++( int );		// post-increment
		Fixed& operator--( void );		// pre-decrement
		Fixed operator--( int );		// post-decrement
	};

// The return type must be std::ostream& to allow chaining of the operator<< calls
// E.g. std::cout << fixedValue << std::endl;
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif