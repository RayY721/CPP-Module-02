#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    public:
        Fixed();
        // a copy constructor
        // a copy assignment operator overload
        ~Fixed();

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );

    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

};

#endif