/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:48:22 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/03 12:33:47 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else {
		_gradeToSign = gradeToSign;
		_gradeToExecute = gradeToExecute;
	}
}

Form::Form(void) : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(const Form &other) : _name(other.getName()), _isSigned(other.isSigned()), 
	_gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()) {}

Form	&Form::operator=(const Form &other) {
	if (this != &other) {
		_gradeToExecute = other.getGradeToExecute();
		_gradeToSign = other.getGradeToSign();
		_isSigned = other.isSigned();
	}
	return (*this);
}

std::string	Form::getName(void) const {return (_name);}
int			Form::getGradeToSign(void) const {return (_gradeToSign);}
int			Form::getGradeToExecute(void) const {return (_gradeToExecute);}
bool		Form::isSigned(void) const {return (_isSigned);}

const char	*Form::GradeTooHighException::what(void) const throw() {
	return ("Error: the grade is too high");
}

const char	*Form::GradeTooLowException::what(void) const throw() {
	return ("Error: the grade is too low");
}

std::ostream	&operator<<(std::ostream &os, const Form &f) {
	std::cout << "Form : " << f.getName() << std::endl
		<< "Grade to sign : " << f.getGradeToSign() << std::endl
		<< "Grade to execute : " << f.getGradeToExecute() << std::endl
		<< "Signed : " << f.isSigned();
	return (os);
}

void	Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

Form::~Form(void) {}
