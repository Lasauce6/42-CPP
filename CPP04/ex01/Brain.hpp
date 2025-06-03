/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:12:07 by rbaticle          #+#    #+#             */
/*   Updated: 2025/06/03 16:54:40 by rbaticle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain {
public:
	Brain(void);
	Brain(const Brain &other);
	Brain	&operator=(const Brain &other);

	void		setIdea(int index, std::string idea);
	std::string	getIdea(int index);

	~Brain(void);
private:
	std::string	ideas[100];
};

#endif
