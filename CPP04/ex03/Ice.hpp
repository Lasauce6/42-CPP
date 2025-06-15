/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:00:39 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/15 19:46:50 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice &other);
	Ice	&operator=(const Ice &other);

	AMateria*	clone(void) const;
	void		use(ICharacter& target);

	~Ice(void);
};

#endif
