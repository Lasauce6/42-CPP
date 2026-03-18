/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:03:40 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/06 13:22:21 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>
#include <iostream>


int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error\n";
		return 1;
	}

	RPN	rpn;
	std::string	input = argv[1];
	input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());

	try {
		for (std::string::iterator it = input.begin(); it != input.end(); it++) {
			rpn.addElement(*it);
		}
		std::cout << rpn.getResult() << "\n";
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
		return 1;
	}
	return 0;
}
