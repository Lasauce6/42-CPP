/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:07:11 by rbaticle          #+#    #+#             */
/*   Updated: 2025/04/08 12:09:57 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>
# include <iostream>

class Harl {
public:
	Harl(void);
	void	complain(std::string level);
	~Harl(void);
private:
	void	debug(void);
	void	infos(void);
	void	warning(void);
	void	error(void);
};

#endif
