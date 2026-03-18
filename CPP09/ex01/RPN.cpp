/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:57:06 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/06 14:16:35 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <cstdlib>

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

void	RPN::addElement(char &nb) {
	if (std::isdigit(nb)) {
		char	tmp[2];
		tmp[0] = nb;
		tmp[1] = '\0';
		double	val = std::strtod(tmp, NULL);
		_stack.push(val);
	} else if (nb == '*' || nb == '/' || nb == '+' || nb == '-') {
		if (_stack.size() < 2)
			throw WrongElementException();
		double	y = _stack.top();
		_stack.pop();
		double	x = _stack.top();
		_stack.pop();
		doOperation(x, y, nb);
		_res = _stack.top();
	} else 
		throw WrongElementException();
}

double	RPN::getResult(void) const {
	if (_stack.size() != 1)
		throw WrongElementException();
	return _res;
}

std::stack< double, std::list<double> >	RPN::getStack(void) const {
	return _stack;
}

const char	*RPN::WrongElementException::what(void) const throw() {
	return "Error";
}

const char	*RPN::DivisionByZeroException::what(void) const throw() {
	return "Error: division by zero";
}

void	RPN::doOperation(double x, double y, char op) {
	switch (op) {
		case '+':
			_stack.push(x + y);
			break;
		case '-':
			_stack.push(x - y);
			break;
		case '*':
			_stack.push(x * y);
			break;
		case '/':
			div(x, y);
			break;
		default:
			return;
	}
}

void	RPN::div(double x, double y) {
	if (y == 0)
		throw DivisionByZeroException();
	_stack.push(x / y);
}

RPN::~RPN(void) {}
