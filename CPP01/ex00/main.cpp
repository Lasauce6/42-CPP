/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:35:13 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 17:43:50 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	z1 = Zombie("Didier");
	randomChump("Michel");
	Zombie	*z2 = newZombie("Hugues");
	z1.announce();
	if (z2) {
		z2->announce();
		delete(z2);
	}
}
