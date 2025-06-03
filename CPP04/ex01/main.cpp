/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:24:34 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/03 17:29:21 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>
#define SIZE 10

int main()
{
	std::cout << "-----------EX00-----------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Animal* k = new WrongCat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	k->makeSound();

	delete meta;
	delete j;
	delete i;
	delete k;

	std::cout << std::endl << std::endl << "-----------EX01-----------" << std::endl << std::endl;
	const Animal	*u = new Cat();
	u->setIdea(0, "eat some fiish!");
	u->setIdea(1, "kill the bird");
	u->setIdea(2, "destroy the sofa");
	const Animal	*ucpy = u;

	std::cout << ucpy->getIdea(0) << std::endl;
	std::cout << ucpy->getIdea(1) << std::endl;
	std::cout << ucpy->getIdea(2) << std::endl;
	std::cout << ucpy->getIdea(3) << std::endl;
	std::cout << std::endl;

	delete u;
	Animal *array[SIZE];
	std::cout << std::endl;

	int	c = -1;
	while (++c < SIZE / 2)
		array[c] = new Dog();
	c--;
	while (++c < SIZE)
		array[c] = new Cat();
	c = -1;
	std::cout << std::endl;

	while (++c < SIZE)
		delete array[c];
	return 0;
}
