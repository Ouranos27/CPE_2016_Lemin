##
## Makefile for Makefile in /home/amaury/CPool_Day10/lib/my
## 
## Made by Amaury Bernard
## Login   <amaury.bernard@epitech.eu>
## 
## Started on  Fri Oct 14 12:08:12 2016 Amaury Bernard
## Last update Thu Feb  2 14:52:33 2017 Amaury Bernard
##

CFLAGS	+=	-Wextra -Wall -Werror

SRC	=	my_printf.c		\
		my_putchar.c		\
		my_strlen.c		\
		my_putstr.c		\
		my_putstr_err.c		\
		my_put_hex.c		\
		my_put_adr.c		\
		my_dec_put_in_bin.c	\
		my_dec_put_in_oct.c	\
		my_putstr_all.c		\
		my_put_nbr.c		\
		flags.c			\
		flags_2.c		\
		flags_3.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	libmy_printf.a

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
