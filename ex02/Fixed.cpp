/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:31:19 by nefimov           #+#    #+#             */
/*   Updated: 2025/10/24 12:49:58 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <cstdint>

Fixed::Fixed(void) : value(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int i_num) : value(i_num << fract_bits) {
	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float f_num)
  : value(static_cast<int>(roundf(f_num * (1 << fract_bits)))) {
	std::cout << "Float Constructor called" << std::endl;
}


Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy Constructor called" << std::endl;
	// this->value = other.getRawBits();
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy Assignment Operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->value = other.value;
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->value > other.value);
};
bool Fixed::operator<(const Fixed &other) const {
	return (this->value < other.value);
};
bool Fixed::operator>=(const Fixed &other) const {
	return (this->value >= other.value);
};
bool Fixed::operator<=(const Fixed &other) const {
	return (this->value <= other.value);
};
bool Fixed::operator==(const Fixed &other) const {
	return (this->value == other.value);
};
bool Fixed::operator!=(const Fixed &other) const {
	return (this->value != other.value);
};

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result = this->value + other.value;
	return (result);
};
Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result = this->value - other.value;
	return (result);
};
Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.value = static_cast<int64_t>(this->value) * other.value >> fract_bits;
    return result;
};
Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
    result.value = (static_cast<int64_t>(this->value) << fract_bits) / other.value;
    return result;
};

Fixed &Fixed::operator++(void) {
	this->value += 1;
	return (*this);
};
Fixed Fixed::operator++(int) {
	Fixed result(this->value);
	this->value += 1;
	return (result);
};
Fixed &Fixed::operator--(void) {
	this->value -= 1;
	return (*this);
};
Fixed Fixed::operator--(int) {
	Fixed result(this->value);
	this->value -= 1;
	return (result);
};

Fixed::~Fixed(void) {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(value) / (1 << fract_bits));
	
}

int Fixed::toInt(void) const {
	return (value >> fract_bits);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2) {
	if (num1 <= num2)
		return (num1);
	else
		return (num2);
}
const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2) {
	if (num1 <= num2)
		return (num1);
	else
		return (num2);
}
Fixed &Fixed::max(Fixed &num1, Fixed &num2) {
	if (num1 >= num2)
		return (num1);
	else
		return (num2);
}
const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2) {
	if (num1 >= num2)
		return (num1);
	else
		return (num2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}