# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 13:20:50 by rbaticle          #+#    #+#              #
#    Updated: 2025/04/04 17:59:29 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp \
	   Contact.cpp \
	   Phonebook.cpp

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -fr $(NAME)

fclean: clean

re: fclean all

