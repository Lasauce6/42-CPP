/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:46:39 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 11:26:32 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <ostream>
#include <iostream>

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone, std::string secret) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_nb = phone;
	this->secret = secret;
}

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string	Contact::get_first_name(void) {
	return (this->first_name);
}

std::string	Contact::get_last_name(void) {
	return (this->last_name);
}

std::string	Contact::get_nickname(void) {
	return (this->nickname);
}

void	Contact::show(void) {
	std::cout << "First name :\t" << this->first_name << std::endl;
	std::cout << "Last name :\t" << this->last_name << std::endl;
	std::cout << "Nickname :\t" << this->nickname << std::endl;
	std::cout << "Phone number :\t" << this->phone_nb << std::endl;
	std::cout << "Darkest secret :\t" << this->secret << std::endl;
}
