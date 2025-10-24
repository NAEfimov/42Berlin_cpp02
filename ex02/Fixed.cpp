/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:31:19 by nefimov           #+#    #+#             */
/*   Updated: 2025/10/24 11:39:15 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : value(0) {
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int i_num) : value(i_num << fract_bits) {
	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed(const float f_num) : value(static_cast<int>(roundf(f_num * (1 << fract_bits)))) {
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
bool Fixed::operator<(const Fixed &other) {
	return (this->value < other.value);
};
bool Fixed::operator>=(const Fixed &other) {
	return (this->value >= other.value);
};
bool Fixed::operator<=(const Fixed &other) {
	return (this->value <= other.value);
};
bool Fixed::operator==(const Fixed &other) {
	return (this->value == other.value);
};
bool Fixed::operator!=(const Fixed &other) {
	return (this->value != other.value);
};
/*
Fixed &Fixed::operator+(const Fixed &other) {
	
};
Fixed &Fixed::operator-(const Fixed &other) {
	
};
Fixed &Fixed::operator*(const Fixed &other) {
	
};
Fixed &Fixed::operator/(const Fixed &other) {
	
};

Fixed &Fixed::operator++(void) {
	
};
Fixed Fixed::operator++(int) {
	
};
Fixed &Fixed::operator--(void) {
	
};
Fixed Fixed::operator--(int) {
	
};
*/
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
}