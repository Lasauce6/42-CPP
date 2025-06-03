/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:47:23 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/03 15:18:31 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name + "_clap_name") {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->name = name;
	this->hit_pt = 100;
	this->energy_pt = 50;
	this->attack_dmg = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.name + "_clap_name"){
	this->name = other.name;
	this->hit_pt = other.hit_pt;
	this->energy_pt = other.energy_pt;
	this->attack_dmg = other.attack_dmg;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap "<< name << " is now in GateKeeper mode" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}
