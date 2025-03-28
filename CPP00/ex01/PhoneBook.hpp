/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:22:10 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/28 13:27:15 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#include "Contact.hpp"

class PhoneBook 
{
private:
	std::array<Contact, 8> contacts;
};
