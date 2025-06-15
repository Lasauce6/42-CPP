/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:55:17 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/05 13:18:32 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void) {
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other) : AAnimal() {
	this->type = other.type;
}

Dog	&Dog::operator=(const Dog &other) {
	if (this != &other) 
		*this = other;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "BARK !" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}
