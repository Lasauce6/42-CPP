/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:02:55 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/15 19:47:00 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	Cure(void);
	Cure(const Cure  &other);
	Cure	&operator=(const Cure &other);

	AMateria*	clone(void) const;
	void		use(ICharacter& target);

	~Cure(void);
};

#endif
