CC = cc
CFLAGS = -g -Wall -Wextra -Werror
NAME = getnextline.a
HEADER = get_next_line.h

SOURCES = get_next_line_utils.c \
		get_next_line.c \

OBJECT = $(SOURCES:.c=.o)
all: $(NAME)

$(NAME): $(OBJECT)
		ar rcs $@ $(OBJECT)

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re all

clean:
		rm -rf $(OBJECT)

fclean:		clean
		rm -rf $(NAME)

re: fclean $(NAME)