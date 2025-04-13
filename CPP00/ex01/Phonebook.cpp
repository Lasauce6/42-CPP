/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:45:06 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 14:10:51 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook(void) {
	this->last_in = 0;
	this->full = false;
}

PhoneBook::~PhoneBook() {
	return ;
}

int	PhoneBook::add(Contact contact) {
		if (this->last_in < 8) {
		this->contacts[this->last_in] = contact;
		this->last_in++;
	} else {
		this->contacts[0] = contact;
		this->last_in = 1;
		this->full = true;
	}
	return (0);
}

std::string	get_substr(std::string str) {
	std::string	res;
	int			padding = 10 - str.size(), pad = padding >> 1;

	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else if (pad > 0)
		return std::string(padding, ' ').insert(pad, str);
	return (str);
}

int	PhoneBook::search(void) {
	std::string	input;
	int			i = 0;
	int			end = this->full ? 8 : this->last_in;

	if (this->last_in == 0) {
		std::cout << "EMPTY PHONEBOOK" << std::endl;
		return (0);
	}
	std::cout << "____________________________________________" << std::endl;
	std::cout << "|  index  |first name| last name| nickname |" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	while (i < end) {
		std::cout << "|    " << i << "    |";
		std::cout << get_substr(this->contacts[i].get_first_name()) << "|";
		std::cout << get_substr(this->contacts[i].get_last_name()) << "|";
		std::cout << get_substr(this->contacts[i].get_nickname()) << "|" << std::endl;
		i++;
	}
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	std::cout << "Enter contact index : ";
	if (!std::getline(std::cin, input))
		return (1);
	if (input.length() == 1 && input.find_first_of("01234567") != std::string::npos)
		this->contacts[atoi(input.c_str())].show();
	return (0);
}
