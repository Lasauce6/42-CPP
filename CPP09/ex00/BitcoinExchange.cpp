/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:05:40 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/03 15:59:52 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::ofstream	file(filename);
	std::string	line;

	if (!file.is_open())
		throw OpenException();

	while (std::getline(file, line))
		check_line(line);

}
