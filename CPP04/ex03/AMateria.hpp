/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:34:03 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/15 19:51:50 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria {
protected:
public:
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria	&operator=(const AMateria &other);

	std::string	const &getType() const; // Returns the materia type

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target) = 0;

	virtual ~AMateria(void);
protected:
	std::string	type;
};

#endif
