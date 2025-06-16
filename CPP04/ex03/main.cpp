/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:24:36 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/16 12:56:38 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	IMateriaSource* s = new MateriaSource();
	s->learnMateria(new Ice());
	s->learnMateria(new Ice());
	s->learnMateria(new Cure());
	s->learnMateria(s->createMateria("cure"));
	ICharacter* you = new Character("me");
	tmp = s->createMateria("ice");
	you->equip(tmp);
	tmp = s->createMateria("cure");
	you->equip(tmp);
	ICharacter* didier = new Character("didier");
	you->use(0, *didier);
	you->use(1, *didier);
	you->use(3, *didier);
	you->use(6, *didier);
	delete you;
	delete didier;
	delete s;


	return 0;
}
