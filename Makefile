# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 12:32:20 by mmasarov          #+#    #+#              #
#    Updated: 2024/02/08 10:36:49 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = gnl
HEADER = get_next_line.h

SOURCES = get_next_line_utils.c \
		get_next_line.c \
		main.c		

OBJECT = $(SOURCES:.c=.o)
all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECT)
		$(CC) $(CFLAGS) $(OBJECT) -o $(NAME)
		
.PHONY:	clean fclean re all

clean:
		rm -f $(OBJECT)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all