/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 12:08:57 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/15 18:55:07 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter {
public:
	Character(const std::string name);
	Character(const Character &other);
	Character			&operator=(const Character &other);

	const std::string	&getName(void) const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

	~Character(void);
private:
	AMateria	*inventory[4];
	std::string	name;
};

#endif
