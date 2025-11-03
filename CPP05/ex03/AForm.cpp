/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:48:22 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/03 12:34:44 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else {
		_gradeToSign = gradeToSign;
		_gradeToExecute = gradeToExecute;
	}
}

AForm::AForm(void) : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const AForm &other) : _name(other.getName()), _isSigned(other.isSigned()), 
	_gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()) {}

AForm	&AForm::operator=(const AForm &other) {
	if (this != &other) {
		_gradeToExecute = other.getGradeToExecute();
		_gradeToSign = other.getGradeToSign();
		_isSigned = other.isSigned();
	}
	return (*this);
}

std::string	AForm::getName(void) const {return (_name);}
int			AForm::getGradeToSign(void) const {return (_gradeToSign);}
int			AForm::getGradeToExecute(void) const {return (_gradeToExecute);}
bool		AForm::isSigned(void) const {return (_isSigned);}

const char	*AForm::GradeTooHighException::what(void) const throw() {
	return ("Error: the grade is too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw() {
	return ("Error: the grade is too low");
}

const char	*AForm::FormNotSignedException::what(void) const throw() {
	return ("Error: the form is not signed");
}

std::ostream	&operator<<(std::ostream &os, const AForm &f) {
	std::cout << "Form : " << f.getName() << std::endl
		<< "Grade to sign : " << f.getGradeToSign() << std::endl
		<< "Grade to execute : " << f.getGradeToExecute() << std::endl
		<< "Signed : " << f.isSigned();
	return (os);
}

void	AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(const Bureaucrat &executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	else if (executor.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	else
		_execution();
}

AForm::~AForm(void) {}
