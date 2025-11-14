/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:26:53 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/14 15:50:09 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

Base::Base(void) : _type("Base") {}

void	Base::showType(void) {
	std::cout << "type: " << _type << "\n";
}

Base::~Base(void) {}
