##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c	\
		src/init_struct.c	\
		src/matchstick.c	\
		src/my_atoi.c	\
		src/get_next_line.c	\
		src/player.c	\
		src/ia.c	\
		src/annex_ia.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-W -Wall

CPPFLAGS	=	-I include/

LIB	=	-L ./ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

tests_run:
	make tests_run -C lib/

clean:
	make clean -C lib/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
