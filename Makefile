##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC      =		gcc

RM      =		rm -f

NAME    =		setting_up

FLAGS	=		-Wall -Wextra -Werror

SRC		=		src/setting_up.c		\
				src/solve_map.c			\
				src/generate_map.c 		\
				src/mini_printf.c		\
				src/my_strlen.c 		\
				src/my_getnbr.c 		\
				src/check_error.c 		\

OBJ		=     	$(SRC:.c=.o)

all:        $(NAME)

$(NAME):	$(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) *~
		$(RM) *.out
		$(RM) *.#
		$(RM) *.gnda
		$(RM) *.gndo

fclean:	clean
		$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
