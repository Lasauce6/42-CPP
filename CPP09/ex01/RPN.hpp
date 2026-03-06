/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:54:20 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/05 12:04:16 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

class RPN {
public:
	RPN(void);
	RPN(const RPN &other);
	RPN	&operator=(const RPN &other);

	void			addElement(char nb);
	double			getResult(void) const;
	std::stack<int>	getStack(void) const;

	class WrongElementException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	~RPN(void);

private:
	std::stack<int>	_stack;
	double			_res;
};
