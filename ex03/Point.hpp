/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:22:12 by nefimov           #+#    #+#             */
/*   Updated: 2025/10/27 13:35:42 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
  public:
	Point(void);
	Point(const float fx, const float fy);
	Point(const int ix, const int iy);
	Point(Point &other);
	~Point(void);
	
	Point &operator=(Point &other);
	
	Fixed getX(void) const;
	Fixed getY(void) const;
	void setX(const Fixed &x);
	void setY(const Fixed &y);
	void setXY(const Fixed &x, const Fixed &y);
	
  private:
	Fixed x;
	Fixed y;
};

std::ostream &operator<<(std::ostream &out, const Point &point);

#endif  // POINT_HPP