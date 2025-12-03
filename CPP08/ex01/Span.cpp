/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:34:35 by rbaticle          #+#    #+#             */
/*   Updated: 2025/12/03 16:24:32 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(void) : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _vec(other._vec),  _N(other._N) {}

Span	&Span::operator=(const Span &other) {
	if (&other != this) {
		_N = other._N;
		_vec = other._vec;
	}
	return (*this);
}

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

	std::vector<int>	sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	int	shortest = sorted[1] - sorted[0];
	shortest = shortest < 0 ? -shortest : shortest;

	int	tmp;
	for (int i = 1; i + 1 < static_cast<int>(sorted.size()); i++) {
		tmp = sorted[i + 1] - sorted[i];
		tmp = tmp < 0 ? -tmp : tmp;
		if (tmp < shortest)
			shortest = tmp;
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void) {
	if (_vec.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int>	sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	int	longest = sorted[sorted.size() - 1] - sorted[0];
	return (longest < 0 ? -longest : longest);
}

const char	*Span::NotEnoughNumbersException::what(void) const throw() {
	return ("Error: the span does not have enought numbers");
}

void	Span::fillSpan(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
// TODO: todo
}


Span::~Span(void) {}
