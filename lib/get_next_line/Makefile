##
## Makefile for Makefile in /home/amaury/CPool_Day10/lib/my
## 
## Made by Amaury Bernard
## Login   <amaury.bernard@epitech.eu>
## 
## Started on  Fri Oct 14 12:08:12 2016 Amaury Bernard
## Last update Wed Jan 18 14:49:39 2017 Amaury Bernard
##

CFLAGS	+=	-Wextra -Wall -Werror

SRC	=	get_next_line.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	libget_next_line.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ..

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
