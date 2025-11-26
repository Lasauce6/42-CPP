/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:21:30 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/26 13:19:21 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <vector>
#include <iostream>

int	main(void) {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);
	vec.push_back(10);


	std::cout << *(easyfind(vec, 6)) << "\n";

	std::deque<int> d;
	d.push_back('a');
	d.push_back('b');
	d.push_back('c');
	d.push_back('d');
	d.push_back('e');
	d.push_back('f');
	d.push_back('g');
	d.push_back('h');
	d.push_back('i');
	d.push_back('j');

	std::cout << static_cast<char>(*(easyfind(d, 'a'))) << "\n";
}
