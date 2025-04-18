/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:22:10 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 12:00:35 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook 
{
	public:
		PhoneBook(void);
		int		add(Contact contact);
		int		search(void);
		~PhoneBook(void);
	private:
		int		last_in;
		Contact	contacts[8];
		bool	full;
};
