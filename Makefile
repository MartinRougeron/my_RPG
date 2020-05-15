##
## EPITECH PROJECT, 2020
## make
## File description:
## make
##

NAME	= my_rpg

CC	= gcc

RM	= rm -f

OBJS	= $(patsubst %.c,%.o, $(wildcard ./src/*/*.c) $(wildcard ./lib/*/*.c) $(wildcard ./src/*/*/*.c))

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -Iinclude -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -Iinclude -lm -g3

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

clean_val:
	rm -f vgcore.*

.PHONY: all clean fclean re
