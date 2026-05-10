/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 12:27:08 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/09 19:07:32 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

// a copy constructor
// a copy assignment operator overload
class Fixed
{
    public:
        Fixed( void );
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
        ~Fixed( void );

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

};

#endif