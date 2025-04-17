/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:46:30 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/14 15:37:18 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	// Triangle ABC
	Point a = Point(Fixed(0), Fixed(0));
	Point b = Point(Fixed(10), Fixed(0));
	Point c = Point(Fixed(5), Fixed(10));

	// Point à l'intérieur
	Point p_inside = Point(Fixed(5), Fixed(5));
	std::cout << "Point inside: " << bsp(a, b, c, p_inside) << std::endl;

	// Point à l'extérieur
	Point p_outside = Point(Fixed(10), Fixed(10));
	std::cout << "Point outside: " << bsp(a, b, c, p_outside) << std::endl;

	// Point sur un bord
	Point p_on_edge = Point(Fixed(5), Fixed(0));
	std::cout << "Point on edge: " << bsp(a, b, c, p_on_edge) << std::endl;

	// Point sur un sommet
	Point p_on_vertex = Point(Fixed(0), Fixed(0));
	std::cout << "Point on vertex: " << bsp(a, b, c, p_on_vertex) << std::endl;

	return 0;
}

