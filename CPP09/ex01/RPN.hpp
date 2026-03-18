/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:54:20 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/06 14:05:20 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <stack>

class RPN {
public:
	RPN(void);
	RPN(const RPN &other);
	RPN	&operator=(const RPN &other);

	void			addElement(char &nb);
	double			getResult(void) const;
	std::stack< double, std::list<double> >	getStack(void) const;

	class WrongElementException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	class DivisionByZeroException : public std::exception {
		virtual const char	*what(void) const throw();
	};


	~RPN(void);

private:
	void	doOperation(double x, double y, char op);
	void	div(double x, double y);

	std::stack< double, std::list<double> >	_stack;
	double			_res;
};
