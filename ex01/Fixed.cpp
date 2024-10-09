#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	setRawBits(0);
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << this->fractional_bits_);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(static_cast<int>(roundf(value * (1 << this->fractional_bits_))));
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
	{
		setRawBits(other.getRawBits());
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
