/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:59:07 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 20:26:08 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);
	void	attack(void);
	~HumanA(void);
private:
	Weapon		&weapon;
	std::string	name;
};

#endif
