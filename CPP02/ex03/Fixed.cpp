/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:31:48 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/11 14:12:24 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>
#include <ostream>

const int	Fixed::nb_bits = 8;

Fixed::Fixed(void) {
	value = 0;
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed	&Fixed::operator =(const Fixed &other) {
	if (this != &other)
		value = other.getRawBits();
	return (*this);
}

Fixed::Fixed(const int val) {
	value = val << nb_bits;
}

Fixed::Fixed(const float val) {
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

bool	Fixed::operator>(const Fixed &other) const {
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed &other) const {
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed &other) const {
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (this->toFloat() != other.toFloat());
}

Fixed	Fixed::operator+(const Fixed &other) const {
	return (this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const {
	return (this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const {
	return (this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const {
	if (other.value == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed();
	}
	Fixed	res;
	res.value = (value << nb_bits) / other.value;
	return (res);
}

Fixed	&Fixed::operator++(void) {
	value++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	value++;
	return (tmp);
}

Fixed	&Fixed::operator--(void) {
	value++;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}

Fixed::~Fixed(void) {
}

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

