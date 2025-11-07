/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:50:37 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:39:49 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("Robotomy Request", 72, 45),
	_target(NULL) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("Robotomy Request", 72, 45),
	_target(target) {}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()),
	_target(other.getTarget()) {}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		_target = other.getTarget();
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

void	RobotomyRequestForm::_execution(void) const {
	int	r = rand() % 101;

	std::cout << "bzzzzrrrdrdrdrdddrdrr...drprapasrspsp..razdzpdzpdzrpzrpezezpz\n"
		<< "brbrbrbbrbrrbrbbrzzbzr.. prrrbrbrrbrzzzzbzbzbzzbzzzzz\n- ";
	if (r < 50)
		std::cout << _target << " has been robotomized successfully !\n";
	else
		std::cout << "Robotomy failed :(\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}
