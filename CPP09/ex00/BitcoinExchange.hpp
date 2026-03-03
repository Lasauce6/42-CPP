/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:04:47 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/03 15:19:39 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <set>

class BitcoinExchange {
public:
	BitcoinExchange(std::string filename);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange	&operator=(const BitcoinExchange &other);

	float	readLine(std::string line);

	class OpenException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	class BadInputException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	class WrongNumberException : public std::exception {
		virtual const char	*what(void) const throw();
	};

	~BitcoinExchange(void);

private:
	std::set<std::string, float>	_btc;
};
