/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:31:15 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/03 12:31:42 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << std::endl << "Try Bureaucrat with grade 155" << std::endl;
	try {
		Bureaucrat	b1 = Bureaucrat("Didier", 155);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Try Bureaucrat with grade 0" << std::endl;
	try {
		Bureaucrat	b2 = Bureaucrat("Didier", 0);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Try Bureaucrat with grade 5 then increment 6 times" << std::endl;
	Bureaucrat	b3 = Bureaucrat("Michel", 5);

	std::cout << b3 << std::endl;
	b3.incrementGrade();
	std::cout << b3 << std::endl;
	b3.incrementGrade();
	std::cout << b3 << std::endl;
	b3.incrementGrade();
	std::cout << b3 << std::endl;
	b3.incrementGrade();
	std::cout << b3 << std::endl;
	try {
		b3.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << b3 << std::endl;

	std::cout << std::endl << "Try Bureaucrat with grade 148 then decrement 3 times" << std::endl;
	Bureaucrat	b4 = Bureaucrat("Jhon", 148);
	std::cout << b4 << std::endl;
	b4.decrementGrade();
	std::cout << b4 << std::endl;
	b4.decrementGrade();
	std::cout << b4 << std::endl;
	try {
		b4.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << b4 << std::endl;
}
