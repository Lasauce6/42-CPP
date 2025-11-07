/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:50:37 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:39:59 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <ostream>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("Shrubbery Creation", 145, 137),
	_target(NULL) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("Shrubbery Creation", 145, 137),
	_target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()),
	_target(other.getTarget()) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		_target = other.getTarget();
	}
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void	ShrubberyCreationForm::_execution(void) const {
	std::ofstream file((_target + "_shrubbery").c_str());
	const std::string tree = "\n\
            &&& &&  & &&\n\
         && &\\/&\\|& ()|/ @, &&\n\
        &\\/(/&/&||/& /_/)_&/_&\n\
       &() &\\/&|()|/&\\/ '%\" & ()\n\
      &_\\_&&_\\ |& |&&/&__%_/_& &&\n\
    &&   && & &| &| /& & % ()& /&&\n\
     ()&_---()&\\&\\|&&-&&--%---()~\n\
         &&     \\|||\n\
                 |||\n\
                 |||\n\
                 |||\n\
           , -=-~  .-^- _";

	if (!file.is_open())
		std::cerr << "Error while opening the file\n";
	else {
		file << tree << std::endl;
		file.close();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}
