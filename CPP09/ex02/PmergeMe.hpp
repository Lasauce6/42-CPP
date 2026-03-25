/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:35:54 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/25 14:55:16 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
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

	template<typename C>
	void	merge_insertion_sort(C &container, int pair_level) {
		typedef typename C::iterator	Iterator;

		int	pair_units_nbr = container.size() / pair_level;
		if (pair_units_nbr < 2)
			return;

		// Ignore odd pair while swapping
		bool	is_odd = pair_units_nbr % 2 == 1;

		Iterator	start = container.begin();
		Iterator	last = next(container.begin(), pair_level * (pair_units_nbr));
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
		Iterator	*main_arr = new Iterator[container.size()];
		Iterator	*pend_arr = new Iterator[container.size()];
		int	main_size = 0;
		int	pend_size = 0;

		// Init the main with {b1, a1}
		main_arr[main_size++] = next(container.begin(), pair_level - 1);
		main_arr[main_size++] =  next(container.begin(), pair_level * 2 - 1);

		// Insert the rest of a into main and the rest of b into pend
		for (int i = 4; i <= pair_units_nbr; i += 2) {
			pend_arr[pend_size++] = next(container.begin(), pair_level * (i - 1) - 1);
			main_arr[main_size++] = next(container.begin(), pair_level * i - 1);
		}

		// Insert the odd element if one
		if (is_odd)
			pend_arr[pend_size++] = next(end, pair_level - 1);

		// Insert the pend into the main in order determined by Jacobsthal numbers
		// We insert by reverse example : 3 2 -> 5 4 -> 11 10 9 8 7 6 ...
		int	prev_jacobsthal = jacobsthal(1);
		int	inserted_numbers = 0;
		for (int k = 2;; k++) {
			int	curr_jacobsthal = jacobsthal(k);
			int	jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;
			int	offset = 0;

			if (jacobsthal_diff > pend_size)
				break;

			int	nbr_of_times =jacobsthal_diff;

			int	pend_idx = jacobsthal_diff - 1;

			while (nbr_of_times) {
				Iterator	val_to_insert = pend_arr[pend_idx];

				int	bound_idx = curr_jacobsthal + inserted_numbers;

				Iterator	*idx_ptr = std::upper_bound(main_arr, main_arr + bound_idx, val_to_insert, comp<Iterator>);
				int	insert_pos = idx_ptr - main_arr;

				// Insert (shift right)
				for (int i = main_size; i > insert_pos; i--)
					main_arr[i] = main_arr[i - 1];
				main_size++;
				main_arr[insert_pos] = val_to_insert;

				nbr_of_times--;

				// Delete in pend_arr (shift left)
				for (int i = pend_idx; i < pend_size - 1; i++)
					pend_arr[i] = pend_arr[i + 1];
				pend_size--;

				// Decrement index
				pend_idx--;

				// Offset if the inserted number is at the exact index where the bound should be to do less comparisons
				if (insert_pos == bound_idx)
					offset++;
				bound_idx = curr_jacobsthal + inserted_numbers - offset;
			}
			prev_jacobsthal = curr_jacobsthal;
			inserted_numbers += jacobsthal_diff;
			offset = 0;
		}

		// Insert remaining elements in reverse order with the less comparisons
		for (ssize_t i = pend_size - 1; i >= 0; i--) {
			Iterator curr_val = pend_arr[i];
			int bound_idx = main_size;

			Iterator* idx_ptr = std::upper_bound(main_arr, main_arr + bound_idx, curr_val, comp<Iterator>);
			int insert_pos = idx_ptr - main_arr;

			for (int j = main_size; j > insert_pos; j--)
				main_arr[j] = main_arr[j - 1];
			main_size++;
			main_arr[insert_pos] = curr_val;
		}

		// Use copy array to store all the numbers
		int* copy_arr = new int[container.size()];
		int copy_idx = 0;

		for (int i = 0; i < main_size; i++) {
			Iterator pair_start = main_arr[i];
			std::advance(pair_start, -pair_level + 1);
			for (int j = 0; j < pair_level; j++) {
				copy_arr[copy_idx++] = *pair_start;
				pair_start++;
			}
		}

		// Replace values in original container
		Iterator container_it = container.begin();
		for (int i = 0; i < copy_idx; i++) {
			*container_it = copy_arr[i];
			container_it++;
		}

		delete[] main_arr;
		delete[] pend_arr;
		delete[] copy_arr;
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

