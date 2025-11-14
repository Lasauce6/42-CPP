/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:44:21 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/12 12:25:49 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

struct Data {
	int	val;
};

class Serializer {
public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);

private:
	Serializer(void);
	Serializer(const Serializer &other);
	Serializer	&operator=(const Serializer &other);

	~Serializer(void);
};
