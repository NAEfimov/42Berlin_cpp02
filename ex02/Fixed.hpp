/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:31:17 by nefimov           #+#    #+#             */
/*   Updated: 2025/10/24 14:01:32 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const int i_num);
	Fixed(const float f_num);
	Fixed(const Fixed &other);
	~Fixed(void);
	Fixed &operator=(const Fixed &other);
	// TODO
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);
	// END TODO
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	// TODO
	static Fixed &min(Fixed &num1, Fixed &num2);
	static Fixed &max(Fixed &num1, Fixed &num2);
	static const Fixed &min(const Fixed &num1, const Fixed &num2);
	static const Fixed &max(const Fixed &num1, const Fixed &num2);
	// END TODO

	
private:
	int value;
	static const int fract_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP