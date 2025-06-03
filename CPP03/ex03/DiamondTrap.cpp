/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:43:14 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/03 15:17:04 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name){
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->hit_pt = 100;
	this->energy_pt = 50;
	this->attack_dmg = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.ClapTrap::getName()), ScavTrap(other), FragTrap(other), name(other.name) {
	this->hit_pt = other.hit_pt;
	this->energy_pt = other.energy_pt;
	this->attack_dmg = other.attack_dmg;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) 
		*this = other;
	return (*this);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "Hi i'm " << this->name << " my ClapTrap name is "
		<< ClapTrap::getName() << std::endl;
}

void	DiamondTrap::attack(std::string _name) {
	ScavTrap::attack(_name);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called" << std::endl;
}
