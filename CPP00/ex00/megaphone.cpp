/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 10:36:24 by rbaticle          #+#    #+#             */
/*   Updated: 2025/03/28 13:19:04 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		int	i = 0;
		while (++i < argc)
		{
			for (size_t j = 0; j < strlen(argv[i]); j++)
				std::cout << (char) toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
}

