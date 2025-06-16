/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:27:16 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/16 12:51:21 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void) : IMateriaSource() {
	for (int i = 0; i < 4; i++)
		stock[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource() {
	for (int i = 0; i < 4; i++)
		stock[i] = other.stock[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++)
			stock[i] = other.stock[i];
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m) {
	int	i = 0;
	while (i < 4 && stock[i] != NULL)
		i++;
	if (i < 4)
		stock[i] = m;
	else
		std::cout << "error: stock full" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (stock[i]->getType() == type)
			return (stock[i]->clone());
	}
	return (NULL);
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++) {
		if (stock[i] != NULL)
			delete stock[i];
	}
}
