#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	setRawBits(0);
}

Fixed::Fixed(const int value)
{
	this->value_ = value << this->fractional_bits_;
}

Fixed::Fixed(const float value)
{
	this->value_ = static_cast<int>(roundf(value * (1 << this->fractional_bits_)));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->value_ = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
}

float Fixed::toFloat() const
{
	return static_cast<float>(this->value_) / (1 << this->fractional_bits_);
}

int Fixed::toInt() const
{
	return this->value_ >> this->fractional_bits_;
}

int Fixed::getRawBits() const
{
	return this->value_;
}

void Fixed::setRawBits(int const raw)
{
	this->value_ = raw;
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return out;
}

Fixed operator+(Fixed const &a, Fixed const &b)
{
	return Fixed(a.toFloat() + b.toFloat());
}

Fixed operator-(Fixed const &a, Fixed const &b)
{
	return Fixed(a.toFloat() - b.toFloat());
}

Fixed operator*(Fixed const &a, Fixed const &b)
{
	return Fixed(a.toFloat() * b.toFloat());
}

Fixed operator/(Fixed const &a, Fixed const &b)
{
	return Fixed(a.toFloat() / b.toFloat());
}

Fixed operator++(Fixed &a)
{
	a.setRawBits(a.getRawBits() + 1);
	return a;
}

Fixed operator++(Fixed &a, int)
{
	Fixed tmp = a;
	a.setRawBits(a.getRawBits() + 1);
	return tmp;
}

Fixed operator--(Fixed &a)
{
	a.setRawBits(a.getRawBits() - 1);
	return a;
}

Fixed operator--(Fixed &a, int)
{
	Fixed tmp = a;
	a.setRawBits(a.getRawBits() - 1);
	return tmp;
}

bool operator>(Fixed const &a, Fixed const &b)
{
	return a.toFloat() > b.toFloat();
}

bool operator<(Fixed const &a, Fixed const &b)
{
	return a.toFloat() < b.toFloat();
}

bool operator>=(Fixed const &a, Fixed const &b)
{
	return a.toFloat() >= b.toFloat();
}

bool operator<=(Fixed const &a, Fixed const &b)
{
	return a.toFloat() <= b.toFloat();
}

bool operator==(Fixed const &a, Fixed const &b)
{
	return a.toFloat() == b.toFloat();
}

bool operator!=(Fixed const &a, Fixed const &b)
{
	return a.toFloat() != b.toFloat();
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}
