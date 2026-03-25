/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 11:02:04 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/25 12:40:23 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

static std::string	check_number(std::string nb) {
	if (nb[0] == '-')
		return "Negative number";
	long n = strtol(nb.c_str(), NULL, 10);
	if (n == 0 && nb != "0")
		return "Incorrect number";
	if (n > INT_MAX || errno == ERANGE)
		return "Number too big";
	return "";
}

static std::string	check_args(int argc, char **argv) {
	if (argc == 1)
		return "usage ./PmergeMe <number1> <number2> ...";
	for (int i = 1; i < argc; i++) {
		std::string	status = check_number(argv[i]);
		if (status != "")
			return status;
	}
	return "";
}

static std::vector<int>	argv_to_vector(int argc, char **argv) {
	std::vector<int>	vector;
	vector.reserve(argc - 1);
	for (int i = 1; i < argc; i++) {
		vector.push_back(atoi(argv[i]));
	}
	return vector;
}

static std::deque<int>	argv_to_deque(int argc, char **argv) {
	std::deque<int>	deque;
	for (int i = 1; i < argc; i++) {
		deque.push_back(atoi(argv[i]));
	}
	return deque;
}

template <typename C>
static bool	is_sorted(const C &container) {
	if (container.size() == 0 || container.size() == 1)
		return true;
	typename C::const_iterator	end = container.end();
	std::advance(end, -1);
	for (typename C::const_iterator it = container.begin(); it != end; it++) {
		typename C::const_iterator	next = it;
		std::advance(next, 1);
		if (*it > *next)
			return false;
	}
	return true;
}

static std::string	argv_to_str(int argc, char **argv) {
	std::string	res("");
	res.reserve(argc + 1);
	res += "[";
	res += argv[1];
	for (int i = 2; argv[i]; i++) {
		res += " ";
		res += argv[i];
	}
	res += "]";
	return res;
}

static std::string	vector_to_str(std::vector<int> &vector) {
	std::stringstream	ss;
	ss << "[" << vector[0];
	for (size_t i = 1; i < vector.size(); i++)
		ss << " " << vector[i];
	ss << "]";
	return ss.str();
}

int	main(int argc, char **argv) {
	PmergeMe	merge;

	std::string	status = check_args(argc, argv);
	if (status != "") {
		std::cerr << "Error: " << status << "\n";
		return 1;
	}

	clock_t	start_vector = clock();
	std::vector<int>	vector = argv_to_vector(argc, argv);
	merge.sort_vector(vector);
	clock_t	end_vector = clock();
	double	time_vector = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC;

	clock_t	start_deque = clock();
	std::deque<int>	deque = argv_to_deque(argc, argv);
	merge.sort_deque(deque);
	clock_t	end_deque = clock();
	double	time_deque = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;
	if (!is_sorted(vector) || !is_sorted(deque)) {
		std::cerr << "Error: Vector or deque not sorted\n";
		return 1;
	}

	std::cout << "BEFORE: " << argv_to_str(argc, argv) << "\n";
	std::cout << "AFTER: " << vector_to_str(vector) << "\n";
	std::cout << "Time to sort " << vector.size() << " elements of an std::vector \t" << std::fixed << std::setprecision(6) << time_vector << "s\n";
	std::cout << "Time to sort " << deque.size() << " elements of an std::deque \t" << std::fixed << std::setprecision(6) << time_deque << "s\n";

	return 0;
}
