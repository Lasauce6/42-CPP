/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:21:56 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/03 17:21:13 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) {
	std::cout << "Animal constructor called" << std::endl;
	type = "";
	this->brain = new Brain();
}

Animal::Animal(const Animal &other) {
	this->type = other.type;
}

Animal	&Animal::operator=(const Animal &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

void	Animal::makeSound(void) const {
	if (type == "Dog")
		std::cout << "BARK !" << std::endl;
	else if (type == "Cat")
		std::cout << "MEW !" << std::endl;
	else
		std::cout << "RANDOM NOISE" << std::endl;
}

std::string	Animal::getType(void) const {
	return (type);
}

std::string Animal::getIdea(int index) const {
	return (brain->getIdea(index));
}

void	Animal::setIdea(int index, std::string idea) const {
	brain->setIdea(index, idea);
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
	delete brain;
}
