/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:33:59 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/03 12:03:45 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
public:
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(void);
	AForm(const AForm &other);
	AForm	&operator=(const AForm &other);

	std::string	getName(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExecute(void) const;
	bool		isSigned(void) const;

	class GradeTooHighException : public std::exception {
		virtual const char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char	*what(void) const throw();
	};
	class FormNotSignedException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	friend std::ostream	&operator<<(std::ostream &os, const AForm &f);

	void	beSigned(const Bureaucrat &b);
	void	execute(Bureaucrat const & executor) const;

	virtual ~AForm(void);
private:
	const std::string	_name;
	bool				_isSigned;
	int					_gradeToSign;
	int					_gradeToExecute;
	virtual void		_execution(void) const = 0;
};
