/* ************************************************************************** */
/*         */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:05:40 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/05 11:52:55 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string &filename) {
	_file = new std::ifstream(filename.c_str());

	if (!_file->is_open())
		throw OpenException();
	fillExchange();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	_btc = other.getExchange();
	_file = other.getFile();
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		_btc = other.getExchange();
		_file = other.getFile();
	}
	return *this;
}

std::map<std::string, double>	BitcoinExchange::getExchange(void) const {
	return _btc;
}

std::ifstream	*BitcoinExchange::getFile(void) const {
	return _file;
}

void	BitcoinExchange::readLine(std::string line) {
	std::string	save = line;

	line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
	if (line.find('|') == std::string::npos) {
		std::cerr  << "Error: bad input => " << save << "\n";
		return;
	}

	std::string	date = line.substr(0, line.find('|'));
	if (!checkDate(date)) {
		std::cerr  << "Error: bad input => " << save << "\n";
		return;
	}

	double val = std::strtod(line.substr(line.find('|') + 1, line.size() - 1).c_str(), NULL);
	if (val < 0) {
		std::cerr << "Error: not a positive number.\n";
		return;
	}
	else if (val > 2147483647) {
		std::cerr << "Error: too large a number.\n";
		return;
	}

	std::map<std::string, double>::iterator	it;
	for (it = _btc.begin(); it != _btc.end(); it++) {
		if (it->first == date)
			break;
		else if (it->first > date) {
			it--;
			break;
		}
	}
	double	res = it->second * val;
	std::cout << date << " => " << val << " = " << res << "\n";
}

void	BitcoinExchange::fillExchange(void) {
	std::string	date;
	std::string	val;
	if (std::getline(*_file, date)) {
		while (_file->is_open() && std::getline(*_file, date, ',')) {
			if (!checkDate(date))
				throw InputDataException();
			std::getline(*_file, val);
			_btc[date] = std::strtod(val.c_str(), NULL);
		}
	}

}

bool	BitcoinExchange::checkDate(std::string date) {
	if (date.length() != 10)
		return false;
	for (size_t i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7) {
			if (date[i] != '-')
				return false;
		} else {
			if (!std::isdigit(date[i]))
				return false;
		}
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	else if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
			return false;
	else if (month == 2) {
		bool	leapYear = ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
		if (day > 28 + leapYear)
			return false;
	}
	return true;
}

const char	*BitcoinExchange::OpenException::what(void) const throw() {
	return ("Error: could not open file.");
}

const char	*BitcoinExchange::InputDataException::what(void) const throw() {
	return ("Error: csv input file error.");
}

BitcoinExchange::~BitcoinExchange(void) {
	delete _file;
}
