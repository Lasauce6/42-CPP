/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:38:22 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/14 15:36:24 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(const Point &other) {
	this->x.setRawBits(other.x.getRawBits());
	this->y.setRawBits(other.y.getRawBits());
}

Point	&Point::operator=(const Point &other) {
	if (this != &other) {}
	return (*this);
}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {}

Fixed	Point::getX(void) const {
	return (x);
}

Fixed	Point::getY(void) const {
	return (y);
}

Point::~Point() {
	return ;
}
