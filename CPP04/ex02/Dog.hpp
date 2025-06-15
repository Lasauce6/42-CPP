/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:52:27 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/05 13:11:41 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public AAnimal {
public:
	Dog(void);
	Dog(const Dog &other);
	Dog	&operator=(const Dog &other);

	void	makeSound(void) const;
	
	~Dog(void);
};

#endif
