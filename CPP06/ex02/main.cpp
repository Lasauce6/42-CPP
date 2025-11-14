/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:38:54 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/14 16:30:09 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {
	std::srand(time(0));
	int		r = std::rand() % 3;
	Base	*res;

	switch (r) {
		case 0:
			res = new A();
			break;
		case 1:
			res = new B();
			break;
		case 2:
			res = new C();
	}

	return (res);
}

void	identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Class is of the type A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Class is of the type B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Class is of the type C\n";
	else
		std::cout << "unknown type\n";
}

void	identify(Base &p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "Class is of the type A\n";
	} catch (std::exception &e) {
		try  {
			(void) dynamic_cast<B&>(p);
			std::cout << "Class is of the type B\n";
		} catch (std::exception &e1) {
			try {
				(void) dynamic_cast<C&>(p);
				std::cout << "Class is of the type C\n";
			} catch (std::exception &e2){
				std::cout << "unknown type\n";
			}
		}
	}
}

int	main(void) {
	Base	*test = generate();

	identify(test);
	identify(*test);
	test->showType();

	delete test;
}
