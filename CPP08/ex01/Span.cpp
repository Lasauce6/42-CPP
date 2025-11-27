/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:34:35 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/27 17:56:45 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _vec(other._vec) {}

Span	&Span::operator=(const Span &other) {
	if (&other != this) {
		_N = other._N;
		_vec = other._vec;
	}
	return (*this);
} // TODO: test cpy with empty other

void	Span::addNumber(int nb) {
	if (_vec.size() >= _N)
		throw SpanFullException();
	_vec.push_back(nb);
}

const char	*Span::SpanFullException::what(void) const throw() {
	return ("Error: span is full");
}

unsigned int	Span::shortestSpan(void) {
	if (_vec.size() < 2)
		throw NotEnoughNumbersException();
}
