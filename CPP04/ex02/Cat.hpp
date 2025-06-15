/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:30:49 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/05 13:10:52 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public AAnimal {
public:
	Cat(void);
	Cat(const Cat &other);
	Cat	&operator=(const Cat &other);

	void	makeSound(void) const;

	~Cat(void);
};

#endif
