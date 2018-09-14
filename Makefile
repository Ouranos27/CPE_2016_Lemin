##
## Makefile for my_printf in /home/artha/printf
## 
## Made by dylan renard
## Login   <artha@epitech.net>
## 
## Started on  Mon Nov  7 15:05:57 2016 dylan renard
## Last update Sun Apr 30 23:12:47 2017 dylan renard
##

CC	= 	gcc

RM	= 	rm -f

NAME	= 	lem_in

SRCS	= 	src/main.c		\
		src/queue.c		\
		src/graph.c		\
		src/tree_utils.c	\
		src/tree.c		\
		src/parser.c		\
		src/parser_set_room.c	\
		src/parser_set_link.c	\
		src/parser_check_rooms.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	+=	-Wextra -Wall -pedantic

CFLAGS	+=	-I./include/

LDFLAGS +=	-L./lib -lmy -L./lib -lget_next_line -L./lib -lmy_printf

all: libmy libget_next_line libmy_printf $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAFS) $(LDFLAGS)

libmy:
	@$(MAKE) -s -C lib/my

libget_next_line:
	@$(MAKE) -s -C lib/get_next_line

libmy_printf:
	@$(MAKE) -s -C lib/my_printf

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -s -C lib/my
	@$(MAKE) clean -s -C lib/get_next_line
	@$(MAKE) clean -s -C lib/my_printf

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -s -C lib/my
	@$(MAKE) fclean -s -C lib/get_next_line
	@$(MAKE) fclean -s -C lib/my_printf

re: fclean all

.PHONY: clean re all fclean
