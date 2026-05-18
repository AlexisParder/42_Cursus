/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achauvie <achauvie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:17:35 by achauvie          #+#    #+#             */
/*   Updated: 2026/05/13 09:26:50 by achauvie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _fractBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_value / (1 << _fractBits));
}

int Fixed::toInt(void) const
{
    return (_value >> _fractBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return (_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return (_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (_value != other._value);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (Fixed(toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++(void)
{
	_value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed curr(*this);
	_value++;
	return (curr);
}

Fixed &Fixed::operator--(void)
{
	_value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed curr(*this);
	_value--;
	return (curr);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}