/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:33:59 by rbaticle          #+#    #+#             */
/*   Updated: 2025/10/24 16:20:49 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form {
public:
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(void);
	Form(const Form &other);
	Form	&operator=(const Form &other);

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

	friend std::ostream	&operator<<(std::ostream &os, const Form &f);

	void	beSigned(const Bureaucrat &b);

	~Form(void);
private:
	const std::string	_name;
	bool				_isSigned;
	int					_gradeToSign;
	int					_gradeToExecute;
};

#endif
