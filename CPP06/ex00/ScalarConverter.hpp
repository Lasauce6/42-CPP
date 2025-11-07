/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:57:52 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/06 13:30:10 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter {
public:
	static void	convert(std::string str);
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter	&operator=(const ScalarConverter &other);

	~ScalarConverter(void);
};

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	ERROR
}	t_type;

int		is_special(std::string str);
int		is_char(std::string str);
int		is_int(std::string str);
int		is_double(std::string str);
int		is_float(std::string str);
void	from_char(std::string str);
void	from_int(std::string str);
void	from_float(std::string str);
void	from_double(std::string str);
void	special(std::string str);
