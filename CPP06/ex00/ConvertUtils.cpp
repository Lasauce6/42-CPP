/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertUtils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:01:05 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/12 11:41:38 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <iostream>
#include <sstream>
#include <stdlib.h>

int	is_special(std::string str) {
	return (str == "inf" || str == "-inf" || str == "nan"
		|| str == "inff" || str == "inff" || str == "nanf");
}

int	is_char(std::string str) {
	return (str.length() == 1);
}

int	is_int(std::string str) {
	int	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	is_double(std::string str) {
	int	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (str[i] && str[i] == '.')
		i++;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (str[i])
		return (0);
	return (1);
}

int	is_float(std::string str) {
	int	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (str[i] && str[i] == '.')
		i++;
	while (str[i] && std::isdigit(str[i]))
		i++;
	if (str[i] && str[i] == 'f')
		i++;
	if (str[i])
		return (0);
	return (1);
}

void	from_char(std::string str) {
	std::cout << "char: ";
	if (str[0] >= 33 && str[0] <= 126)
		std::cout << "'" << str[0] << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl
		<< "float: " << static_cast<float>(str[0]) << ".0f\n"
		<< "double: " << static_cast<double>(str[0]) << ".0\n";
}

void	from_int(std::string str) {
	std::stringstream	strs(str);
	double				val;
	strs >> val;

	std::cout << "char: ";
	if (val >= 33 && val <= 126)
		std::cout  << "'" << static_cast<char>(val) << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: ";
	if (val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(val) << "\n";
	if (val >= 1e6)
		std::cout << "float: " << static_cast<float>(val) << "f\n"
			<< "double: " << val << "\n";
	else
		std::cout << "float: " << static_cast<float>(val) << ".0f\n"
			<< "double: " << val << ".0\n";
}

void	from_float(std::string str) {
	std::stringstream	strs(str);
	float				val;
	strs >> val;

	std::cout << "char: ";
	if (val >= 33 && val <= 126)
		std::cout << "'" << static_cast<char>(val) << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: ";
	if (val > static_cast<float>(INT_MAX) || val < static_cast<float>(INT_MIN))
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(val) << "\n";
	if (val - static_cast<int>(val) || val >= 1e6)
		std::cout << "float: " << val << "f\n"
			<< "double: " << static_cast<double>(val) << "\n";
	else
		std::cout << "float: " << val << ".0f\n"
			<< "double: " << static_cast<double>(val) << ".0\n";
}

void	from_double(std::string str) {
	std::stringstream	strs(str);
	double				val;
	strs >> val;

	std::cout << "char: ";
	if (val >= 33 && val <= 126)
		std::cout << "'" << static_cast<char>(val) << "'\n";
	else
		std::cout << "Non displayable\n";
	std::cout << "int: " ;
	if (val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))
		std::cout << "impossible\n";
	else
		std::cout<< static_cast<int>(val) << "\n";
	if (val - static_cast<int>(val) || val >= 1e6)
		std::cout << "float: " << static_cast<float>(val) << "f\n"
			<< "double: " << val << "\n";
	else
		std::cout << "float: " << static_cast<float>(val) << ".0f\n"
			<< "double: " << val << ".0\n";
}

void	special(std::string str) {
	std::cout << "char: impossible\n"
		<< "int: impossible\n";
	if (str == "inf" || str == "inff")
		std::cout << "float: inff\n"
			<< "double: inf\n";
	if (str == "-inf" || str == "-inff")
		std::cout << "float: -inff\n"
			<< "double: -inf\n";
	if (str == "nan" || str == "nanf")
		std::cout << "float: nanf\n"
			<< "double: nan\n";
}
