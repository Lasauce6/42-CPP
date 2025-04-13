/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:09:31 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/08 12:04:33 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Error usage ./replace <filename> s1 s2" << std::endl;
		return (1);
	}
	std::size_t		i;
	std::ifstream	file;
	std::ofstream	fout;
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::string		str = std::string();
	std::string		res = std::string();

	filename = filename + ".replace";

	file.open(argv[1]);
	if (!file.good()) {
		std::cout << "Error reading file " << filename << std::endl;
		return (1);
	}

	fout.open(filename.c_str());
	if (!file.good()) {
		std::cout << "Error creating file" << std::endl;
		file.close();
		return (1);
	}

	while (true)
	{
		if (!file.good()) break;
		if (!getline(file, str)) break;
	
		i = str.find(s1);
		while (i != std::string::npos && s1 != "") {
			res = res + std::string(str, 0, i) + s2;
			str = std::string(str, i + s1.length(), std::string::npos);
			i = str.find(s1);
		}
		res = res + str;
		fout << res << std::endl;
		res = std::string();
	}

	file.close();
	fout.close();
	return (0);
}
