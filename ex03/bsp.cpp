/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:37:15 by nefimov           #+#    #+#             */
/*   Updated: 2025/12/11 16:45:58 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

// return 1 if point p is on the right side of vector ab,
// -1 - if on the left side and 0 - if it is on the vector
static int sign(Point const &p, Point const &a, Point const &b) {
	Fixed f_sign = (p.getX() - b.getX()) * (a.getY() - b.getY())
					- (a.getX() - b.getX()) * (p.getY() - b.getY());

	if (f_sign > 0) return (1);
	if (f_sign < 0) return (-1);
    return (0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	int s1 = sign(point, a, b);
	int s2 = sign(point, b, c);
	int s3 = sign(point, c, a);

	return (((s1 > 0) && (s2 > 0) && (s3 > 0))
			|| ((s1 < 0) && (s2 < 0) && (s3 < 0)));
}