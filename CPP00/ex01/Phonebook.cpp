/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:45:06 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/04 18:03:50 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>


PhoneBook::PhoneBook(void) {
	this->last_in = 0;
	this->full = false;
	for (int i = 0; i < 8; ++i) {
		this->contacts[i] = Contact();
	}
}

void	PhoneBook::add(Contact contact) {
	if (this->last_in < 8) {
		this->contacts[this->last_in] = contact;
		this->last_in++;
	} else
{
		this->contacts[0] = contact;
		this->last_in = 1;
		this->full = true;
	}
}

static std::string	get_str(std::string str) {
	std::string	res;

	if (str.length() > 10)
		res = str.substr(0, 9) + ".";
	else
		res = std::string(10 - str.length(), ' ') + str;
	return (str);
}

void	PhoneBook::search(void) {
	int			i = 0;
	std::string	input;

	if (this->last_in == 0) {
		std::cout << "EMPTY PHONEBOOK" << std::endl;
		return ;
	}
	std::cout << "____________________________________________" << std::endl;
	std::cout << "|  index  |first name| last name| nickname |" << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	int	end = this->full ? 8 : this->last_in;
	while (i < end) {
		std::cout << "|    " << i << "    |" << std::endl;
		std::cout << get_str(this->contacts[i].get_first_name()) << "|" << std::endl;
		std::cout << get_str(this->contacts[i].get_last_name()) << "|" << std::endl;
		std::cout << get_str(this->contacts[i].get_nickname()) << "|" << std::endl;
		i++;
	}
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	std::cout << "Enter contact index :";
	std::getline(std::cin, input);
	if (input.length() == 1 && input.find_first_not_of("01234567") != std::string::npos)
		this->contacts[std::atoi(input.c_str())].show();
}
