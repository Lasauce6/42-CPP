/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:31:15 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/07 14:38:21 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {

	std::cout << "#### EX00 ####\n";

	std::cout << "\n" << "Try Bureaucrat with grade 155\n";
	try {
		Bureaucrat	b1 = Bureaucrat("Didier", 155);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n" << "Try Bureaucrat with grade 0\n";
	try {
		Bureaucrat	b2 = Bureaucrat("Didier", 0);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "\n" << "Try Bureaucrat with grade 5 then increment 6 times\n";
	Bureaucrat	b3 = Bureaucrat("Michel", 5);

	std::cout << b3 << "\n";
	b3.incrementGrade();
	std::cout << b3 << "\n";
	b3.incrementGrade();
	std::cout << b3 << "\n";
	b3.incrementGrade();
	std::cout << b3 << "\n";
	b3.incrementGrade();
	std::cout << b3 << "\n";
	try {
		b3.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << b3 << "\n";

	std::cout << "\n" << "Try Bureaucrat with grade 148 then decrement 3 times\n";
	Bureaucrat	b4 = Bureaucrat("Jhon", 148);
	std::cout << b4 << "\n";
	b4.decrementGrade();
	std::cout << b4 << "\n";
	b4.decrementGrade();
	std::cout << b4 << "\n";
	try {
		b4.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << b4 << "\n" << std::endl;

	std::cout << "#### EX01 ####\n";


	std::cout << "\n" << "Try Form with gradeToExecute 200\n";
	try {
		Form f1 = Form("Form", 15, 200);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n" << "Try Form with gradeToSign 0\n";
	try {
		Form f2 = Form("Form", 0, 20);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}


	std::cout << "\n" << "Bureaucrat 150 tries to sign Form gradeToSign 20\n";
	Form f3 = Form("Form", 20, 20);
	std::cout << f3 << "\n";
	try {
		b4.signForm(f3);
	} catch (std::exception &e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n" << "Bureaucrat 1 tries to sign Form gradeToSign 20\n";
	b3.signForm(f3);
}
