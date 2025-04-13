/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:06:26 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/10 16:19:11 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage ./harlFilter <Level>" << std::endl;
		return (1);
	}
	Harl	h = Harl();

	h.complain(argv[1]);
}
