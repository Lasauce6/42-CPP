/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:37:18 by rbaticle          #+#    #+#             */
/*   Updated: 2025/10/24 16:22:40 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"


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

	void		signForm(Form f);

	~Bureaucrat(void);
private:
	const std::string	_name;
	int					_grade;
};

#endif
