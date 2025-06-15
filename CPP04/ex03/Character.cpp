/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:50:04 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/15 19:50:09 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(const std::string name) : ICharacter(), name(name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &other) : ICharacter(), name(other.name) {
	for (int i = 0; i < 4; i++)
		inventory[i] = other.inventory[i];
}

Character	&Character::operator=(const Character &other) {
	if (this != &other) {
		this->name = other.name;
		for (int i = 0; i < 4; i++)
			inventory[i] = other.inventory[i];
	}
	return (*this);
}

const std::string	&Character::getName(void) const {
	return (this->name);
}

void	Character::equip(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <=3)
		inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3) {
		if (inventory[idx] == NULL)
			std::cout << "error: no material in inventory index " << idx << std::endl;
		else
			inventory[idx]->use(target);
	} else
		std::cout << "error: inventory out of bounds" << std::endl;
}

Character::~Character(void) {}
