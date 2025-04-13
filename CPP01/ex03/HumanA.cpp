/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:02:30 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 20:30:19 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon) {
	this->name = name;
}

HumanA::~HumanA(void) {
	return ;
}

void	HumanA::attack(void) {
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
