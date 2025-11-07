# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbaticle <rbaticle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 15:16:11 by rbaticle          #+#    #+#              #
#    Updated: 2025/11/06 12:52:00 by rbaticle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRCS = ScalarConverter.cpp \
	   ConvertUtils.cpp \
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

re: fclean
	@make all --no-print-directory
