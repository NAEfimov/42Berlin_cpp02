/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:31:19 by nefimov           #+#    #+#             */
/*   Updated: 2025/12/12 16:01:13 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// #include <iostream>
#include <cmath>

// Constructors
Fixed::Fixed(void) : value(0) {
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int i_num) : value(i_num << fract_bits) {
	// std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float f_num)
: value(static_cast<int>(roundf(f_num * (1 << fract_bits)))) {
	// std::cout << "Float Constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}

// Destructor
Fixed::~Fixed(void) {
	// std::cout << "Destructor called\n";
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy Assignment Operator called" << std::endl;
	if (this != &other)
		this->value = other.value;
	return (*this);
}

// Comparison operators
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

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.value = this->value + other.value;
	return (result);
};

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.value = this->value - other.value;
	return (result);
};

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.value = static_cast<long long>(this->value) * other.value >> fract_bits;
    return result;
};

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
    result.value = (static_cast<long long>(this->value) << fract_bits) / other.value;
    return result;
};

// Increment/Decrement operators
Fixed &Fixed::operator++(void) {
	this->value += 1;
	return (*this);
};
Fixed Fixed::operator++(int) {
	Fixed result = *this;
	this->value += 1;
	return (result);
};
Fixed &Fixed::operator--(void) {
	this->value -= 1;
	return (*this);
};
Fixed Fixed::operator--(int) {
	Fixed result = *this;
	this->value -= 1;
	return (result);
};

// Getters and setters
int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

// Conversion functions
float Fixed::toFloat(void) const {
	return (static_cast<float>(value) / (1 << fract_bits));
	
}

// Static member functions
int Fixed::toInt(void) const {
	return (value >> fract_bits);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2) {
	return ((num1 <= num2) ? num1 : num2);
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2) {
	return ((num1 <= num2) ? num1 : num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2) {
	return ((num1 >= num2) ? num1 : num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2) {
	return ((num1 >= num2) ? num1 : num2);
}

// Stream operator (non-member function)
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}