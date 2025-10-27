/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:37:15 by nefimov           #+#    #+#             */
/*   Updated: 2025/10/27 14:21:35 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

static int sign(Point const &p, Point const &a, Point const &b) {
	Fixed f_sign;
	
	Fixed pb;
	
	f_sign = (p.getX() - b.getX()) * (a.getY() - b.getY()) -
			 (a.getX() - b.getX()) * (p.getY() - b.getY());
	
	if (f_sign > 0)
		return (1);
	else if (f_sign < 0)
		return (-1);
		
    return (0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	int s1 = sign(point, a, b);
	int s2 = sign(point, b, c);
	int s3 = sign(point, c, a);
	
	bool all_positive = (s1 > 0) && (s2 > 0) && (s3 > 0);
	bool all_negative = (s1 < 0) && (s2 < 0) && (s3 < 0);
	
	if (all_positive || all_negative)
		return (true);
		
	return (false);
}