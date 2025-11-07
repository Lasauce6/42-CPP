/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:06:02 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:35:26 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void) other;}
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other) {
	(void) other;
	return (*this);
}

static t_type	get_type(std::string str) {
	if (is_special(str))
		return (SPECIAL);
	else if (is_int(str))
		return (INT);
	else if (is_char(str))
		return (CHAR);
	else if (is_double(str))
		return (DOUBLE);
	else if (is_float(str))
		return (FLOAT);
	return (ERROR);
}

void	ScalarConverter::convert(std::string str) {
	t_type	type = get_type(str);

	switch (type) {
		case (CHAR):
			from_char(str);
			break;
		case (INT):
			from_int(str);
			break;
		case (FLOAT):
			from_float(str);
			break;
		case (DOUBLE):
			from_double(str);
			break;
		case (SPECIAL):
			special(str);
			break;
		case (ERROR):
			std::cerr << "error: wrong format\n";
	}
}

ScalarConverter::~ScalarConverter(void) {}
