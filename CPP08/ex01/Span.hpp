/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:20:46 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/26 14:13:02 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <vector>

class Span {
public:
	Span(void);
	Span(unsigned int N);
	Span(const Span &other);
	Span	&operator=(const Span &other);

	void	addNumber(int nb);

	class OutOfBoundsException : public std::exception {
		const char	*what(void) const throw();
	};

	unsigned int	shortestSpan(void);
	unsigned int	longestSpan(void);

	class EmptySpanException : public std::exception {
		const char	*what(void) const throw();
	};

	~Span(void);
private:
	std::vector<int>	_vec;
	unsigned int		_N;
};
