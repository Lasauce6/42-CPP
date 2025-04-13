/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:34:13 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/11 14:09:52 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point {
public:
	Point(void);
	Point(const Point &other);
	Point &operator=(const Point &other);
	
	Point(const Fixed x, const Fixed y);
	
	Fixed	getX(void) const;
	Fixed	getY(void) const;

	~Point(void);
private:
	const Fixed	x;
	const Fixed	y;
};

#endif
