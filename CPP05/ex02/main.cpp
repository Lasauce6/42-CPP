/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:31:15 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:40:45 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void) {
	// AForm	test;
	PresidentialPardonForm	pres = PresidentialPardonForm("Lab");
	RobotomyRequestForm		rob = RobotomyRequestForm("Fence");
	ShrubberyCreationForm	shrub = ShrubberyCreationForm("Home");
	Bureaucrat				patron = Bureaucrat("Musk", 1);
	Bureaucrat				cadre = Bureaucrat("Michel", 50);
	Bureaucrat				sous_fifre = Bureaucrat("Employe", 150);

	std::cout << "Bureaucrat grade 150 tries to sign forms\n";
	sous_fifre.signForm(pres);
	sous_fifre.signForm(rob);
	sous_fifre.signForm(shrub);


	std::cout << "\n" << "Bureaucrat grade 50 tries to sign forms\n";
	cadre.signForm(pres);
	cadre.signForm(rob);
	cadre.signForm(shrub);

	std::cout << "\n" << "Bureaucrat grade 1 tries to execute forms\n";
	patron.executeForm(pres);
	patron.executeForm(rob);
	patron.executeForm(shrub);
	std::cout << "Sign and execute PresidentialPardonForm\n";
	patron.signForm(pres);
	patron.executeForm(pres);

	std::cout << "\n" << "Bureaucrat grade 150 tries to execute forms\n";
	sous_fifre.executeForm(pres);
	sous_fifre.executeForm(rob);
	sous_fifre.executeForm(shrub);

}
