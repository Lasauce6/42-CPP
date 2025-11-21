/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:01:40 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/21 15:28:29 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include <algorithm>

template<typename T>
typename T::value_type	*easyfind(T container, int to_find) {
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end())
		return (&(*it));
	return (NULL);
}
