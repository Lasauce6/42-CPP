/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:14:34 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/16 12:40:44 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	MateriaSource	&operator=(const MateriaSource &other);

	void		learnMateria(AMateria*);
	AMateria	*createMateria(std::string const & type);

	~MateriaSource(void);
private:
	AMateria	*stock[4];
};

#endif
