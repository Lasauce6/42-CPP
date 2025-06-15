/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:21:56 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/05 13:07:26 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

AAnimal::AAnimal(void) {
	std::cout << "Animal constructor called" << std::endl;
	type = "";
	this->brain = new Brain();
}

AAnimal::AAnimal(const AAnimal &other) {
	this->type = other.type;
}

AAnimal	&AAnimal::operator=(const AAnimal &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

std::string	AAnimal::getType(void) const {
	return (type);
}

std::string AAnimal::getIdea(int index) const {
	return (brain->getIdea(index));
}

void	AAnimal::setIdea(int index, std::string idea) const {
	brain->setIdea(index, idea);
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal destructor called" << std::endl;
	delete brain;
}
