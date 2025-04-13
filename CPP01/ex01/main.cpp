/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:13 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 17:57:44 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1 = Zombie("Didier");
	z1.announce();

	Zombie	*horde = zombieHorde(5, "Michel");
	for (int i = 0; i < 5; i++) {
		horde[i].announce();
	}
	delete [] horde;
}
