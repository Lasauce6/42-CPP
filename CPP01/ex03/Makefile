# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 17:22:47 by rbaticle          #+#    #+#              #
#    Updated: 2025/04/10 17:02:29 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = main.cpp \
	   HumanA.cpp \
	   HumanB.cpp \
	   Weapon.cpp

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
