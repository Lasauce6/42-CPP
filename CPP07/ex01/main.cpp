/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:42:19 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/21 11:58:56 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void) {
	int		list[] = {1, 2, 3, 4, 5};
	iter(list, 5, &print_e<int>);
	std::cout << "\n";

	char	listc[] = {'a', 'b', 'c', 'd', 'e'};
	iter(listc, 5, &print_e_const<char>);
	std::cout << "\n";
}
