/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:05:40 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/03 15:21:16 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange(std::string filename) {
	std::ofstream	file(filename);
	std::string	line;

	while (std::getline(file, line))
		check_line(line);

}
