#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    _fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    _fixedPointValue = other._fixedPointValue;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _fixedPointValue = other._fixedPointValue;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return _fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return _fixedPointValue / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _fixedPointValue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

