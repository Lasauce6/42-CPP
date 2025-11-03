/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:50:37 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/03 12:42:39 by rbaticle         ###   ########.fr       */
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

	std::cout << "bzzzzrrrdrdrdrdddrdrr...drprapasrspsp..razdzpdzpdzrpzrpezezpz" << std::endl
		<< "brbrbrbbrbrrbrbbrzzbzr.. prrrbrbrrbrzzzzbzbzbzzbzzzzz" << std::endl << "- ";
	if (r < 50)
		std::cout << _target << " has been robotomized successfully !" << std::endl;
	else
		std::cout << "Robotomy failed :(" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}
