/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:59:47 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/21 14:06:35 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#define MAX_VAL 750

// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}
//
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
//
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }

int	main(void) {
	Array<int> numbers(10);
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		const int value = rand() % 101;
		numbers[i] = value;
	}

	Array<int> cpy = numbers;

	std::cout << cpy[4] << " " << numbers[4] << "\n";
	cpy[4] = 42;
	std::cout << cpy[4] << " " << numbers[4] << "\n";

	cpy = numbers;
	std::cout << cpy[4] << " " << numbers[4] << "\n";

	try {
		cpy[50] = 0;
	} catch (std::exception &e) {
		std::cerr << "error: " << e.what() << "\n";
	}

	Array<char> chars(10);
	chars[0] = 'a';

	std::cout << chars[0] << "\n";
}

