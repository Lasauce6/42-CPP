/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:11:41 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 20:23:33 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
}

std::string	Weapon::getType(void) const {
	return (type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}

Weapon::~Weapon(void) {
	return ;
}
