/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:22:35 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/05 13:29:43 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal constructor called" << std::endl;
	type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	this->type = other.type;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

void	WrongAnimal::makeSound(void) const {
	if (type == "Cat")
		std::cout << "BEEEEEEEEEEEEEEH !" << std::endl;
	else
		std::cout << "SKIBEDIBAP BEDIPOUP" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (type);
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}
