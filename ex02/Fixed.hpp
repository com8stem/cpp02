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

	static Fixed const&max(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const&min(Fixed const &a, Fixed const &b);
	static Fixed &min(Fixed &a, Fixed &b);

	int getRawBits() const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
Fixed operator+(Fixed const &a, Fixed const &b);
Fixed operator-(Fixed const &a, Fixed const &b);
Fixed operator*(Fixed const &a, Fixed const &b);
Fixed operator/(Fixed const &a, Fixed const &b);
Fixed operator++(Fixed &a);
Fixed operator++(Fixed &a, int);
Fixed operator--(Fixed &a);
Fixed operator--(Fixed &a, int);
bool operator>(Fixed const &a, Fixed const &b);
bool operator<(Fixed const &a, Fixed const &b);
bool operator>=(Fixed const &a, Fixed const &b);
bool operator<=(Fixed const &a, Fixed const &b);
bool operator==(Fixed const &a, Fixed const &b);
bool operator!=(Fixed const &a, Fixed const &b);

#endif
