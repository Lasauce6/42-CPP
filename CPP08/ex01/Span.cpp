/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:34:35 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/26 14:43:18 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) {
	_N = other._N;
	_vec = std::vector<int>(other._vec);
}

Span	&Span::operator=(const Span &other) {
	if (&other != this) {
		_N = other._N;
		_vec = std::vector<int>(other._vec);
	}
	return (*this);
} // TODO: test cpy with empty other


