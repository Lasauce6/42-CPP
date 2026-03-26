/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:35:54 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/26 12:17:22 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iterator>
#include <vector>
#include <deque>

template<typename C>
bool	comp(C a, C b) {
	return *a < *b;
}

class PmergeMe {
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	PmergeMe	&operator=(const PmergeMe &other);

	void	sort_vector(std::vector<int> &vector);
	void	sort_deque(std::deque<int> &deque);

	~PmergeMe(void);

private:
	long	jacobsthal(long n);

	template<typename C>
	C	next(C it, int steps) {
		std::advance(it, steps);
		return it;
	}

	template<typename T, template<typename, typename> class C>
	void	merge_insertion_sort(C< T, std::allocator<T> > &container, int pair_level) {
		typedef typename C< T, std::allocator<T> >::iterator	Iterator;

		int	nb_pairs = container.size() / pair_level;
		if (nb_pairs < 2)
			return;

		// Ignore odd pair while swapping
		bool	is_odd = nb_pairs % 2 == 1;

		Iterator	start = container.begin();
		Iterator	last = next(container.begin(), pair_level * (nb_pairs));
		Iterator	end = next(last, -(is_odd * pair_level));

		// Swap pairs by the biggest pair number
		// Recursion after swap
		int	jump = 2 * pair_level;
		for (Iterator it = start; it != end; std::advance(it, jump)) {
			Iterator	this_pair = next(it, pair_level - 1);
			Iterator	next_pair = next(it, pair_level * 2 - 1);
			if (comp(next_pair, this_pair)) 
				swap_pair(this_pair, pair_level);
		}
		merge_insertion_sort(container, pair_level * 2);

		// Divide pairs into main and pend
		// Main with sorted sequence
		// Pend with yet to be sorted
		C< Iterator, std::allocator<Iterator> >	main;
		C< Iterator, std::allocator<Iterator> >	pend;

		// Init the main with {b1, a1}
		main.push_back(next(container.begin(), pair_level - 1));
		main.push_back(next(container.begin(), pair_level * 2 - 1));

		// Insert the rest of a into main and the rest of b into pend
		for (int i = 4; i <= nb_pairs; i += 2) {
			pend.push_back(next(container.begin(), pair_level * (i - 1) - 1));
			main.push_back(next(container.begin(), pair_level * i -1));
		}

		// Insert the odd element if one
		if (is_odd)
			pend.push_back(next(end, pair_level - 1));

		// Insert the pend into the main in order determined by Jacobsthal numbers
		// We insert by reverse example : 3 2 -> 5 4 -> 11 10 9 8 7 6 ...
		int	prev_jacobsthal = jacobsthal(1);
		int	inserted_numbers = 0;
		typedef typename C< Iterator, std::allocator<Iterator> >::iterator	ItContIterator;
		for (int k = 2;; k++) {
			int	curr_jacobsthal = jacobsthal(k);
			int	jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
			int	offset = 0;

			if (jacobsthal_diff > static_cast<long>(pend.size()))
				break;

			int	nbr_of_times = jacobsthal_diff;
			ItContIterator	pend_it = next(pend.begin(), jacobsthal_diff - 1);
			ItContIterator	bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers);
			int	pend_idx = jacobsthal_diff - 1;

			while (nbr_of_times) {
				ItContIterator	idx = std::upper_bound(main.begin(), bound_it, *pend_it, comp<Iterator>);
				ItContIterator	inserted = main.insert(idx, *pend_it);

				nbr_of_times--;

				pend_it = pend.erase(pend_it);
				std::advance(pend_it, -1);

				// Decrement index
				pend_idx--;

				// Offset if the inserted number is at the exact index where the bound should be to do less comparisons
				offset += (inserted - main.begin()) == curr_jacobsthal + inserted_numbers;
				bound_it = next(main.begin(), curr_jacobsthal + inserted_numbers - offset);
			}
			prev_jacobsthal = curr_jacobsthal;
			inserted_numbers += jacobsthal_diff;
			offset = 0;
		}

		// Insert remaining elements in reverse order with the less comparisons
		for (ssize_t i = pend.size() - 1; i >= 0; i--) {
			ItContIterator	curr_pend = next(pend.begin(), i);
			ItContIterator	curr_bound = next(main.begin(), main.size() - pend.size() + i + is_odd);
			ItContIterator	idx = std::upper_bound(main.begin(), curr_bound, *curr_pend, comp<Iterator>);
			main.insert(idx, *curr_pend);
		}

		// Use copy container to store all the numbers
		C< T, std::allocator<T> >	copy;
		for (ItContIterator it = main.begin(); it != main.end(); it++) {
			for (int i = 0; i < pair_level; i++) {
				Iterator	pair_start = *it;
				std::advance(pair_start, -pair_level + i + 1);
				copy.insert(copy.end(), *pair_start);
			}
		}

		// Replace values in original container
		Iterator	copy_it = copy.begin();
		Iterator	container_it = container.begin();
		while (copy_it != copy.end()) {
			*container_it = *copy_it;
			container_it++;
			copy_it++;
		}

	}

	template<typename C>
	void	swap_pair(C it, int pair_level) {
		C	start = next(it, -pair_level + 1);
		C	end = next(start, pair_level);
		while (start != end) {
			std::iter_swap(start, next(start, pair_level));
			start++;
		}
	}
};

