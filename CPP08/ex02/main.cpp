/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:34:27 by rbaticle          #+#    #+#             */
/*   Updated: 2026/03/03 14:48:06 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n---------TESTS FOR STD::LIST---------\n";

	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();
	++lit;
	--lit;
	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << "\n---------TESTS WITH ANOTHER TYPE---------\n";
	MutantStack< std::string, std::vector<std::string> > st;
	st.push("A");
	st.push("B");
	std::cout << st.top() << std::endl;
	st.pop();
	std::cout << st.size() << std::endl;
	st.push("C");
	st.push("D");
	st.push("Bonjour");
	st.push("Hello");
	MutantStack< std::string, std::vector<std::string> >::iterator sit = st.begin();
	MutantStack< std::string, std::vector<std::string> >::iterator site = st.end();
	while (sit != site) {
		std::cout << *sit << std::endl;
		++sit;
	}
	std::stack< std::string, std::vector<std::string> > sts(st);
	return 0;
}
