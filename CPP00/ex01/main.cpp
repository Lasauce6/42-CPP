/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:20:35 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 14:05:42 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>

static int	add_contact(PhoneBook *book) {
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone;
	std::string	secret;

	std::cout << "____________________________________________" << std::endl;
	std::cout << "|              Add a contact               |" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;

	std::cout << "Enter First Name : ";
	if (!std::getline(std::cin, first_name))
		return (1);
	std::cout << "Enter Last Name : ";
	if (!std::getline(std::cin, last_name))
		return (1);
	std::cout << "Enter nickname : ";
	if (!std::getline(std::cin, nickname))
		return (1);
	std::cout << "Enter phone number : ";
	if (!std::getline(std::cin, phone))
		return (1);
	std::cout << "Enter darkest secret : ";
	if (!std::getline(std::cin, secret))
		return (1);
	Contact contact = Contact(first_name, last_name, nickname, phone, secret);
	return (book->add(contact));
}

int	main(void) {
	PhoneBook	book = PhoneBook();
	std::string	input;

	std::cout << "____________________________________________" << std::endl;
	std::cout << "|               My PhoneBook               |" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	while (1) {
		std::cout << "Enter ADD, SEARCH or EXIT : ";
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl;
			break ;
		}
		if (input.compare("EXIT") == 0)
			break ;
		else if (input.compare("SEARCH") == 0) {
			if (book.search())
				std::cout << "ERROR !" << std::endl;
		}
		else if (input.compare("ADD") == 0) {
			if (add_contact(&book))
				std::cout << "ERROR !" << std::endl;
		}
		else
			std::cout << "Wrong value !" << std::endl;
	}
	std::cout << "BYE !" << std::endl;
}
