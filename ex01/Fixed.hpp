/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 20:50:00 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/10 21:54:04 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public:
	
		Fixed( void );
		Fixed( const int n );
		Fixed( const float f );
		Fixed( const Fixed& other );
		Fixed& operator=( const Fixed& other );
		~Fixed( void );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
	private:
		int					_rawBits;
		static const int	_fractionalBits = 8;
	};
	
// float operator<<(Fixed& value);		// TODO: don't know what to do

// The return type must be std::ostream& to allow chaining of the operator<< calls
// E.g. std::cout << fixedValue << std::endl;
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif