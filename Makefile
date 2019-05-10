##
## EPITECH PROJECT, 2018
## My_runner
## File description:
## My_runner's makefile
##

SRCDIR  =       src

INCDIR =	include

SRC     =	$(SRCDIR)/minishell.c \
		$(SRCDIR)/simple_functions.c \
		$(SRCDIR)/sentence_to_word.c \
		$(SRCDIR)/path_handling.c \
		$(SRCDIR)/split_path.c \
		$(SRCDIR)/str_to_word_array.c \
		$(SRCDIR)/added_builtins.c \

OBJ     =       $(SRC:.c=.o)

NAME    =       mysh

CFLAGS  =       -W -Wall -Wextra -I include/

all:            $(NAME)

$(NAME):	$(OBJ)
		gcc $(SRC) -g3 -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re

