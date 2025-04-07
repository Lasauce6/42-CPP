/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 13:22:10 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/04 17:39:33 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook 
{
	public:
		PhoneBook(void);
		void	add(Contact contact);
		void	search();
		~PhoneBook(void);
	private:
		int		last_in;
		Contact	contacts[8];
		bool	full;
};
