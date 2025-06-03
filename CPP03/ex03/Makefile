# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 11:43:54 by rbaticle          #+#    #+#              #
#    Updated: 2025/06/03 14:58:00 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -fstandalone-debug
SRCS = ClapTrap.cpp \
	   ScavTrap.cpp \
	   FragTrap.cpp \
	   DiamondTrap.cpp \
	   main.cpp

OBJS_DIR = .objs/
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

fsan:
	$(CC) $(CFLAGS) -g3 -fsanitize=address $(SRCS) -o $(NAME)

clean:
	rm -fr $(OBJS_DIR)

fclean: clean
	rm -fr $(NAME)

re: fclean all
