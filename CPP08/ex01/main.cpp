/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:21:59 by rbaticle          #+#    #+#             */
/*   Updated: 2026/02/28 16:19:34 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

int	main(void) {
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << "\n";
	std::cout << sp.longestSpan() << "\n";

	std::cout << "\n other tests \n";
	Span	sp2 = Span(100000);
	std::vector<int>	vec(100000);

	srand(time(0));
	std::generate(vec.begin(), vec.end(), std::rand);
	sp2.fillSpan(vec.begin(), vec.end());

	std::cout << sp2.shortestSpan() << "\n";
	std::cout << sp2.longestSpan() << "\n";
}
