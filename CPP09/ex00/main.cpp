/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:02:06 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/05 12:01:19 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	std::string line;
	std::ifstream	file(argv[1]);
	if (!file.is_open() || !std::getline(file, line)) {
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	
	try {
		BitcoinExchange exchange("data.csv");
		while (std::getline(file, line))
			exchange.readLine(line);
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
		return 1;
	}
	return 0;
}
