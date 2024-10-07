#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value_;
	static const int fractional_bits_ = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	float toFloat() const;
	int toInt() const;

	int getRawBits() const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif
