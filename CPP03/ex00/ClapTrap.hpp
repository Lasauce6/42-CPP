/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:36:37 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/16 11:52:09 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap	&operator=(const ClapTrap &other);

	void			attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	void			showStatus(void);
	void			setAttackDmg(unsigned int amount);
	std::string		getName(void);
	unsigned int	getAttackDmg(void);

	~ClapTrap(void);
private:
	std::string		name;
	unsigned int	hit_pt;
	unsigned int	energy_pt;
	unsigned int	attack_dmg;
};

#endif
