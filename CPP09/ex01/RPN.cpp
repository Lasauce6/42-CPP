/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:57:06 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/05 19:04:24 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>

RPN::RPN(void) {}

RPN::RPN(const RPN &other) {
	_stack = other.getStack();
	_res = other.getResult();
}

RPN	&RPN::operator=(const RPN &other) {
	if (this != &other) {
		_stack = other.getStack();
		_res = other.getResult();
	}
	return (*this);
}

void	RPN::addElement(char nb) {
	if (std::isdigit(nb)) {

	} else {

	}
}
