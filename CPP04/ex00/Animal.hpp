/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:18:12 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/03 15:32:52 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {
public:
	Animal(void);
	Animal(const Animal &other);
	Animal	&operator=(const Animal &other);

	void	makeSound(void) const;
	std::string	getType(void) const;

	~Animal(void);
protected:
	std::string	type;
};

#endif
