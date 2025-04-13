/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:59:07 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 20:36:21 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	void	attack(void);
	void	setWeapon(Weapon &weapon);
	~HumanB(void);
private:
	Weapon		*weapon;
	std::string	name;
};

#endif
