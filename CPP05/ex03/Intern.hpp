/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:15:32 by rbaticle          #+#    #+#             */
/*   Updated: 2025/11/03 14:20:31 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern {
public:
	Intern(void);
	Intern(const Intern &other);
	Intern	&operator=(const Intern &other);

	AForm	*makeForm(std::string const name, std::string const target);

	~Intern(void);
};

