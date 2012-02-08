##
## Makefile for  in /u/all/hervet_g/public/morpion
## 
## Made by tracy nelcha
## Login   <nelcha_t@epitech.net>
## 
## Started on  Wed May 25 19:21:16 2011 tracy nelcha
## Last update Wed May 25 22:50:11 2011 tracy nelcha
##

NAME	=	my_morpion

CC	=	gcc

RM	=	rm -f

SRC	=	get_name.c	\
		main.c		\
		my_strlen.c	\
		my_putstr.c	\
		my_putchar.c	\
		my_strcmp.c	\
		my_strncpy.c	\
		init_grid.c	\
		aff_grid.c	\
		play_ai.c	\
		play.c		\
		possible_win.c	\
		aff_win.c	\
		is_win.c	\
		play_player.c

SRCS	=	$(addprefix src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS	+=	-Wall -Wextra -I./inc

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	re fclean all clean
