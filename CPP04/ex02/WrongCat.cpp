/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:36:15 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/05 13:27:39 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) {
	std::cout << "WrongCat constructor called" << std::endl;
	type = "Cat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal() {
	this->type = other.type;
}

WrongCat	&WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}
