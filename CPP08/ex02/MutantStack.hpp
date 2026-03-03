/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:34:24 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/03 14:40:38 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template< typename Type, typename Container=std::deque<Type> >
class MutantStack : public std::stack<Type, Container> {
public:
	MutantStack(void) {};

	typedef typename std::stack<Type, Container>::container_type::iterator	iterator;

	iterator	begin() {
		return this->c.begin();
	};

	iterator	end() {
		return this->c.end();
	}

	~MutantStack(void) {};
};
