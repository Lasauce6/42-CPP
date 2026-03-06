/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:04:47 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/05 11:52:05 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <map>
#include <fstream>

class BitcoinExchange {
public:
	BitcoinExchange(const std::string &filename);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange	&operator=(const BitcoinExchange &other);

	std::map<std::string, double>	getExchange(void) const;
	std::ifstream					*getFile(void) const;

	void	readLine(std::string line);

	class OpenException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	class InputDataException : public std::exception {
		virtual const char	*what(void) const throw();
	};


	~BitcoinExchange(void);

private:
	void	fillExchange(void);
	bool	checkDate(std::string date);

	std::map<std::string, double>	_btc;
	std::ifstream					*_file;
};
