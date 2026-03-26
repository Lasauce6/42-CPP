/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:50:45 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/26 11:14:57 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>

PmergeMe::PmergeMe(void) {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void) other; }
PmergeMe	&PmergeMe::operator=(const PmergeMe &other) {
	(void) other;
	return *this;
}

long	PmergeMe::jacobsthal(long n) {
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

void	PmergeMe::sort_vector(std::vector<int> &vector) {
	merge_insertion_sort(vector, 1);
}

void	PmergeMe::sort_deque(std::deque<int> &deque) {
	merge_insertion_sort(deque, 1);
}

PmergeMe::~PmergeMe(void) {}
