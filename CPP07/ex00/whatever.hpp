/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 09:32:30 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/17 09:40:14 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void	swap(T &a, T &b) {
	T	t = a;
	a = b;
	b = t;
}

template<typename T>
T	min(T a, T b) {
	if (a < b)
		return a;
	return b;
}

template<typename T>
T	max(T a, T b) {
	if (a > b)
		return a;
	return b;
}
