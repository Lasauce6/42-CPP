/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:23:42 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/07 17:52:57 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>

class Zombie {
	public:
		Zombie(void);
		Zombie(std::string name);
		void	announce(void);
		void	set_name(std::string name);
		~Zombie(void);
	private:
		std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
