/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:47:41 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/22 12:55:43 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called" << std::endl;
	this->name = name;
	this->hit_pt = 100;
	this->energy_pt = 100;
	this->attack_dmg = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other.name) {
	this->name = other.name;
	this->hit_pt = other.hit_pt;
	this->energy_pt = other.energy_pt;
	this->attack_dmg = other.attack_dmg;
}

FragTrap	&FragTrap::operator=(const FragTrap &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "Give me five !" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}
