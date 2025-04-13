/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:31:48 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/11 11:46:29 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

const int	Fixed::nb_bits = 8;

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &	Fixed::operator =(const Fixed &other)
{
	std::cout << "Copy assignement operator called" << std::endl;

	if (this != &other)
		value = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	value = val << nb_bits;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf((1 << nb_bits) * val);
}

float	Fixed::toFloat(void) const {
	return (value / float(1 << nb_bits));
}

int	Fixed::toInt(void) const {
	return (value >> nb_bits);
}

int	Fixed::getRawBits(void) const {
	return (value);
}

void	Fixed::setRawBits(const int raw) {
	value = raw;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}
