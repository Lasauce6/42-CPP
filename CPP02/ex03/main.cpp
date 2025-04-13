/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:46:30 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/11 14:27:38 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point	a(1, 5);
	Point	b(3, 4);
	Point	c(4, 0);
	Point	p(3, 3);
	Point	q(2, 3.5f);
	Point	s(2, 3);

	std::cout << "p in triangle : " << bsp(p, a, b, c) << std::endl;
	std::cout << "q in triangle : " << bsp(q, a, b, c) << std::endl;
	std::cout << "s in triangle : " << bsp(s, a, b, c) << std::endl;
	return (0);
}

