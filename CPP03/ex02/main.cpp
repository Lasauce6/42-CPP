/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:36:19 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/22 13:10:44 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void	attack(ClapTrap aggresor, ClapTrap victim) {
	aggresor.attack(victim.getName());
	victim.takeDamage(aggresor.getAttackDmg());
}

int	main(void) {
	std::cout << "------EXO00-----" << std::endl << std::endl;

	ClapTrap	steve = ClapTrap("Steve");
	ClapTrap	roger = ClapTrap("Roger");
	ClapTrap	hugues = ClapTrap("Hugues");

	// On affiche les differents ClapTrap
	steve.showStatus();
	std::cout << std::endl;
	roger.showStatus();
	std::cout << std::endl;
	hugues.showStatus();
	std::cout << std::endl;
	std::cout << std::endl;

	// On ajoute 5 d'attaque a Hugues
	hugues.setAttackDmg(5);
	hugues.showStatus();
	std::cout << std::endl;

	hugues.attack(roger.getName());
	roger.takeDamage(hugues.getAttackDmg());
	std::cout << std::endl;
	roger.showStatus();
	std::cout << std::endl;
	hugues.attack(roger.getName());
	roger.takeDamage(hugues.getAttackDmg());
	std::cout << std::endl;

	// Test d'attaque d'un mec mort
	hugues.attack(roger.getName());
	roger.takeDamage(hugues.getAttackDmg());
	std::cout << std::endl;

	// Reparation d'un mec mort
	roger.beRepaired(5);
	std::cout << std::endl;

	// Test d'attaque par un mec mort
	roger.attack(hugues.getName());
	std::cout << std::endl;

	// Test d'attaque par un mec qui sait pas attquer
	steve.attack(hugues.getName());
	std::cout << std::endl;

	hugues.beRepaired(2);
	hugues.beRepaired(2);
	hugues.beRepaired(2);
	hugues.beRepaired(2);
	hugues.beRepaired(2);
	hugues.beRepaired(2);
	hugues.beRepaired(2);
	hugues.beRepaired(2);
	std::cout << std::endl;

	std::cout << "------EXO01-----" << std::endl << std::endl;
	ScavTrap	gontrand = ScavTrap("Gontrand");

	gontrand.showStatus();
	std::cout << std::endl;

	gontrand.guardGate();
	gontrand.attack(hugues.getName());
	hugues.takeDamage(gontrand.getAttackDmg());

	std::cout << std::endl;
	std::cout << "------EXO02-----" << std::endl << std::endl;

	FragTrap	bertrand = FragTrap("Bertrand");

	bertrand.showStatus();
	std::cout << std::endl;
	bertrand.highFivesGuys();
	std::cout << std::endl;
	bertrand.attack(hugues.getName());
	hugues.takeDamage(bertrand.getAttackDmg());
	bertrand.beRepaired(4);

	std::cout << std::endl;
	bertrand.showStatus();

	std::cout << std::endl;
}
