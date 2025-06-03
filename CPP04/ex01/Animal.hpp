/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:18:12 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/03 17:21:02 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include "Brain.hpp"

class Animal {
public:
	Animal(void);
	Animal(const Animal &other);
	Animal	&operator=(const Animal &other);

	void	makeSound(void) const;
	std::string	getType(void) const;
	std::string	getIdea(int index) const;
	void		setIdea(int index, std::string idea) const;

	~Animal(void);
protected:
	std::string	type;
	Brain		*brain;
};

#endif
