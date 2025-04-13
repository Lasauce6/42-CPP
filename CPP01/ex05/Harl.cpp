/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:10:49 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/08 12:28:31 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cassert>

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void	Harl::complain(std::string level) {
	void		(Harl::*complaints[4]) (void) = 
		{&Harl::debug, &Harl::infos, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (!level.compare(levels[i])) {
			(this->*complaints[i])();
			return ;
		}
	}
	std::cout << "No level matching " << level << std::endl;
}

void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger.";
	std::cout << " I really do!" << std::endl;
}

void	Harl::infos(void) {
	std::cout << "I cannot believe adding extra bacon costs more money.";
	std::cout << " You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!" << std::endl;
}


void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming for years, whereas you started working";
	std::cout << "here just last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}
