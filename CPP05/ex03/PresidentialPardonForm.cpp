/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:50:37 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:42:09 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Presidential Pardon", 25, 5),
	_target(NULL) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("Presidential Pardon", 25, 5),
	_target(target) {}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()),
	_target(other.getTarget()) {}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		_target = other.getTarget();
	}
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void	PresidentialPardonForm::_execution(void) const {
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}
