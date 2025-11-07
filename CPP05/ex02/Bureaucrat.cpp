/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:57:02 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:39:08 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(other.getGrade()) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other.getGrade();
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const {return (_name);}
int	Bureaucrat::getGrade(void) const {return (_grade);}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("The grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("The grade is too low");
}

void	Bureaucrat::incrementGrade(void) {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		_grade++;
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b)
{
	std::cout << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

void	Bureaucrat::signForm(AForm &f) {
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << "\n";
	} catch (std::exception &e) {
		std::cerr << _name << " couldn't sign " << f.getName() << " because "
			<< e.what() << "\n";
	}
}

void	Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << "\n";
	} catch (std::exception &e) {
		std::cerr << _name << " couldn't execute " << form.getName() << " because "
			<< e.what() << "\n";
	}
}

Bureaucrat::~Bureaucrat(void) {}
