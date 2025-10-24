/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:31:15 by rbaticle          #+#    #+#             */
/*   Updated: 2025/10/24 14:37:17 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	b1 = Bureaucrat("Didier", 155);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat	b2 = Bureaucrat("Didier", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat	b3 = Bureaucrat("Michel", 5);

	b3.incrementGrade();
	b3.incrementGrade();
	b3.incrementGrade();
	b3.incrementGrade();
	try {
		b3.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b3 << std::endl;

	Bureaucrat	b4 = Bureaucrat("Jhon", 148);
	b4.decrementGrade();
	b4.decrementGrade();
	try {
	b4.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b4 << std::endl;

}
