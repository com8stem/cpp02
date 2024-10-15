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
		this->setRawBits(other.getRawBits());
	}
	return *this;
}

Fixed::~Fixed()
{
}

float Fixed::toFloat() const
{
	return static_cast<float>(this->getRawBits()) / (1 << this->fractional_bits_);
}

int Fixed::toInt() const
{
	return this->getRawBits() >> this->fractional_bits_;
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

Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + other.getRawBits());
	return result;
}

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::operator*(Fixed const &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() * other.getRawBits() / (1 << this->fractional_bits_));
	return result;
}

Fixed Fixed::operator/(Fixed const &other) const
{
	Fixed result;
	result.setRawBits(this->getRawBits() * (1 << this->fractional_bits_) / other.getRawBits());
	return result;
}

Fixed Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() + 1);
	return tmp;
}

Fixed Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->setRawBits(this->getRawBits() - 1);
	return tmp;
}

bool Fixed::operator>(Fixed const &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(Fixed const &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(Fixed const &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(Fixed const &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(Fixed const &other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(Fixed const &other) const
{
	return this->getRawBits() != other.getRawBits();
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}
