/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:18:32 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/06 12:28:00 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) {
	this->type = type;
}

AMateria::AMateria(const AMateria &other) {
	this->type = other.getType();
}

AMateria	&AMateria::operator=(const AMateria &other) {
	if (this != &other)
		(*this) = other;
	return (*this);
}

std::string const	&AMateria::getType() const {
	return (this->type);
}

void	AMateria::use(ICharacter &target) {
	(void) target;
	std::cout << "use: no materia" << std::endl;
}

AMateria::~AMateria(void) {}
