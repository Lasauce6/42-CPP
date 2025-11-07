/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:38:54 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:35:36 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cerr << "Usage: ./convert <literal>\n";
}
