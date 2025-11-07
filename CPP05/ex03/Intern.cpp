/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:37:05 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:41:59 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other) {
	(void) other;
}

Intern	&Intern::operator=(const Intern &other) {
	(void) other;
	return (*this);
}

static AForm	*makeRobotomy(const std::string target) {
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubbery(const std::string target) {
	return (new ShrubberyCreationForm(target));
}

static AForm	*makePresidential(const std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	std::string inputs[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm	*(*func[3])(const std::string) = {&makeRobotomy, &makeShrubbery, &makePresidential};


	for (int i = 0; i < 4; i++) {
		if (i == 3) {
			std::cerr << "Error: the requested form does not exist" << "\n";
			return (NULL);
		} else if (name == inputs[i])
			return (func[i](target));
	}
	return (NULL);
}

Intern::~Intern(void) {}
