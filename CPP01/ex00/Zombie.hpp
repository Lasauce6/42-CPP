/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:23:42 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 17:40:12 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie {
	public:
		Zombie(std::string name);
		void	announce(void);
		~Zombie(void);
	private:
		std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
