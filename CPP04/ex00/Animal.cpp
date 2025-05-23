/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:21:56 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/28 15:25:25 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {
	std::cout << "Animal constructor called" << std::endl;
	type = "";
}

Animal::Animal(const Animal &other) {
	this->type = other.type;
}

Animal	&Animal::operator=(const Animal &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}
