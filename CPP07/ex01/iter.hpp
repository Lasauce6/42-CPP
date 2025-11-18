/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:42:32 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/18 13:24:48 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

// template<typename T>
// void iter(T *array, const size_t length, void (* func)(T&)) {
// 	if (array) {
// 		for (size_t i = 0; i < length; i++) {
// 			func(array[i]);
// 		}
// 	}
// }

template<typename T>
void iter(T *array, const size_t length, void (* func)(T&)) {
	std::cout << "CONST\n";
	if (array) {
		for (size_t i = 0; i < length; i++) {
			func(array[i]);
		} 
	}
}

template<typename T>
void	print_e(T &elem) {
	std::cout << elem << "\t";
}

template<typename T>
void	print_e_const(const T &elem) {
	std::cout << elem << "\t";
}
