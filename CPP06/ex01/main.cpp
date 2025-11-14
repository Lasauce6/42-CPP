/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:38:54 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/12 12:25:06 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data	*t = new Data;

	t->val = 42;

	uintptr_t	ptr = Serializer::serialize(t);
	Data	*t2 = Serializer::deserialize(ptr);
	if (t == t2)
		std::cout << "EQUAL :)\n";
	else
		std::cout << "NOT EQUAL :(\n";
	delete t;
}
