/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:56:21 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 20:23:36 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon {
	public:
		Weapon(std::string type);
		std::string	getType(void) const;
		void		setType(std::string type);
		~Weapon(void);
	private:
		std::string	type;
};

#endif
