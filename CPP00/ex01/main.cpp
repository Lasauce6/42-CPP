/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:20:35 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/04 18:00:04 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>

static void	add_contact(PhoneBook *book) {
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone;
	std::string	secret;

	std::cout << "Enter First Name :";
	std::getline(std::cin, first_name);
	std::cout << "Enter Last Name :";
	std::getline(std::cin, first_name);
	std::cout << "Enter nickname :";
	std::getline(std::cin, first_name);
	std::cout << "Enter phone number :";
	std::getline(std::cin, first_name);
	std::cout << "Enter darkest secret :";
	std::getline(std::cin, first_name);
	Contact contact = Contact(first_name, last_name, nickname, phone, secret);
	book->add(contact);
}

int	main(void) {
	PhoneBook	book = PhoneBook();
	std::string	input;

	while (1) {
		std::getline(std::cin, input);
		if (input.compare("EXIT") == 0)
			break ;
		if (input.compare("SEARCH") == 0)
			book.search();
		if (input.compare("ADD"))
			add_contact(&book);
	}
}
