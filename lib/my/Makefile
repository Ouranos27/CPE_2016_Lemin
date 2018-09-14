##
## Makefile for Makefile in /home/Artha77/CPool_Day10/lib/my
##
## Made by dylan renard
## Login   <Artha77@epitech.net>
##
## Started on  Mon Oct 17 20:22:43 2016 dylan renard
## Last update Sat Apr 29 14:17:59 2017 dylan renard
##

CC	=	gcc -g

AR	=	ar rc

CFLAGS	=	-I./include

NAME	=	libmy.a

RM	=	rm -f

SRCS	=	list.c	\
		list_util.c	\
		list_uitl2.c	\
		is_bt.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		int_overflow.c	\
		my_power_it.c	\
		my_atoi.c	\
		my_putstr.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_strndup.c	\
		my_strcat.c	\
		my_strncmp.c	\
		xmalloc.c	\
		my_str_to_wordtab.c	\
		tab_to_space.c	\
		my_strncpy.c	\
		my_putchar_fd.c	\
		my_putchar_name.c	\
		to_string.c	\
		my_putstr_fd.c	\
		my_putstr_name.c	\
		my_putstr_name_end.c	\
		my_puts.c	\
		my_puts_fd.c	\
		my_puts_name.c	\
		my_puts_name_end.c	\
		xopen.c		\
		xread.c		\
		my_str_isnum.c	\
		my_strlen.c	\
		my_puterr.c 	\
		my_strcmp.c

OBJS	=	$(SRCS:.c=.o)

CPLIB	=	cp $(NAME) ../ && cp include/my.h ../../include/  && cp include/list.h ../../include/

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(CPLIB)

$(OBJS):
	$(CC) -c $(SRCS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
