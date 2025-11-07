/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:31:15 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:43:47 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>

int	main(void) {
	// AForm	test;
	AForm		*pres;
	AForm		*rob;
	AForm		*shrub;
	Bureaucrat	patron = Bureaucrat("Musk", 1);
	Bureaucrat	cadre = Bureaucrat("Michel", 50);
	Bureaucrat	sous_fifre = Bureaucrat("Employe", 150);
	Intern		non_paye = Intern();

	pres = non_paye.makeForm("presidential pardon", "Lab");
	rob = non_paye.makeForm("robotomy request", "Bender");
	shrub = non_paye.makeForm("shrubbery creation", "Home");

	if (pres == NULL || rob == NULL || shrub == NULL) {
		if (pres)
			delete pres;
		if (rob)
			delete rob;
		if (shrub)
			delete shrub;
		exit(1);
	}

	std::cout << "Bureaucrat grade 150 tries to sign forms" << "\n";
	sous_fifre.signForm(*pres);
	sous_fifre.signForm(*rob);
	sous_fifre.signForm(*shrub);


	std::cout << "\n" << "Bureaucrat grade 50 tries to sign forms" << "\n";
	cadre.signForm(*pres);
	cadre.signForm(*rob);
	cadre.signForm(*shrub);

	std::cout << "\n" << "Bureaucrat grade 1 tries to execute forms" << "\n";
	patron.executeForm(*pres);
	patron.executeForm(*rob);
	patron.executeForm(*shrub);
	std::cout << "Sign and execute PresidentialPardonForm" << "\n";
	patron.signForm(*pres);
	patron.executeForm(*pres);

	std::cout << "\n" << "Bureaucrat grade 150 tries to execute forms" << "\n";
	sous_fifre.executeForm(*pres);
	sous_fifre.executeForm(*rob);
	sous_fifre.executeForm(*shrub);

	delete pres;
	delete rob;
	delete shrub;
}
