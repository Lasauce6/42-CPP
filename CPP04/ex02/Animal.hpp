/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:18:12 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/05 13:17:05 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include "Brain.hpp"

class AAnimal {
public:
	AAnimal(void);
	AAnimal(const AAnimal &other);
	AAnimal	&operator=(const AAnimal &other);

	virtual void	makeSound(void) const = 0;
	std::string	getType(void) const;
	std::string	getIdea(int index) const;
	void		setIdea(int index, std::string idea) const;

	virtual ~AAnimal(void);
protected:
	std::string	type;
	Brain		*brain;
};

#endif
