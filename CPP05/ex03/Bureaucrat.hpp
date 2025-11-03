/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:37:18 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/03 12:02:37 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

class Bureaucrat {
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat	&operator=(const Bureaucrat &other);

	std::string getName(void) const;
	int			getGrade(void) const;

	class GradeTooHighException : public std::exception {
		virtual const char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	void		incrementGrade(void);
	void		decrementGrade(void);
	friend std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b);

	void		signForm(AForm &f);
	void		executeForm(AForm const & form);

	~Bureaucrat(void);
private:
	const std::string	_name;
	int					_grade;
};
