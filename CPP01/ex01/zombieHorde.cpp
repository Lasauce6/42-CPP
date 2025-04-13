/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:45:39 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 17:52:43 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie	*zombieHorde(int N, std::string name) {
	if (N <= 0 || N > 2147483647) {
		std::cout << "Invalid value" << std::endl;
		return (NULL);
	}
	Zombie	*horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].set_name(name);
	}
	return (horde);
}
