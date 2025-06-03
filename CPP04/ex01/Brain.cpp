/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:17:26 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/03 16:55:34 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = "white noise";
	}
}

Brain::Brain(const Brain &other) {
	for (int i = 0; i < 100; i++) {
		this->ideas[i] = other.ideas[i];
	}
}

Brain	&Brain::operator=(const Brain &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

void	Brain::setIdea(int index, std::string idea) {
	this->ideas[index] = idea;
}

std::string	Brain::getIdea(int index) {
	return (this->ideas[index]);
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}
