/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:23:37 by nefimov           #+#    #+#             */
/*   Updated: 2025/12/12 15:55:07 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors and Destructor
Point::Point(void) : x(0), y(0) {}

Point::Point(const float fx, const float fy) : x(fx), y(fy) {}

Point::Point(const int ix, const int iy) : x(ix), y(iy) {}

Point::Point(Point &other) {
	x = other.x;
	y = other.y;
}

Point::~Point(void) {}

// Operators
Point &Point::operator=(Point &other) {
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

// Getters and Setters
Fixed Point::getX(void) const {
	return (this->x);
}

Fixed Point::getY(void) const {
	return (this->y);
}

void Point::setX(const Fixed &fx) {
	x = fx;
}

void Point::setY(const Fixed &fy) {
	y = fy;
}

void Point::setXY(const Fixed &fx, const Fixed &fy) {
	x = fx;
	y = fy;
}

// Stream operator
std::ostream &operator<<(std::ostream &out, const Point &point) {
	out << "(" << point.getX() << ", " << point.getY() << ")";
	return (out);
}