/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:31:23 by nefimov           #+#    #+#             */
/*   Updated: 2025/10/27 14:41:55 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	Point a(-1, -1);
	Point b(0.f, 5.f);
	Point c(5.f, 0.f);
	Point point;

	std::cout << "triangle: " << a << " " << b << " " << c << std::endl;

	// Positive tests
	std::cout << std::endl << "<<< Positive tests >>>" << std::endl;
	
	point.setXY(Fixed(1.f), Fixed(1.f));
	std::cout << point << ": " << bsp(a, b, c, point) << std::endl;
	point.setXY(Fixed(0), Fixed(0));
	std::cout << point << ": " << bsp(a, b, c, point) << std::endl;
	point.setXY(Fixed(0), Fixed(4));
	std::cout << point << ": " << bsp(a, b, c, point) << std::endl;
	point.setXY(Fixed(-0.5f), Fixed(-0.5f));
	std::cout << point << ": " << bsp(a, b, c, point) << std::endl;
	point.setXY(Fixed(3), Fixed(1.99f));
	std::cout << point << ": " << bsp(a, b, c, point) << std::endl;

	// Negative tests
	std::cout << std::endl << "<<< Negative tests >>>" << std::endl;
	
	point.setXY(Fixed(3), Fixed(2));
	std::cout << point << ": " << bsp(a, b, c, point) << std::endl;
	point.setXY(Fixed(-1.2f), Fixed(2.f));
	std::cout << point << ": " << bsp(a, b, c, point) << std::endl;
	point.setXY(Fixed(3.1f), Fixed(3.5f));
	std::cout << point << ": " << bsp(a, b, c, point) << std::endl;
	point.setXY(Fixed(3.f), Fixed(-0.5f));
	std::cout << point << ": " << bsp(a, b, c, point) << std::endl;
	
	return (0);
}