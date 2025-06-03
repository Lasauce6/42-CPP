/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:42:35 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/03 15:17:46 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hit_pt = 10;
	this->energy_pt = 10;
	this->attack_dmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		this->name = other.name;
		this->hit_pt = other.hit_pt;
		this->energy_pt = other.energy_pt;
		this->attack_dmg = other.energy_pt;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->hit_pt == 0) {
		std::cout << this->name << " is dead" << std::endl;
		return ;
	}
	if (this->energy_pt == 0) {
		std::cout << this->name << " has no more energy points" << std::endl;
		return ;
	}
	this->energy_pt--;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing "
		<< this->attack_dmg << " points of damage !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= this->hit_pt) {
		hit_pt = 0;
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
	} else {
		this->hit_pt -= amount;
		std::cout << "ClapTrap " << this->name << " took " << amount
			<< " points of damages" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (hit_pt == 0) {
		std::cout << name << " is dead" << std::endl;
		return ;
	}
	if (energy_pt == 0) {
		std::cout << name << " has no more energy points" << std::endl;
		return ;
	}
	energy_pt--;
	hit_pt += amount;
	std::cout << "ClapTrap " << name << " repairs itselfs" << std::endl;
}

void	ClapTrap::showStatus(void) {
	std::cout << "Name :\t\t" << this->name << std::endl
		<< "Hit points :\t" << this->hit_pt << std::endl
		<< "Energy points :\t" << this->energy_pt << std::endl
		<< "Attack damage :\t" << this->attack_dmg << std::endl;
}

void	ClapTrap::setAttackDmg(unsigned int amount) {
	this->attack_dmg = amount;
}

std::string	ClapTrap::getName(void) const {
	return (this->name);
}

unsigned int	ClapTrap::getAttackDmg(void) {
	return (this->attack_dmg);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor callled" << std::endl;
}
