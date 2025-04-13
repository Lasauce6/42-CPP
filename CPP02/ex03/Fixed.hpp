/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:23:54 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/11 13:53:02 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	
	Fixed(const int val);
	Fixed(const float val);

	float				toFloat(void) const;
	int					toInt(void) const;
	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	bool				operator>(const Fixed &other) const;
	bool				operator<(const Fixed &other) const;
	bool				operator>=(const Fixed &other) const;
	bool				operator<=(const Fixed &other) const;
	bool				operator==(const Fixed &other) const;
	bool				operator!=(const Fixed &other) const;

	Fixed				operator+(const Fixed &other) const;
	Fixed				operator-(const Fixed &other) const;
	Fixed				operator*(const Fixed &other) const;
	Fixed				operator/(const Fixed &other) const;

	Fixed				&operator++(void);
	Fixed				operator++(int);
	Fixed				&operator--(void);
	Fixed				operator--(int);

	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

	~Fixed(void);
private:
	int					value;
	static const int	nb_bits;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif
